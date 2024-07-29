
# Vroom

Vroom is a 3D game engine made with OpenGL. It is a personal project I'm doing to improve myself as a computer graphics and C++ developer.
This project has been reset, the old version in 2D with SFML is still available in branch "V1".

## Building project

### Windows

#### Visual Studio

In repository root folder, open a terminal and type :

```bash
mkdir build
cd build
cmake ..
ctest # If you want to run unit tests
doxygen ../Doxyfile # If you need to generate documentation
```

#### VS Code

You can also build the project by opening the root folder on VS Code, and use the "CMake" and "CMake Tools" VS Code extensions (that is my workflow).

### Linux

> **_NOTE:_**  Vroom is actively developped for the Windows platform, but I try to keep it compatible with Linux as much as possible. Vroom may not be fully functional on Linux.

- Install required dependencies:
```bash
sudo apt install libglew-dev
```

- In repository root folder, open a terminal and type:
```bash
mkdir build
cd build
cmake ..
make
```

- Launching Sandbox program:
```bash
cd Sandbox # Don't use ./Sandbox/Sandbox directly because the program won't be able to load resource files.
./Sandbox
```

## External libraries

- [glew](https://glew.sourceforge.net/)
- [glfw](https://www.glfw.org/)
- [glm](https://github.com/icaven/glm)
- [spdlog](https://github.com/gabime/spdlog)
- [stb](https://github.com/nothings/stb)
- [OBJ-Loader](https://github.com/Bly7/OBJ-Loader)
- [entt](https://github.com/skypjack/entt)

## Inspirations

- [Hazel](https://github.com/TheCherno/Hazel), game engine created by TheCherno.
- [Unreal Engine](https://www.unrealengine.com/)
- [javidx9 (YouTube)](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)

## Known problems

- Unbinding trigger and custom event inputs is buggy.
