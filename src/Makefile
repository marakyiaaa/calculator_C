FLAGS = -Wall -Werror -Wextra -std=c11
OS := $(shell uname)
FILES = $(wildcard s21_check_error.c s21_polish.c s21_stack.c s21_support_polish.c s21_calcul.c s21_credit_calc.c)
PROJECT = s21_calc

ifeq ($(OS),Linux)
 	OPEN_CMD = open
 	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
 	OPEN_CMD = open
 	ADD_LIB = -lcheck
endif

all: s21_calc.a test

test: s21_calc.a
	gcc $(FLAGS) test.c s21_calc.a -o test $(ADD_LIB)
	./test
  
s21_calc.a:
	gcc -c $(FLAGS) $(FILES) 
	ar rcs s21_calc.a *.o

gcov_report:
	gcc --coverage $(FILES) test.c -o test $(ADD_LIB)
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

brew:
	cd
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
	brew install lcov

clean:
	@rm -f test
	@rm -f *.gc*
	@rm -f s21_test.info
	@rm -rf report
	@rm -f *.o *.a
	@rm -rf test.dSYM
	@rm -rf *.tgz
	@rm -rf view/*.o

style:
	@clang-format -style=Google -i $(FILES) test.c *.h

check:
	@clang-format -style=Google -n $(FILES) test.c *.h


install: uninstall
	mkdir build
	@cd view/ &&qmake && make -j8 && make clean && rm Makefile && mv $(PROJECT).app ../build
	open build

uninstall: clean
	rm -rf build

dvi:
	open Manual.md

dist: clean
	mkdir Smart_Calculate
	mkdir Smart_Calculate/src
	cp -R view Smart_Calculate/src
	cp -R test.c Smart_Calculate/src
	cp -R screenshot Smart_Calculate/src
	cp -R $(FILES) Smart_Calculate/src
	cp -R Makefile Smart_Calculate/src
	cp -R Manual.md Smart_Calculate/src
	tar cvzf Smart_Calculate.tgz Smart_Calculate/
	rm -rf Smart_Calculate

.PHONY: all test s21_calc.a gcov_report clean dist