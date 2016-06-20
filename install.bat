set PATH=%PATH%;C:\Program Files (x86)\CMake\bin
set compiler=C:\Program Files (x86)\MSBuild\14.0\Bin

mkdir ThirdParties

git clone https://github.com/glfw/glfw ThirdParties/GLFW
git clone https://github.com/g-truc/glm ThirdParties/GLM

cd ThirdParties/GLFW
mkdir build
cd build
cmake ../ -G "Visual Studio 14 2015 Win64"

cd ../../../

"%compiler%\msbuild" "ThirdParties/GLFW/build/GLFW.sln" /p:Configuration=Debug /p:Platform="x64"
"%compiler%\msbuild" "ThirdParties/GLFW/build/GLFW.sln" /p:Configuration=Release /p:Platform="x64"

mkdir build
cd build
cmake ../ -G "Visual Studio 14 2015 Win64"

"%compiler%\msbuild" "testGL.sln" /p:Configuration=Debug /p:Platform="x64"
"%compiler%\msbuild" "testGL.sln" /p:Configuration=Release /p:Platform="x64"