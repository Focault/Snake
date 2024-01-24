#!/bin/bash

# Function to check and install dependencies
check_and_install_dependency() {
    local command_name="$1"
    local package_name="$2"

    if ! command -v "$command_name" &> /dev/null; then
        echo "$command_name not found. Installing $package_name..."
        sudo apt-get update
        sudo apt-get install -y "$package_name"
    fi
}

# Check and install Docker
check_and_install_dependency "docker" "docker.io"

# Check and install Docker Compose
check_and_install_dependency "docker-compose" "docker-compose"

# Check and install xauth
check_and_install_dependency "xauth" "xauth"

# Check if X11 server is running
if ! xhost &> /dev/null; then
    echo "X11 server not running. Please start your X11 server."
    exit 1
fi

# Generate X11 authorization cookie
xauth generate :1 . trusted
X11_COOKIE=$(xauth list | grep "$(hostname)/unix:1" | awk '{print $3}')

# Set environment variables for Docker Compose
export DISPLAY=:1
export XAUTHORITY=$(mktemp)
xauth add :1 . $X11_COOKIE

# build Docker Image
docker-compose build

# make run script executable
chmod +x ./run.sh

# Clean up
rm -f $XAUTHORITY