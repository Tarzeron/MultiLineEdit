# !/bin/sh 
export ANDROID_NDK=~/Android/Sdk/ndk/21.0.6113669
export ANDROID_SDK=~/Android/Sdk
export PATH=$ANDROID_NDK/toolchains/x86_64-4.9/prebuilt/linux-x86_64/bin:$ANDROID_NDK/build:$ANDROID_NDK/prebuilt/linux-x86_64/bin:$ANDROID_SDK/tools:$ANDROID_SDK/tools/bin:$ANDROID_SDK/platform-tools:$PATH

export URHO3D_HOME=~/workspace/Urho3D/android/urho3d-lib/build/outputs/aar


cd ./android

./gradlew installDebug
