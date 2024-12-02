CFLAGS=-Wall -Werror -Wextra -std=c11

all: clean s21_matrix.a
	
clean:
	rm -rf *.a *.o *.gcno *.gcda test main *.css *.html *.gcov main
	clear

test: clean
	gcc $(CFLAGS) s21_test.c -c
	gcc $(CFLAGS) -o test s21_test.o s21_matrix.c --coverage -lcheck -lsubunit -lm
	chmod +x test
	./test

s21_matrix.a:
	gcc $(CFLAGS) s21_matrix.c -c
	ar rc s21_matrix.a s21_matrix.o
#Опция "c" заставляет создавать (от create) библиотеку, если ее нет, \
	а опция "r" (от replace) заменяет старые объектные файлы новыми версиями.
	ranlib s21_matrix.a
#Программа ranlib добавит индекс к архиву и получится полноценная статическая \
	библиотека объектных файлов. Стоит отметить, что на некоторых системах программа ar \
	автоматически создает индекс, и использование ranlib не имеет никакого эффекта. \
	Но тут надо быть осторожным при атоматической компиляции библиотеки с помощью файлов makefile, \
	если вы не будете использовать утилиту ranlib, то возможно на каких-то системах библиотеки будут \
	создаваться не верно и потеряется независимость от платформы. Так что возьмем за правило тот факт, \
	что утилиту ranlib надо запускать в любом случае, даже если он нее нет никакого эффекта.

gcov_report: clean test
	gcov *.gcda
	gcovr
	gcovr --html-details -o report.html

rebuild: all
	
format:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	rm -rfv .clang-format
	clear

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes ./test
#expanded function
vd: clean test
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all -s ./test
#Reachable blocks (those to which a pointer was found) are not shown.
#To see them, rerun with: --leak-check=full --show-leak-kinds=all
#For lists of detected and suppressed errors, rerun with: -s
push: clean format
	git add .
	git commit -m "auto"
	git push origin develop
	clear
