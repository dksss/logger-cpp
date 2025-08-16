GCC := g++
GCC_FLAGS := -Wall -Werror -Wextra --std=c++17

LIB_SRC := ./src/lib/*/*.cc
LIB_INC := ./src/lib/*/*.h

DOXYFILE := Doxyfile

.PHONY: all style docs clean open_docs

all:

style:
	clang-format -style=Google -i $(LIB_SRC) $(LIB_INC)

docs:
	doxygen $(DOXYFILE)

open_docs:
	open ./docs/html/index.html

test:


clean:
	rm -rf docs/html


rebuild:
