#include <jni.h>
#include <string>

extern "C"{
#include <libavutil/avutil.h>
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mdplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    hello.append(av_version_info());
    return env->NewStringUTF(hello.c_str());
}
