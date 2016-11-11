#pragma once

#ifdef _WIN32
#pragma comment(linker, "/subsystem:windows")
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif

#include <iostream>
#include <chrono>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <string>
#include <array>

#include "vulkan/vulkan.h"

#include "keycodes.hpp"
#include "tools.hpp"
#include "debug.hpp"

//#include "device.hpp"
#include "swapchain.hpp"
#include "texture.hpp"
#include "camera.hpp"

typedef VkPhysicalDeviceFeatures (*PFN_GetEnabledFeatures)();

class gl_base
{
private:
	bool enableValidation = false;
	bool enableVSync = false;
	VkPhysicalDeviceFeatures enabledFeatures = {};
	float fpsTimer = 0.0f;
	VkResult createInstance(bool enableValidation);
	std::string getWindowTitle();
	bool viewUpdated = false;
	uint32_t destWidth;
	uint32_t destHeight;
	void windowResize();

protected:
	float frameTimer = 1.0f;
	uint32_t frameCounter = 0;
	uint32_t lastFPS = 0;
	VkInstance instance;
	VkPhysicalDevice physicalDevice;
	VkPhysicalDeviceProperties deviceProperties;
	VkPhysicalDeviceFeatures deviceFeatures;
	VkPhysicalDeviceMemoryProperties deviceMemoryProperties;
	VkDevice device;
	vk::VulkanDevice *vulkanDevice;
	VkQueue queue;
	VkFormat colorformat = VK_FORMAT_B8G8R8A8_UNORM;
	VkFormat depthFormat;
	VkCommandPool cmdPool;
	VkCommandBuffer setupCmdBuffer = VK_NULL_HANDLE;
	VkPipelineStageFlags submitPipelineStages = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	VkSubmitInfo submitInfo;
	VkRenderPass renderPass;
	std::vector<VkFramebuffer>frameBuffers;
	uint32_t currentBuffer = 0;
	VkDescriptorPool descriptorPool = VK_NULL_HANDLE;
	std::vector<VkShaderModule> shaderModules;
	VkPipelineCache pipelineCache;
	VulkanSwapChain swapChain;

	struct {
		VkSemaphore presentComplete;
		VkSemaphore renderComplete;
		VkSemaphore textOverlayComplete;
	} semaphores;

	vkTools::VulkanTextureLoader *textureLoader = nullptr;
	const std::string getAssetPath();
public: 
	bool prepared = false;
	uint32_t width = 1280;
	uint32_t height = 720;

	VkClearColorValue defaultClearColor = { { 0.025f, 0.025f, 0.025f, 1.0f } };

	float zoom = 0;
	float timer = 0.0f;
	float timerSpeed = 0.25f;
	bool paused = false;

	float rotationSpeed = 1.0f;
	float zoomSpeed = 1.0f;

	Camera camera;

	glm::vec3 rotation = glm::vec3();
	glm::vec3 cameraPos = glm::vec3();
	glm::vec2 mousePos;

	std::string title = "Vulkan Example";
	std::string name = "vulkanExample";

	struct 
	{
		VkImage image;
		VkDeviceMemory mem;
		VkImageView view;
	} depthStencil;

	struct
	{
		glm::vec2 axisLeft = glm::vec2(0.0f);
		glm::vec2 axisRight = glm::vec2(0.0f);
	} gamePadState;

	HWND window;
	HINSTANCE windowInstance;

	gl_base(bool enableValidation, PFN_GetEnabledFeatures enabledFeaturesFn = nullptr);
	~gl_base();

	void initVulkan(bool enableValidation);

	void setupConsole(std::string title);
	HWND setupWindow(HINSTANCE hinstance, WNDPROC wndproc);
	void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual void render() = 0;
	virtual void viewChanged();
	virtual void keyPressed(uint32_t keyCode);
	virtual void windowResized();

	void createCommandPool();
	virtual void setupDepthStencil();
	virtual void setupFrameBuffer();
	virtual void setupRenderPass();

	void initSwapchain();
	void setupSwapChain();

	bool checkCommandBuffers();
	void createSetupCommandBuffer();
	void flushSetupCommandBuffer();

	VkCommandBuffer createCommandBuffer(VkCommandBufferLevel level, bool begin);
	void flushCommandBuffer(VkCommandBuffer commandBuffer, VkQueue queue, bool free);

	void createPipelineCache();

	virtual void prepare();

	VkPipelineShaderStageCreateInfo loadShader(std::string fileName, VkShaderStageFlagBits stage);

	VkBool32 createBuffer(
		VkBufferUsageFlags usageFlags,
		VkMemoryPropertyFlags memoryPropertyFlags,
		VkDeviceSize size,
		void *data,
		VkBuffer *buffer,
		VkDeviceMemory *memory);

	VkBool32 createBuffer(
		VkBufferUsageFlags usage,
		VkDeviceSize size,
		void *data,
		VkBuffer *buffer,
		VkDeviceMemory *memory);

	VkBool32 createBuffer(
		VkBufferUsageFlags usage,
		VkDeviceSize size,
		void *data,
		VkBuffer *buffer,
		VkDeviceMemory *memory,
		VkDescriptorBufferInfo *descriptor);

	VkBool32 createBuffer(
		VkBufferUsageFlags usage,
		VkMemoryPropertyFlags memoryPropertyFlags,
		VkDeviceSize size,
		void *data,
		VkBuffer *buffer,
		VkDeviceMemory *memory,
		VkDescriptorBufferInfo *descriptor);

	void renderLoop();
	void prepareFrame();
	void submitFrame();

};

#define VULKAN_EXAMPLE_MAIN()																		\
VulkanExample *vulkanExample;																		\
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)						\
{																									\
	if (vulkanExample != NULL)																		\
	{																								\
		vulkanExample->handleMessages(hWnd, uMsg, wParam, lParam);									\
	}																								\
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));												\
}																									\
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)	\
{																									\
	vulkanExample = new VulkanExample();															\
	vulkanExample->setupWindow(hInstance, WndProc);													\
	vulkanExample->initSwapchain();																	\
	vulkanExample->prepare();																		\
	vulkanExample->renderLoop();																	\
	delete(vulkanExample);																			\
	return 0;																						\
}																									
