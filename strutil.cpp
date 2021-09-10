#include <iostream>
#include <string.h>

int strConteins(char* a, char* str)
{
	int i = 0, j = 0;
	int al = strlen(a);
	int strl = strlen(str);

	while (i<strl)
	{
		if (str[i] == a[0])
		{
			bool e = true;
			for (j=1; j<al; j++)
			{
				
				if (a[j] != str[i])
				{
					e = false;
					break;
				}
				i++;
			}
			if (e)
			return 0;
		}
		i++;
	}
	return -1;
}
