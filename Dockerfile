FROM ubuntu:22.04

# Install Node.js 18 (has fetch support)
RUN apt-get update && apt-get install -y \
    curl \
    && curl -fsSL https://deb.nodesource.com/setup_18.x | bash - \
    && apt-get install -y nodejs \
    && rm -rf /var/lib/apt/lists/*

# Install other dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    nasm \
    grub-pc-bin \
    cmake \
    git \
    xorriso \
    python3 \
    python3-dev \
    gcc-multilib \
    g++-multilib \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy package files first for better caching
COPY package*.json ./

# Install AssemblyScript compiler
RUN npm install -g assemblyscript

# Copy source code
COPY . .

# Clone and build wabt (WebAssembly Binary Toolkit) - skip if wasm2c already exists
RUN if [ ! -f build/wasm2c ]; then \
    cd lib && \
    rm -rf wabt && \
    git clone https://github.com/WebAssembly/wabt.git && \
    cd wabt && \
    mkdir build && \
    cd build && \
    git submodule update --init && \
    cmake .. && \
    cmake --build . && \
    cp wasm2c ../../../build/; \
    fi

# Build the OS
RUN npm run build

# Create ISO directory structure
RUN mkdir -p isodir/boot/grub && \
    cp build/kernel isodir/boot/ && \
    cp isodir/boot/grub/grub.cfg isodir/boot/grub/ || echo "grub.cfg not found, creating default"

# Create a basic grub.cfg if it doesn't exist
RUN if [ ! -f isodir/boot/grub/grub.cfg ]; then \
    echo 'set timeout=0' > isodir/boot/grub/grub.cfg && \
    echo 'set default=0' >> isodir/boot/grub/grub.cfg && \
    echo '' >> isodir/boot/grub/grub.cfg && \
    echo 'menuentry "platformOS" {' >> isodir/boot/grub/grub.cfg && \
    echo '    multiboot /boot/kernel' >> isodir/boot/grub/grub.cfg && \
    echo '    boot' >> isodir/boot/grub/grub.cfg && \
    echo '}' >> isodir/boot/grub/grub.cfg; \
    fi

# Create the ISO
RUN grub-mkrescue -o platformOS.iso isodir/

# Default command
CMD ["bash"]