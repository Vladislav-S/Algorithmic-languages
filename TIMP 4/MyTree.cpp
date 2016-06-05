// tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void straight(int i, int* a, int n)
{
	for (int j = 0; j<n; j++)
		if (a[j] == i)
		{
			cout << j << " ";
			straight(j, a, n);
		}
}


void back(int i, int* a, int n)
{
	for (int j = 0; j<n; j++)
		if (a[j] == i)
		{
			back(j, a, n);
		}
	if (i != -1) cout << i << " ";
}

void symmetry(int i, int* a, int n)
{
	int x = 0;
	for (int j = 0; j<n; j++)
		if (a[j] == i)
		{
			symmetry(j, a, n);
			if ((!x) && (i != -1)) cout << i << " ";
			x++;
		}
	if (x == 0)
	{
		cout << i << " ";
	}
}


int main()
{
	int n;
	cin >> n;
	int* tree = new int[n];
	for (int i = 0; i<n; i++)
		cin >> tree[i];

	straight(-1, tree, n);
	cout << endl;

	back(-1, tree, n);
	cout << endl;

	symmetry(-1, tree, n);
	cout << endl;

	system("pause");

	delete[] tree;
	return 0;
}

