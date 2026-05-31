# AudioQ — Qt6 Audio Converter for Linux

## Bug fixes
- AAC (.m4a) now works reliably: cover art mapping disabled for m4a
  (real-world files with embedded cover caused silent ffmpeg failure)
- Drag & drop from file manager no longer crashes: QMessageBox was called
  inside dropEvent() causing Qt re-entrancy; deferred via QTimer::singleShot
- Non-local URLs (trash://, smb://, empty) in drop events are filtered out

## Running tests
  cd bin && ./tst_audioq            # run all 35 unit tests
  cd src && cmake -B build && cmake --build build && ctest  # build+test from source

## Build from source (Arch / CachyOS)
  sudo pacman -S qt6-base cmake ffmpeg
  cd src && bash build.sh
