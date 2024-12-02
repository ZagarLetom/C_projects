all: clean linter s21_cat tests	

s21_cat:
	@echo
	@echo Сборка программы:
	gcc -Wall -Werror -Wextra s21_cat.c -o s21_cat

rebuild: clean linter s21_cat

clean:
	clear
	@echo Чистка устаревших файлов:
	rm -f s21_cat report.txt *.log

tests:
	@echo
	@echo "Идёт тестирование (до 1 минуты):"
	bash tests.sh 2>/dev/null > report.txt
	@echo
	@echo Тестирование окончено:
	tail -n 5 report.txt

linter:
	@echo
	@echo Проверка исходного кода на соответствие стилю:
	clang-format -n *.c *.h -style=Google
	clang-format -i *.c *.h -style=Google
