#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
void Var(char name[], int a)

{
int kod;
kod=(int)name[0];
int var;
var=kod%a+1;
cout << "\nVariant: " << var;

}
int main(){
char name[20];
int a;
cout << "\nInput your name: ";
cin.getline(name,20);
cout << "Input number of variants: ";
cin >> a;

Var (name, a);
return 0;
}
