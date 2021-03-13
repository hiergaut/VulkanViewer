#include <jni.h>
#include <string>

//#include "renderer.h"
//#include "SDL.h"
//#include <linux/sdla.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
//    render();


    return env->NewStringUTF(hello.c_str());
}