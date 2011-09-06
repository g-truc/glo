<?xml version="1.0" encoding="utf-8" ?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output
		method="text"
		version="1.0"
		encoding="utf-8"
		standalone="no"
		omit-xml-declaration="yes"
		indent="no" />

  <xsl:strip-space elements="*" />

	<xsl:variable name="smallcase" select="'abcdefghijklmnopqrstuvwxyz'" />
	<xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />
	
  <!-- Constants -->
  <xsl:param name="spec-gl" select="'gl'" />
  <xsl:param name="spec-es" select="'es'" />
  <xsl:param name="spec-sc" select="'sc'" />
  <xsl:param name="profile-core" select="'core'" />
  <xsl:param name="profile-comp" select="'compatiblity'" />
  <xsl:param name="profile-limited" select="'limited'" />

  <!-- Processing parameters -->
  <xsl:param name="Spec" select="$spec-gl" />
  <xsl:param name="Version" select="'200'" />
  <xsl:param name="Profile" select="$profile-comp" />

  <xsl:template match="version">
	  <xsl:variable name="Namespace" select="translate(/lang/spec[@name=$Spec]/@spec-ns, $smallcase, $uppercase)" />
    <xsl:value-of select="concat('#define ', $Namespace, '_VERSION_', ./@major, '_', ./@minor, ' ', '1', '&#10;')"/>
  </xsl:template>
  
  <xsl:template match="spec">
    <xsl:param name="Name" select="./@name" />
	      
    <xsl:choose>
      <xsl:when test="$Profile=$profile-limited">
        <xsl:apply-templates select="./version[@name=$Version]" />
      </xsl:when>
      <xsl:when test="$Profile=$profile-core">
        <xsl:apply-templates select="./version[@core='yes'][$Version>=@name]" />
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates select="./version[$Version>=@name]" />
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="type">
    <xsl:param name="Name" select="./@name" />
	  <xsl:variable name="Namespace" select="translate(../spec[@name=$Spec]/@api-ns, $smallcase, $uppercase)" />

    <xsl:choose>
      <xsl:when test="$Profile='limited'">
        <xsl:variable name="Used" select="/lang/command/param[@type=$Name]" />
        <xsl:variable name="Validity" select="$Used/../spec[@name=$Spec]" />

        <xsl:if test="$Used and (($Validity/@limited='no') or (not($Validity/@limited)) or ($Validity/@limited > $Version))">
          <xsl:value-of select="concat('typedef ', ./@value, ' ', $Namespace, ./@name, ';', '&#10;')"/>
        </xsl:if>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="concat('typedef ', ./@value, ' ', $Namespace, ./@name, ';', '&#10;')"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
  
  <xsl:template match="token">
    <xsl:param name="Name" select="./@name" />
	  <xsl:variable name="Namespace" select="translate(../spec[@name=$Spec]/@api-ns, $smallcase, $uppercase)" />
    
    <xsl:choose>
      <!-- Limited profile -->
      <xsl:when test="$Profile='limited'">
        <xsl:variable name="Used" select="/lang/command/param/arg[@name=$Name]" />
        
        <xsl:if test="$Used and ($Used/@limited='no' or $Used/@limited>$Version)">
          <xsl:value-of select="concat('#define ', $Namespace, '_', ./@name, ' ', ./@value, '&#10;')"/>
        </xsl:if>
      </xsl:when>
      <!-- Core profile -->
      <xsl:when test="$Profile='core'">
        <xsl:variable name="Used" select="/lang/command/param/arg[@name=$Name]" />

        <xsl:if test="$Used and ($Used/@removed='no' or $Used/@removed>$Version)">
          <xsl:value-of select="concat('#define ', $Namespace, '_', ./@name, ' ', ./@value, '&#10;')"/>
        </xsl:if>
      </xsl:when>
      <!-- Compatiblity profile -->
      <xsl:otherwise>
        <xsl:value-of select="concat('#define ', $Namespace, '_', ./@name, ' ', ./@value, '&#10;')"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

	<xsl:template name="header_guard">
		<xsl:variable name="Namespace" select="translate(/lang/spec[@name=$Spec]/@spec-ns, $uppercase, $smallcase)" />
		<xsl:variable name="ProfileLimited" select="/lang/spec[@name=$Spec]/version[$Version=./@name]/@limited" />
		<xsl:variable name="ProfileCore" select="/lang/spec[@name=$Spec]/version[$Version=./@name]/@core" />
		<xsl:variable name="ProfileComp" select="/lang/spec[@name=$Spec]/version[$Version=./@name]/@compatiblity" />

		<xsl:value-of select="concat('__', $Namespace, '_', $Version)" />
		<xsl:if test="($ProfileLimited='yes') or ($ProfileCore='yes') or ($ProfileComp='yes')">
			<xsl:value-of select="concat('_', $Profile)" />
		</xsl:if>
		<xsl:value-of select="'__'" />
	</xsl:template>
	
  <xsl:template match="lang">
	  <xsl:variable name="Namespace" select="translate(./spec[@name=$Spec]/@spec-ns, $uppercase, $smallcase)" />
	  <!--
	  <xsl:value-of select="concat('#ifndef __', translate(/lang/spec[@name=$Spec]/@spec-ns, $uppercase, $smallcase), '_h_&#10;')" />
	  <xsl:value-of select="'#error: An OpenGL header is already included&#10;'" />
	  <xsl:value-of select="concat('#endif//__', translate(/lang/spec[@name=$Spec]/@spec-ns, $uppercase, $smallcase), '_h_&#10;')" />
	  <xsl:value-of select="'&#10;'" />
	  -->
	  
	  <xsl:value-of select="'#ifndef '" />
	  <xsl:call-template name="header_guard" />
	  <xsl:value-of select="'&#10;'" />
	  <xsl:value-of select="'#define '" />
	  <xsl:call-template name="header_guard" />
	  <xsl:value-of select="'&#10;'" />

    <xsl:text>&#10;</xsl:text>
    
    <!-- Versions -->
    <xsl:value-of select="concat('// Declare supported versions of ', ./spec[./@name=$Spec]/@label, ' specification &#10;')" />
    <xsl:apply-templates select="./spec[@name=$Spec]" />
    <xsl:text>&#10;</xsl:text>

    <!-- Extensions -->
    <xsl:value-of select="concat('// Declare supported ', ./spec[./@name=$Spec]/@label, ' extensions &#10;')" />
    <xsl:text>&#10;</xsl:text>
    
    <!-- Types -->
    <xsl:value-of select="concat('// Declare types of ', ./spec[./@name=$Spec]/@label, ' specification &#10;')" />
    <xsl:apply-templates select="./type/spec[@name=$Spec][$Version>=./@version]/.." />
    <xsl:text>&#10;</xsl:text>
    
    <!-- Tokens -->
    <xsl:value-of select="concat('// Define tokens of ', ./spec[./@name=$Spec]/@label, ' specification &#10;')" />
    <xsl:apply-templates select="./token[$Version>=./@version]" />
    <xsl:text>&#10;</xsl:text>
    
    <!-- Commands -->
    <xsl:value-of select="concat('// Declare commands of ', ./spec[./@name=$Spec]/@label, ' specification &#10;')" />
    <xsl:text>&#10;</xsl:text>

	  <xsl:value-of select="'#endif//'" />
	  <xsl:call-template name="header_guard" />
	  <xsl:value-of select="'&#10;'" />
  </xsl:template>

  <xsl:template match="/">
    <xsl:variable name="SelectedSpec" select="./lang/spec[@name=$Spec]" />
    
    <xsl:choose>
      <!-- Check valid specification -->
      <xsl:when test="$Spec and $SelectedSpec">
        <xsl:variable name="SelectedVersion" select="$SelectedSpec/version[@name=$Version]" />
        
        <xsl:choose>
          <!-- Check valid version for OpenGL only -->
			<!--xsl:when test="$SelectedVersion">
            <xsl:choose>
              <xsl:when test="($SelectedVersion/@compatiblity='yes') and ($Profile=$profile-comp)">
                <xsl:apply-templates select="./lang" />
              </xsl:when>
              <xsl:when test="($SelectedVersion/@core='yes') and ($Profile=$profile-core)">
                <xsl:apply-templates select="./lang" />
              </xsl:when>
              <xsl:when test="($SelectedVersion/@limited='yes') and ($Profile=$profile-limited)">
                <xsl:apply-templates select="./lang" />
              </xsl:when>
              <xsl:when test="($Profile=$profile-comp) or ($Profile=$profile-core) or ($Profile=$profile-limited)">
                <xsl:value-of select="concat('ERROR: Unsupported profile for ', $SelectedSpec/@label, ' ', $SelectedVersion/@major, '.', $SelectedVersion/@minor, ' specification...: ', $Profile, '&#10;')" />
              </xsl:when>
              <xsl:otherwise>
                <xsl:value-of select="concat('ERROR: Unknown profile of ', $SelectedSpec/@label, ' specification...: ', $Profile, '&#10;')" />
              </xsl:otherwise>
            </xsl:choose>
          </xsl:when-->
          <!-- Check valid version for OpenGL ES and OpenGL SC -->
          <xsl:when test="$SelectedVersion">
            <xsl:apply-templates select="./lang" />
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="concat('ERROR: Unknown version of ', $SelectedSpec/@label, ' specification...: ', $Version, '&#10;')" />
            <!-- TODO: Added list of the supported version -->
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="concat('ERROR: Unknown specification...: ', $Spec, '&#10;')" />
        <!-- TODO: Added list of the supported specification -->
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

</xsl:stylesheet>
