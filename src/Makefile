# Makefile の特殊変数・自動変数の一覧
# https://tex2e.github.io/blog/makefile/automatic-variables
# Makefile の関数一覧
# https://tex2e.github.io/blog/makefile/functions

APP_VERSION = $(shell git show --format='%h' --no-patch)

CXX          = g++
CXX_FLAFS    = -Wall -DAPP_VERSION=\"$(APP_VERSION)\"
INCLUDE_DIRS = -I ../mylib/include -I include
LIB_DIRS     = -L ../mylib/lib
LIBS         = -l mylib

BUILD_DIR = build
SRCS      = $(wildcard *.cpp)
OBJS      = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET    = $(BUILD_DIR)/main


# makeを実行すると最初のターゲットが実行される。
all: build

# @-をつけると実行するコマンドを表示しない
clean:
	@-echo '---------- start $@ ----------'
	rm -rf $(BUILD_DIR)
	@-echo '---------- end $@ ----------'

build: $(OBJS)
	@-echo '---------- start $@ ----------'
	$(CXX) -o $(TARGET) $^ $(CXX_FLAFS) $(LIB_DIRS) $(LIBS)
	@-echo '---------- end $@ ----------'

$(BUILD_DIR)/%.o: %.cpp
	@-mkdir -p $(BUILD_DIR)
	$(CXX) -o $@ -c $^ $(CXX_FLAFS) $(INCLUDE_DIRS)

run:
	LD_LIBRARY_PATH=../mylib/lib $(TARGET)
