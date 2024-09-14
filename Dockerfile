FROM ubuntu:latest

# 64bitイメージだと古いlinuxでも2025年2月まで開発コンテナが利用できる
# https://code.visualstudio.com/docs/remote/faq#_can-i-run-vs-code-server-on-older-linux-distributions
# FROM ubuntu:16.04

# 32bitイメージだと開発コンテナが利用できない
# FROM ubuntu@sha256:bcb8397f1390f4f0757ca06ce184f05c8ce0c7a4b5ff93f9ab029a581192917b

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential cmake git sudo bash-completion \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/google/googletest.git
ARG BUILD_DIR='build'
RUN cd googletest \
    && cmake -S . -B ${BUILD_DIR} \
    && cmake --build ${BUILD_DIR} \
    && cmake --install ${BUILD_DIR}

# ubuntu24ではuid=1000のubuntuというユーザーがデフォルトで存在する。
# 追加するユーザとUIDが重複するときの条件分岐を避けるため削除する。
RUN userdel -r ubuntu
ARG USERNAME='user'
ARG UID
# useraddのmオプションはホームディレクトリ作成のため。
# VSCode周りのファイルはホームディレクトリ以下に作成されるのでmオプションが必要。
RUN useradd -u ${UID} --shell /bin/bash -m ${USERNAME}
RUN echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER ${USERNAME}
