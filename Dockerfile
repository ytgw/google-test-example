FROM ubuntu:latest

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
