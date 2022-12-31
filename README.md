
# Vroom

Vroom is a 2D game engine made with SFML. It is a personal project I'm doing for fun a to improve myself as a C++ developer.

## Building project

No CMake files are set up for now since I'm using Visual Studio. I will do it as soon as I can.
I plan to add submodules for libraries I use.

## External libraries

- [SFML](https://github.com/SFML/SFML)
- [SPDLOG](https://github.com/gabime/spdlog)
- [entt](https://github.com/skypjack/entt)

## Inspirations

- [Hazel](https://github.com/TheCherno/Hazel), created by TheCherno.
- [Unreal Engine](https://www.unrealengine.com/)
- [javidx9 (YouTube)](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)

## Implemented features

- Assets manager with fixed size
    - Assets are designated by their on disk adress. Getting an asset only requires its adress.
    - Assets are separated into to types : StaticAsset and DynamicAsset. Getting an asset loads a static asset if it is not cached, or retrieves the cached static asset if already cached. It will then instanciate a dynamic asset from the static one. Dynamic assets can be used in components, and their number is stored in their related static asset. If a static asset has no instance (i.e their is no dynamic asset in use), the static asset stays loaded in cache, and is eligble for unloading when the cache runs out of space.
    - Users don't have to know about static assets, they only deal with dynamic assets.
- Entity Component System (ECS)
    - Entities and components are registered with the entt library.
    - Sprite component.
        - Owns a sprite asset instance.
    - Script component.
        - A custom script must be derived from ScriptComponent.
        - A script can access its owning entity and its sibling components.
        - onSpawn and onUpdate virtual member functions.
- Events management
    - Events can be created with a string name identifier and a keyboard/mouse event.
    - Callbacks can be linked to events. When an event state is updated (mouse button/key pressed/released), it will trigger all linked callbacks.

## Planned features

- Collision box components.
- Physics engine (only collisions, maybe physics simulation too).
- HUDs implementation.
- Tilemap component.
- Camera component.
- Only render visible sprites (related with the camera component).
    - Maybe with some chunks manager.
- Flipbook component (for animations).
- Flipbook state machine (for flibooks transitions).
- Network manager with replicated functions (as Unreal Engine does).
- Storage of user inputs in a configuration file that will be loaded at runtime.
- Game save system.

### Possible features

- Simulated physics.
- Create my own renderer with OpenGL.

## Known problems

- When two inputs are bound to the same event name, the behaviour is strange (triggering input 1 triggers the event, and triggering input 2 while input 1 is triggered stops triggering the event).

## To-do list

- Externalize events managing into a separate class.
- Create a function that tells if an event is currently triggered.
- Create a wrapper that makes class member functions easier to bind to an event.

## About me

I'm a 24 years old third year computer sciences student living in Dijon, France. I'm interested in rendering, software engineering, maths and game engines, that's why I'm working on this side project. For now, I am using SFML instead of designing my own rendering library, just because I am currently not in a rendering mood. No doubt it would be cool to design my own 2D renderer.

I do not intend to make this engine a reference in the video game industry, I just want to have fun making it. Maybe someday I'll use it in a game jam, or maybe in one of my university assignments. It could be a great goal to be able to use it these ways.