# <img src="Resources/logo.png" alt="Logo" width="20"/> SkeletonEngine <!-- omit in toc -->
Welcome SkeletonEngine <img src="Resources/logo.png" alt="Logo" width="10"/>

This engine is a hobby and very much a work-in-progress, without much work or progress. Everything here is subject to change and the README is more of a notepad than an introduction right now.

If you are actually looking for a *good*, *usable* engine and ended up here by accident, checkout [Godot](https://godotengine.org).



- [Notes](#notes)
- [Road Map](#road-map)
- [Building SkeletonEngine](#building-skeletonengine)
  - [Prerequisites](#prerequisites)
  - [Windows](#windows)
  - [Linux and macOS / OS X](#linux-and-macos--os-x)
- [Building the Docs](#building-the-docs)
  - [Prerequisites](#prerequisites-1)
  - [Windows](#windows-1)
  - [Linux, macOS / OS X](#linux-macos--os-x)
- [LICENSE](#license)



# Notes
TODO: Create proper icon (to replace `Resources/logo.png`)

TODO: Create proper logo

TODO: Create banner-style logo



# Road Map
- Get very basic window to compile on Linux
- Implement features on Windows build until reasonable
- Slowly add features to Linux build
- OSX / macOS eventually



# Building SkeletonEngine
How to build SkeletonEngine on various platforms.
## Prerequisites
Python 3

For Windows, it is recommended to use Visual Studio 2019 Community edition.
## Windows
Run `python generate_projects.py` to generate a Visual Studio solutions (`SkeletonEngine.sln`) which can then be opened in Visual Studio. By deafult, the solution is built for Visual Studio 2019.
## Linux and macOS / OS X
Run `./generate_projects.py` to generate the required `Makefile`s.

Run `make` from the project source to build the project.



# Building the Docs
Building the SkeletonEngine documentation on various platforms.
## Prerequisites
[Python 3](https://www.python.org/downloads/)

[Doxygen](https://www.doxygen.nl/manual/install.html)

Sphinx (`pip install -U Sphinx`)

Breathe (`pip install breathe`)

Exhale (`pip install exhale`)
## Windows
Run `python generate_projects.py docs` to build the docs.

Run `python generate_projects.py viewdocs` to open the docs in browser.

Run `python generate_projects.py docs viewdocs` to build and view the docs.
## Linux, macOS / OS X
Run `./generate_projects.py docs` to build the docs.

Run `./generate_projects.py viewdocs` to open the docs in browser.

Run `./generate_projects.py docs viewdocs` to build and view the docs.



# LICENSE
TODO: Pick a LICENSE
