Домашняя работа по Алгоритмическим Языкам Сапрыкина В.И, ИУ8-14
Вариант 7 - Система проведения выборов
для справки по командам - внутри программы наберите "man" и нажмите enter

пример последовательности команд:

mkreg reg
add person reg Tomas G
add person reg Mike T
add person reg Line M
add person reg George L
add person reg Kate G
mkreg reg2
add person reg2 Linda G
add person reg2 Lukas T
add person reg2 Mira M
add person reg2 Tima L
add person reg2 Karol G
mkreg reg 3
add person reg2 Xerox K
merge 2>1
listp
list reg
list reg2
add candidate Tomas
listc
start
add candidate Tomas
add candidate Tima
vote Tomas Tomas
vote Mike Tomas
vote Line Tomas
vote George Tomas
vote Kate Tomas
vote Xerox Tima
vote Lukas Tima
vote Karol Tima
listc
stop
stats
save temp.txt
ca
listp
load temp.txt
listp
list reg

Замечание: подразумевается, что имена у всех граждан УНИКАЛЬНЫЕ. Я не стал делать 
идентификаторы каждому гражданину, чтобы не усложнять задание.

содерэание задания (по файлам):
data.txt , temp.txt //файлы с сохраненными состояниями
man.txt //справка
Header.h //заголовочный файл, в нем определены все классы и функции
main.cpp //главный код программы
Person.cpp //файл с реализацией класса Person
Region.cpp //файл с реализацией класса Region
Source.cpp //файл с реализацией функций
split.cpp //реализация split функции
MyException.cpp //реализация класса для обработчика ошибок
