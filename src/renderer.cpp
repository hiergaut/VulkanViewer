
#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>

#include <iostream>
#include <vulkan/vulkan_core.h>

#include <SDL2/SDL.h>
//#include "SDL.h"

#include <string>

void render()
{
    //return 0;
    //    glfwInit();
    //
    //    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported" << std::endl;

    std::cout << VK_API_VERSION_1_0 << "\t" << VK_HEADER_VERSION << std::endl;

    //    glm::mat4 matrix;
    //    glm::vec4 vec;
    //    auto test = matrix * vec;

    //    while(!glfwWindowShouldClose(window)) {
    //        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    //            glfwSetWindowShouldClose(window, true);
    //        }
    //
    //        glfwPollEvents();
    //    }
    //
    ////    glfwDestroyWindow(window);
    //
    //    glfwTerminate();

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    SDL_DestroyWindow(window);
    SDL_Quit();

}
