GCC := g++
GCC_FLAGS := -Wall -Werror -Wextra --std=c++17

LIB_SRC := ./src/lib/*/*.cc
LIB_INC := ./src/lib/*/*.h

all:

style:
	clang-format -style=Google -i $(LIB_SRC) $(LIB_INC)

clean:

rebuild: