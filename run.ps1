Write-Host "Running platformOS ISO in QEMU via Docker..."

docker build -f Dockerfile.run -t platformos-runner .

docker run --rm -it -v "${PWD}:/app" platformos-runner