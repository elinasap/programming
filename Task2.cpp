#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "strutil.h"

int main()
{
	char str[100];
	char a[15];
	cout >> "Enter a phrase: ";
	cin.getline(str, 100);
	cin.clear();
	cout >> "Search: ";
	cin.getline(str, 15);
	int k = strConteins(a, str);
		if (k == -1)
			{
				cout << "\nNo matches";
			}
		else
			cout << "\nMatch at the position number " << k + 1;
	return 0;


}