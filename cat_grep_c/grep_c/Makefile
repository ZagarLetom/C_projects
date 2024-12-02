all: clean linter s21_grep tests	

s21_grep:
	@echo
	@echo Сборка программы:
	gcc -Wall -Werror -Wextra s21_grep.c -o s21_grep

rebuild: clean linter s21_grep

clean:
	clear
	@echo Чистка устаревших файлов:
	rm -f s21_grep report.txt *.log

tests:
	@echo
	@echo "Идёт тестирование (до 5 минут):"
	bash tests.sh 2>/dev/null > report.txt
	@echo
	@echo Тестирование окончено:
	tail -n 5 report.txt

linter:
	@echo
	@echo Проверка исходного кода на соответствие стилю:
	clang-format -n *.c *.h -style=Google
	clang-format -i *.c *.h -style=Google
