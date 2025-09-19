# platformOS
Operating System written in typescript

## Building

This project is dockerized for easy building on any platform.

### Prerequisites
- Docker

### Build Instructions
1. Run the build script:
   ```bash
   ./build.bat
   ```
   or on Linux/Mac:
   ```bash
   docker build -t platformos-builder .
   docker create --name temp-container platformos-builder
   docker cp temp-container:/app/platformOS.iso .
   docker rm temp-container
   ```

2. The `platformOS.iso` file will be created in the project root.

## Manual Build (Linux only)
Follow the steps in `notes.md` for manual building on Linux.

## TODO
- Create build script: typescript to .iso file with npm run build
