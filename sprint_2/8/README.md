**H. Скобочная последовательность**

Ограничение времени	0.1 секунда

Ограничение памяти 64Mb

Ввод стандартный ввод или input.txt

Вывод стандартный вывод или output.txt

Вот какую задачу Тимофей предложил на собеседовании одному из кандидатов. Если вы с ней ещё не сталкивались, то наверняка столкнётесь –— она довольно популярная.

Дана скобочная последовательность. Нужно определить, правильная ли она.

Будем придерживаться такого определения:

пустая строка —– правильная скобочная последовательность;

правильная скобочная последовательность, взятая в скобки одного типа, –— правильная скобочная последовательность;

правильная скобочная последовательность с приписанной слева или справа правильной скобочной последовательностью —– тоже правильная.

На вход подаётся последовательность из скобок трёх видов: [], (), {}.
Напишите функцию is_correct_bracket_seq, которая принимает на вход скобочную последовательность и возвращает True, если последовательность правильная, а иначе False.

Формат ввода
На вход подаётся одна строка, содержащая скобочную последовательность. Скобки записаны подряд, без пробелов.

Формат вывода
Выведите «True» или «False».

