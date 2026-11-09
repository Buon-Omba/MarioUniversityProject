# Super Mario Bros. Qt — University Project

When I was studying at university I created this simple project: it is nothing more than a fork, in Qt and C++, of the first two levels of Super Mario Bros. A very simple Bowser boss fight has been added towards the end, but there is no World 1-4. It should be considered exclusively an educational project, which I am trying to develop a little further.

To-Do:
- Complete World 1-3 and 1-4
- Create an .AppImage

## Build (Arch Linux and derivatives)

```bash
sudo pacman -S --needed cmake qt5-base qt5-multimedia
cmake -S . -B build
cmake --build build
./build/supermario
```

On Windows the project can also be opened in Visual Studio 2022 with `Supermario.sln`.

## Disclaimer

This is a non-commercial educational project and is not affiliated with or endorsed by Nintendo.
Super Mario Bros., its characters, graphics and sounds are the property of Nintendo Co., Ltd.
Only the source code is released under the Unlicense: see [LICENSE.txt](LICENSE.txt).
