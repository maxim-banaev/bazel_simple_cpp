FROM ubuntu:24.04

ARG BAZELISK_VERSION=v1.27.0
ARG TARGETARCH

ENV DEBIAN_FRONTEND=noninteractive

# GNU toolchain (gcc/g++, binutils, make, gdb) plus what Bazel needs at runtime.
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        gdb \
        libicu-dev \
        git \
        ca-certificates \
        curl \
        python3 \
        unzip \
        zip \
    && rm -rf /var/lib/apt/lists/*

# Bazelisk as `bazel`; it downloads the version pinned in .bazelversion.
RUN curl -fsSL -o /usr/local/bin/bazel \
        "https://github.com/bazelbuild/bazelisk/releases/download/${BAZELISK_VERSION}/bazelisk-linux-${TARGETARCH:-amd64}" \
    && chmod +x /usr/local/bin/bazel

# Make Bazel's auto-configured C++ toolchain pick GCC.
ENV CC=gcc CXX=g++

# Pre-create the cache dir so the mounted volume is owned by ubuntu.
RUN mkdir -p /home/ubuntu/.cache && chown ubuntu:ubuntu /home/ubuntu/.cache

USER ubuntu
