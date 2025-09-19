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

## Running the OS

After building, run your operating system:

```bash
./run.bat
```

This will start QEMU with your platformOS ISO. The OS will boot and you'll see the QEMU monitor. Press Ctrl+C to stop the emulator.

## Development Workflow

1. **Build**: `./build.bat` (creates platformOS.iso)
2. **Run**: `./run.bat` (runs the OS in QEMU)
3. **Modify**: Edit TypeScript code in `assembly/` or C code in `build/`
4. **Repeat**: Rebuild and run to test changes

## Manual Build (Linux only)
Follow the steps in `notes.md` for manual building on Linux.

## TODO
- Create build script: typescript to .iso file with npm run build
