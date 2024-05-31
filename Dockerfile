FROM ubuntu:latest

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential cmake git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/google/googletest.git
ARG BUILD_DIR='build'
RUN cd googletest \
    && cmake -S . -B ${BUILD_DIR} \
    && cmake --build ${BUILD_DIR} \
    && cmake --install ${BUILD_DIR}
