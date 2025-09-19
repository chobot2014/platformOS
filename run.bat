@echo off
echo Running platformOS ISO in QEMU via Docker...
echo.
echo Your custom operating system is now running!
echo Press Ctrl+C to stop the emulator
echo.

docker build -f Dockerfile.run -t platformos-runner .

docker run --rm -it -v "%cd%:/app" platformos-runner