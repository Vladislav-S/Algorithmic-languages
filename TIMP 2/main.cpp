#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <string>
struct heapitem {
	int priority; /* Приоритет элемента */
	char *value; /* Данные */
};
struct heap {
	int maxsize; /* Максимальный размер массива */
	int nitems; /* Количество элементов в куче */
				/* Элементы кучи (хранятся с индекса 1) */
	struct heapitem *items;
};

//создание пустой кучи
struct heap *heap_create(int maxsize)
{
	struct heap *h;
	h = (heap *)malloc(sizeof(*h));
	if (h != NULL) {
		h->maxsize = maxsize;
		h->nitems = 0;
		h->items = (heapitem *)malloc(sizeof(struct heapitem) *
			(maxsize + 1));
		if (h->items == NULL) {
			free(h);
			return NULL;
		}
	}
	return h;
}

//освобождение кучи
void heap_free(struct heap *h)
{
	free(h->items);
	free(h);
}

//поменять элементы местами
void heap_swap(struct heapitem *a,
	struct heapitem *b)
{
	struct heapitem temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//максимальный элемент
struct heapitem heap_max(struct heap *h)
{
	struct heapitem erritem = { -1, NULL };
	if (h->nitems > 0) {
		return h->items[1];
	}
	else {
		fprintf(stderr,
			"heap: Heap is empty.\n");
		return erritem;
	}
}

//вставка элемента
int heap_insert(struct heap *h,
	int priority, char *value)
{
	int i;
	if (h->nitems >= h->maxsize) {
		fprintf(stderr,
			"heap: Heap overflow.\n");
		return -1;
	}
	h->nitems++;
	h->items[h->nitems].priority = priority;
	h->items[h->nitems].value = value;
	/* Продвигаем элемент вверх */
	for (i = h->nitems;
		i > 1 && h->items[i].priority >
		h->items[i / 2].priority;
		i = i / 2)
	{
		heap_swap(&h->items[i], &h->items[i / 2]);
	}
	return 0;
}

//удаление максимального элемента
struct heapitem heap_removemax(struct heap *h)
{
	int k, n, j;
	heap_swap(&h->items[1],
		&h->items[h->nitems]);
	for (k = 1, n = h->nitems - 1; 2 * k <= n;
		k = j)
	{
		j = 2 * k;
		if (j < n && h->items[j].priority <
			h->items[j + 1].priority)
		{
			j++;
		}
		if (h->items[k].priority >=
			h->items[j].priority)
		{
			break;
		}
		heap_swap(&h->items[k], &h->items[j]);
	}
	return h->items[h->nitems--];
}

using namespace std;
int main()
{
	string str;
	string arg;
	int i;
	int ii;

	struct heap *h;
	struct heapitem item;
	cout << "Enter nuber of cells: ";
	int n;
	cin >> n;
	h = heap_create(n);

	cout << "enter command in format: [command] <arg> (type help for more information)" << endl;
	while (true)
	{

		getline(cin, str);
		if (!str.find("add")) {
			int i = str.find(" ");
			arg = str.substr(i + 1, str.length() - i);
			cout << arg << endl;
			ii = atoi(arg.c_str());
			heap_insert(h, ii, "item");
		}
		else if (!str.find("del")) {
			heap_removemax(h);

		}
		else if (!str.find("get")) {
			item = heap_max(h);
			printf("Item: %d\n", item.priority);
		}

		else if (!str.find("exit")) {
			break;
		}
		else if (!str.find("help")) {
			cout << "programm 'tree'\nadd <arg> - add an <arg> in the tree\nget - show and pop the argument\ndel - delete max argument\nhelp - show help \nexit - for exit" << endl;
		}

	}
	
	
	heap_free(h);
	return 0;
}