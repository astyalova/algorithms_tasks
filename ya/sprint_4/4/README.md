**D. Полиномиальный хеш**

Ограничение времени	0.5 секунд  
Ограничение памяти	64Mb  
Ввод стандартный ввод или input.txt  
Вывод стандартный вывод или output.txt  

Алле очень понравился алгоритм вычисления полиномиального хеша. Помогите ей написать функцию, вычисляющую хеш строки s. В данной задаче необходимо использовать в качестве значений отдельных символов их коды в таблице ASCII.  

Полиномиальный хеш считается по формуле:  
![alt text](https://contest.yandex.ru/testsys/tex/render/aChzKSA9IChzXzFhXntuLTF9ICsgc18yYV57bi0yfSArIFxkb3RzICsgc197bi0xfWEgKyBzX3tufSkgXCBtb2QgXCBt.png)

Формат ввода
В первой строке дано число a (1 ≤ a ≤ 1000) –— основание, по которому считается хеш.

Во второй строке дано число m (1 ≤ m ≤ 109) –— модуль.

В третьей строке дана строка s (0 ≤ |s| ≤ 106), состоящая из больших и маленьких латинских букв.

Формат вывода
Выведите целое неотрицательное число –— хеш заданной строки.