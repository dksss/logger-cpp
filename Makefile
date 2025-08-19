FLAGS := -Wall -Werror -Wextra
COVERAGE_FLAGS := -fprofile-arcs -ftest-coverage

GXX := g++
GXX_FLAGS := $(FLAGS) --std=c++17

LIB_SRC := ./src/lib/*/*.cc
LIB_INC := ./src/lib/*/*.h
APP_SRC := ./src/app/*/*.cc
APP_INC := ./src/app/*/*.h

DOXYFILE := Doxyfile

TEST_DIR := ./tests
TEST_SRC := $(TEST_DIR)/*.cc
TEST_LIBS := -lgtest -lgtest_main

BUILD_DIR := ./build

.PHONY: all style docs clean open_docs test coverage valgrind

all: app

app: liblogger.so $(APP_SRC) $(APP_INC)
	@mkdir -p $(BUILD_DIR)
	$(GXX) $(GXX_FLAGS) -I./src/lib -I./src/app -o $(BUILD_DIR)/$@ $(APP_SRC) ./src/app/main.cc \
	-L$(BUILD_DIR) -Wl,-rpath=$(BUILD_DIR) -llogger

liblogger.so: $(LIB_SRC) $(LIB_INC)
	@mkdir -p $(BUILD_DIR)
	$(GXX) $(GXX_FLAGS) -fPIC -shared -o $(BUILD_DIR)/$@ $(LIB_SRC)

check_style:
	@clang-format -style=Google -n $(LIB_SRC) $(LIB_INC) $(TEST_SRC) $(TEST_DIR)/*.h \
	$(APP_SRC) $(APP_INC) ./src/app/main.cc

docs:
	doxygen $(DOXYFILE)

open_docs: docs
	open ./docs/html/index.html

test:
	@$(GXX) $(GXX_FLAGS) -o $@ $(TEST_SRC) $(LIB_SRC) $(TEST_LIBS)
	@./$@

valgrind: test
	CK_FORK=no valgrind -s  --track-origins=yes --tool=memcheck --leak-check=full \
	--show-leak-kinds=all --log-file=RESULT_VALGRIND.txt ./$<
	@rm $<

coverage:
	$(GXX) $(GXX_FLAGS) $(COVERAGE_FLAGS) -o tests_coverage $(TEST_SRC) $(LIB_SRC) $(TEST_LIBS)
	./tests_coverage
	lcov -t "Logger lib tests" -o coverage.info --no-external -c -d . --ignore-errors mismatch
	genhtml -o report coverage.info
	@rm *.info *.gcda *.gcno
	@rm tests_coverage
	@open report/index.html

clean:
	@rm -rf ./docs/html ./report ./RESULT_VALGRIND.txt ./build ./test ./*.txt

rebuild: clean all