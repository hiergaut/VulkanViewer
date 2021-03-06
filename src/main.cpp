
#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>

#include <iostream>
#include <vulkan/vulkan_core.h>

#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
//int main() {
    //return 0;
//    glfwInit();
//
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported" << std::endl;
    __android_log_print(ANDROID_LOG_VERBOSE, "Own Tag", "--------------------------------------");

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

//    return 0;
//}


    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}