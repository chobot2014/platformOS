@echo off
echo Building platformOS in Docker...

docker build -t platformos-builder .

echo Creating container to extract ISO...
docker create --name temp-container platformos-builder
docker cp temp-container:/app/platformOS.iso .
docker rm temp-container

echo Build complete! ISO file: platformOS.iso