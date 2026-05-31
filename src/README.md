# AudioQ

[![CI](https://github.com/YOUR_USERNAME/audioq/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/audioq/actions/workflows/ci.yml)
[![Release](https://github.com/YOUR_USERNAME/audioq/actions/workflows/release.yml/badge.svg)](https://github.com/YOUR_USERNAME/audioq/releases/latest)

A fast, multi-threaded audio format converter for Linux, built with Qt6 and powered by ffmpeg.

![AudioQ screenshot](audioq.svg)

---

## Features

- **Multi-threaded** — configurable parallel conversion (up to your CPU core count)
- **Per-file progress bar** — real-time progress via `ffmpeg -progress pipe:1`
- **Output formats** — MP3, AAC (.m4a), Ogg Vorbis, Opus, FLAC, WAV (PCM), AIFF
- **Quality presets** — CBR/VBR bitrates, compression levels per format
- **Tag preservation** — copies ID3/Vorbis tags and cover art
- **Drag & drop** — files and folders, with optional subfolder recursion
- **Settings dialog** — enable/disable individual formats, codec availability precheck
- **ffmpeg log pane** — dockable, hidable, colour-coded output from ffmpeg
- **Dark theme UI**

---

## Requirements

| Dependency | Version | Install (Arch) | Install (Ubuntu/Debian) |
|------------|---------|----------------|-------------------------|
| Qt6 Widgets | 6.2+   | `qt6-base`     | `qt6-base-dev`          |
| CMake       | 3.16+  | `cmake`        | `cmake`                 |
| ffmpeg      | 4.0+   | `ffmpeg`       | `ffmpeg`                |
| ffprobe     | (bundled with ffmpeg) | — | — |

---

## Build from source

```bash
# Arch / CachyOS / Manjaro
sudo pacman -S qt6-base cmake ninja ffmpeg

# Ubuntu 22.04+
sudo apt-get install qt6-base-dev libgl-dev libxkbcommon-dev cmake ninja-build ffmpeg

# Build
git clone https://github.com/YOUR_USERNAME/audioq.git
cd audioq
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
./build/audioq
```

---

## Run tests

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
cd build && ctest --output-on-failure
```

---

## Install (system-wide)

```bash
cmake --install build --prefix /usr/local
# Binary  → /usr/local/bin/audioq
# Icon    → /usr/local/share/icons/hicolor/scalable/apps/audioq.svg
# Launcher→ /usr/local/share/applications/audioq.desktop
```

---

## Release

Releases are created automatically by pushing a version tag:

```bash
git tag v1.2.0
git push origin v1.2.0
```

The [release workflow](.github/workflows/release.yml) will:
1. Build in Release mode
2. Run all unit tests (must pass)
3. Strip and package the binary + sources into a zip
4. Create a GitHub Release with the zip attached

Pre-release versions are detected automatically from tags containing a `-`
(e.g. `v1.2.0-beta.1`).

---

## Project structure

```
audioq/
├── main.cpp
├── mainwindow.h / mainwindow.cpp   # Main window, conversion logic, worker threads
├── settingsdialog.h / settingsdialog.cpp  # Settings dialog, codec precheck
├── CMakeLists.txt
├── audioq.svg                      # Application icon
├── audioq.desktop                  # Linux desktop entry
├── build.sh                        # Convenience build script
├── tests/
│   ├── tst_audioq.cpp              # 37 unit tests (Qt Test)
│   └── CMakeLists.txt
└── .github/
    └── workflows/
        ├── ci.yml                  # Build + test on push / PR
        └── release.yml             # Package + publish on version tag
```

---

## License

MIT
