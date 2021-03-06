mkdir build
cd build

if [ "$TRAVIS_OS_NAME" = "linux" ]; then 
  cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=${CONFIG} -DCMAKE_INSTALL_PREFIX=install
  cmake --build . --target install
fi

if [ "$TRAVIS_OS_NAME" = "osx" ]; then 
  if [ "$IOS" = "true" ]; then 
    cmake .. -DCMAKE_TOOLCHAIN_FILE=../DiligentCore/ios.toolchain.cmake -DIOS_PLATFORM=OS64 -DIOS_ARCH=arm64 -DVULKAN_SDK="$VULKAN_SDK" -DCMAKE_INSTALL_PREFIX=install -G "Xcode"
  else
    cmake .. -DCMAKE_INSTALL_PREFIX=install -G "Xcode"
  fi
  cmake --build . --target install --config ${CONFIG} | xcpretty
fi

