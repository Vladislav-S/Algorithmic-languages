�������� ������ �� ��������������� ������ ��������� �.�, ��8-14
������� 7 - ������� ���������� �������
��� ������� �� �������� - ������ ��������� �������� "man" � ������� enter

������ ������������������ ������:

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

���������: ���������������, ��� ����� � ���� ������� ����������. � �� ���� ������ 
�������������� ������� ����������, ����� �� ��������� �������.

���������� ������� (�� ������):
data.txt , temp.txt //����� � ������������ �����������
man.txt //�������
Header.h //������������ ����, � ��� ���������� ��� ������ � �������
main.cpp //������� ��� ���������
Person.cpp //���� � ����������� ������ Person
Region.cpp //���� � ����������� ������ Region
Source.cpp //���� � ����������� �������
split.cpp //���������� split �������
MyException.cpp //���������� ������ ��� ����������� ������
