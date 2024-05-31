CXX             = g++
INCLUDE_DIRS    = -I include -I $(PRODUCT_SRC_DIR)/include -I ../mylib/include

BUILD_DIR         = build
PRODUCT_BUILD_DIR = $(BUILD_DIR)/src
TEST_BUILD_DIR    = $(BUILD_DIR)/test

PRODUCT_SRC_DIR = ../src
PRODUCT_SRCS = $(filter-out $(PRODUCT_SRC_DIR)/main.cpp, $(wildcard $(PRODUCT_SRC_DIR)/*.cpp))
TEST_SRCS    = $(wildcard *.cpp)

PRODUCT_OBJS = $(patsubst ../%.cpp, build/%.o, $(PRODUCT_SRCS))
TEST_OBJS    = $(patsubst %.cpp, $(TEST_BUILD_DIR)/%.o, $(TEST_SRCS))

$(warning PRODUCT_SRCS = $(PRODUCT_SRCS))
$(warning PRODUCT_OBJS = $(PRODUCT_OBJS))

$(warning TEST_SRCS    = $(TEST_SRCS))
$(warning TEST_OBJS    = $(TEST_OBJS))

TARGET    = $(BUILD_DIR)/test_main


# makeを実行すると最初のターゲットが実行される。
all: build test

clean:
	@-echo '---------- start $@ ----------'
	rm -rf $(BUILD_DIR)
	@-echo '---------- end $@ ----------'

build: $(TEST_OBJS) $(PRODUCT_OBJS)
	@-echo '---------- start $@ ----------'
	$(CXX) -o $(TARGET) $^ -lgtest_main -lgtest -lpthread
	@-echo '---------- end $@ ----------'

test: build
	$(TARGET)

$(TEST_BUILD_DIR)/%.o: %.cpp
	@-mkdir -p $(TEST_BUILD_DIR)
	$(CXX) -o $@ -c $^ $(INCLUDE_DIRS)

$(PRODUCT_BUILD_DIR)/%.o: ../src/%.cpp
	@-mkdir -p $(PRODUCT_BUILD_DIR)
	$(CXX) -o $@ -c $^ $(INCLUDE_DIRS)
