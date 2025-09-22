# GooseCrypto Node Dockerfile
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libssl-dev \
    libboost-all-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

# Create app directory
WORKDIR /app

# Copy source code
COPY . .

# Build the application
RUN mkdir build && cd build && cmake .. && make

# Expose ports
EXPOSE 1337 8080

# Run the node
CMD ["./build/goosecrypto_node"]