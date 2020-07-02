# <img src="Resources/logo.png" alt="Logo" width="20"/> SkeletonEngine <!-- omit in toc -->
Welcome SkeletonEngine <img src="Resources/logo.png" alt="Logo" width="10"/>

This engine is a hobby and very much a work-in-progress, without much work or progress. Everything here is subject to change and the README is more of a notepad than an introduction right now.

If you are actually looking for a *good*, *usable* engine and ended up here by accident, checkout [Godot](https://godotengine.org).

- [Notes](#notes)
- [Building SkeletonEngine](#building-skeletonengine)
  - [Requirements](#requirements)
  - [Windows](#windows)
  - [Linux](#linux)
  - [OSX / macOS](#osx--macos)
- [Building the Docs](#building-the-docs)
  - [Requirements](#requirements-1)
    - [Python 3](#python-3)
    - [Doxygen](#doxygen)
    - [Sphinx](#sphinx)
    - [Breathe](#breathe)
    - [Exhale](#exhale)
  - [Windows](#windows-1)
  - [Linux, OSX / macOS](#linux-osx--macos)
- [LICENSE](#license)

# Notes
Why does `vendor/bin/premake5/*` get ignored by git? TODO: Fix it

TODO: Create proper icon (to replace `Resources/logo.png`)

TODO: Create proper logo

TODO: Create banner-style logo

TODO: Consistant capitalisation for folder names


# Building SkeletonEngine
How to build SkeletonEngine on various platforms.

TODO: Instead of multiple build scripts, have one Python build script that reacts to platform?

## Requirements
TODO: Include premake5 executables for Win/*nix and LICENSE in repo

Get the [premake5](https://github.com/premake/premake-core) executable for your system and place it in `vendor/bin/premake5/` as `premake5` on *nix and `premake5.exe` on Windows.

## Windows
Run `GenerateProjects.Windows.VS2019.bat`

The produced `SkeletonEngine.sln` can be opened in Visual Studio and built from there.

TODO: Windows build from command line

## Linux
Run `GenerateProjects.Linux.gmake.sh`

Run `make`

TODO: Get SE to compile on Linux (https://gcc.gnu.org/wiki/Visibility)


## OSX / macOS
Maybe later...

If you really have to try, it should be similar to Linux.


# Building the Docs
Building the SkeletonEngine documentation on various platforms.

TODO: Make a script for this

## Requirements
Install the following requirements

### Python 3
Not directly required by required needed for `pip` installs of other requirements.

Check `python --version` if it is Python 2 check `python3 --version`, which everone gives version Python 3 assume `python` and `pip` refer to `python`/`python3` and `pip`/`pip3` respectively.

### Doxygen
Get [doxygen](https://www.doxygen.nl/download.html). For Windows and OSX / macOS binaries are available. For Linux the binaries didn't work for me so I built from source: [instructions](https://www.doxygen.nl/manual/install.html).

### Sphinx
Run ```pip install -U Sphinx``` (for Python 3 `pip`)

### Breathe
Run ```pip install breathe``` (for Python 3 `pip`)

### Exhale
Run ```pip install exhale``` (for Python 3 `pip`)

## Windows
Build the docs on Windows
```
cd Docs
make html
```

## Linux, OSX / macOS
Build the docs on Linux or OSX / macOS
```
cd Docs
sphinx-build -M html . _build
```

TODO: Test this

TODO: Make a script for this?


# LICENSE
TODO: Pick a LICENSE
