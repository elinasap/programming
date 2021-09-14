﻿#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std; 

class FooString
{
	char* buf;
	int len;
public:
	FooString(char* tbuf)
	{
	    len = strlen(tbuf) + 1;
		buf = new char[len];
		for (int i = 0; i < len; i++)
			buf[i] = tbuf[i];
	}
	~FooString()
	{
		delete[] buf;
	}
	
	void Show()
	{
	cout << buf << endl;
	}
	bool Compare(FooString str)
	{
		if (str.len != len)
		{
			for (int i = 0; i < len; i++)
			{
				if (buf[i] != str.buf[i])
				{
					return false;
				}
			} 
			return true;
		} 
		return false;
	}
	int Test()
	{
		char str1[] = "Test";
		char str2[] = "Test";
		char str3[] = "No";
		FooString a(str1);
		FooString b(str2);
		FooString c(str3);
		if ((a.Compare(b) == true) && (a.Compare(c) == false))
		{
			cout << "OK";
			return 0;
		}
		else
		{
			cout << "NOT OK";
			return -1;
		}

	}
};

int main()
{
	char e[] = "Test";
	FooString h(e);
	h.Show();
	h.Test();
}
