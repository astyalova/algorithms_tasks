**G. Максимальный путь в дереве**

Ограничение времени	1 секунда  
Ограничение памяти	64Mb  
Ввод	стандартный ввод или input.txt  
Вывод	стандартный вывод или output.txt  

Тимофей устраивает соревнования по спортивному ориентированию в своём офисе. Схема офиса представлена в виде дерева. Посещая каждый пункт, можно зарабатывать или терять очки. Если в узле записано положительное число, это значение добавляется к текущему количеству очков участника. Если отрицательное —– очки вычитаются. Если 
0 –— их количество не меняется.  
Нужно определить, какое максимальное число очков можно заработать, пройдя по пути из какого-то пункта   
A в какой-то (возможно, тот же) пункт B.  
Путь не обязательно должен проходить через корень или содержать лист. Путь должен содержать по крайней мере один узел.  
Требования к решению: передаваемое в качестве аргумента дерево нельзя менять. Не храните вспомогательную информацию в вершинах.

![](G.png)

Формат ввода  
На вход подается корень дерева.  

Формат вывода  
Функция должна вернуть число, равное максимальному количеству очков, которое можно заработать, попав из пункта А в пункт В.  