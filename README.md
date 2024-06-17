
# Vroom

Vroom is a 3D game engine made with OpenGL. It is a personal project I'm doing for fun to improve myself as a C++ developer.
This project has been reset, the old version in 2D with SFML is still available in branch "V1".

## Building project

Building has only been tested on Windows.
In repository root folder, open a terminal and type :

```bash
mkdir build
cd build
cmake ..
cmake --build . --config [Release|Debug]
```

Output files will be written in Vroom/build/[Project]/[config]/ folder, where [Project] is Vroom or Sandbox, and config is Release or Debug.

## External libraries

- [glew](https://glew.sourceforge.net/)
- [glfw](https://www.glfw.org/)
- [glm](https://github.com/icaven/glm)
- [spdlog](https://github.com/gabime/spdlog)
- [stb](https://github.com/nothings/stb)

## Inspirations

- [Hazel](https://github.com/TheCherno/Hazel), game engine created by TheCherno.
- [Unreal Engine](https://www.unrealengine.com/)
- [javidx9 (YouTube)](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)

## Implemented features (explained)

- Please check branch V1 to see previously implemented features (with SFML rendering). Most of them will be implemented in V2 too.

## Known problems
