# LilyEngine
Lily Engine is a high-layer game engine that can be used with Lua. It is highly versatile and has special functions.
# Q&A
Q: Can I contribute to the development?
A: This is a personal practice project, so I'm reluctant to contribute. We welcome bug reports and questions about the program.

Q:Is using this program recommended?
A:No. Please keep in mind that this project is very experimental.

Q:Why are there so many strange functions?
A:That's an interesting question. This project is seriously being developed as a developer's toy.

# How to build.
Please install SDL3, imgui, and Lua via vcpkg.
Then run this at the command prompt.
```
cmake . --preset x64-debug
```
or
```
cmake . --preset x64-release
```

# How to use.
Create a lua folder in the folder where the executable file is located and write the script in it.