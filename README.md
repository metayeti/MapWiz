![MapWiz](dev/logo/logo_64x64.png?raw=true)
# MapWiz

2D map editor

v0.0.1

🚧 -- UNDER CONSTRUCTION -- 🚧

This project is a work in progress and is not currently in any type of functional or useful state. Please grab a time machine and check back in at a later time.

## About

MapWiz is a free and open source, cross-platform, general-purpose 2D map editor intended for 2D game development. Its main features are:

- Fast, lightweight and responsive, with as little cruft as humanly possible.
- Scales well. Your enormous maps are safe here.
- Comes with a custom binary map format. Also offers a JSON-formatted export.
- Map importers for C, C++ and JS.
- Designed around portability. MapWiz consists of one single executable that you can drop into any project. When first launched, it creates a local configuration ini file, which means that you can keep the level editor and its local configuration with a grand total of 2 files. The idea behind this approach is that inside your game project, the editor remains preconfigured for your game. MapWiz has no installer, the executable is all you need to use it.
- Some advanced features. This project does not intend to compete or catch up with other, bigger editors. The aim of this project is to provide a minimalistic but powerful featureset built around a transparent and intuitive workflow.

## Installation

MapWiz is a portable program. See [releases](releases/) for binary distributions for Windows. For non-Windows systems you will have to build the program yourself (see [build instructions](BUILDING.md)).

## Contribution

This project is **not** currently open for contributions. Please note that unless the PR is of exceptional quality or resolves some type of critical bug, it will most likely be turned down so be forewarned before you attempt to contribute.

If you absolutely need additional features then please consider forking the project.

## Credits

- [wxWidgets](https://www.wxwidgets.org/) - GUI library

# License

Copyright &copy; 2024 Danijel Durakovic

Licensed under the terms of the [GPLv3 license](LICENSE)
