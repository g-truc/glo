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
	
	<xsl:param name="Spec" select="'gl'" />
	<xsl:param name="Version" select="'420'" />
	<xsl:param name="Profile" select="'limited'" />

	<xsl:template match="/">
		<xsl:param name="Guard" select="concat('__', $Spec, '_', $Version, '_', $Profile, '__')" />
		
		<xsl:text>#ifndef </xsl:text><xsl:value-of select="$Guard"/><xsl:text>&#10;</xsl:text>
		<xsl:text>#define </xsl:text><xsl:value-of select="$Guard"/><xsl:text>&#10;</xsl:text>
		<xsl:text>&#10;</xsl:text>
		<xsl:text>&#10;</xsl:text>
		<xsl:text>#endif//</xsl:text><xsl:value-of select="$Guard"/>
		<xsl:text>&#10;</xsl:text>
	</xsl:template>

</xsl:stylesheet>
