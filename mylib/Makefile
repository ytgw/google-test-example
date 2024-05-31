CXX          = g++
INCLUDE_DIRS = -I include
LIB_DIR      = lib
LIB_PATH     = $(LIB_DIR)/libmylib.so
SRCS         = $(wildcard *.cpp)


# makeを実行すると最初のターゲットが実行される。
all: build

clean:
	rm -rf $(LIB_DIR)

# @-をつけると実行するコマンドを表示しない
build: $(SRCS)
	@-mkdir -p $(LIB_DIR)
	$(CXX) -shared -fPIC -o $(LIB_PATH) $^ $(INCLUDE_DIRS)
