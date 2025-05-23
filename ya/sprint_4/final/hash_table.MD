**B. Хеш-таблица**
Ограничение времени	5 секунд  
Ограничение памяти	64Mb  
Ввод стандартный ввод или input.txt  
Вывод стандартный вывод или output.txt  

Тимофей, как хороший руководитель, хранит информацию о зарплатах своих сотрудников в базе данных и постоянно её обновляет. Он поручил вам написать реализацию хеш-таблицы, чтобы хранить в ней базу данных с зарплатами сотрудников.  
 
Хеш-таблица должна поддерживать следующие операции:   

put key value —– добавление пары ключ-значение. Если заданный ключ уже есть в таблице, то соответствующее ему значение обновляется.   
get key –— получение значения по ключу. Если ключа нет в таблице, то вывести «None». Иначе вывести найденное значение.   
delete key –— удаление ключа из таблицы. Если такого ключа нет, то вывести «None», иначе вывести хранимое по данному ключу значение и удалить ключ.  
В таблице хранятся уникальные ключи.  

Требования к реализации:   

Нельзя использовать имеющиеся в языках программирования реализации хеш-таблиц (std::unordered_map в С++, dict в Python, HashMap в Java, и т. д.)  
Разрешать коллизии следует с помощью метода цепочек или с помощью открытой адресации.  
Все операции должны выполняться за O(1) в среднем.  
Поддерживать рехеширование и масштабирование хеш-таблицы не требуется.  
Ключи и значения, id сотрудников и их зарплата, —– целые числа. Поддерживать произвольные хешируемые типы не требуется.  

Формат ввода  
В первой строке задано общее число запросов к таблице n (1≤ n≤ 106).  

В следующих n строках записаны запросы, которые бывают трех видов –— get, put, delete —– как описано в условии.  

Все ключи и значения –— целые числа, не превосходящие 109 по модулю. Числа могут быть и отрицательными в том числе.  

При любой последовательности команд, количество ключей в хеш-таблице не может превышать 105.  

Формат вывода  
На каждый запрос вида get и delete выведите ответ на него в отдельной строке.  