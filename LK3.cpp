#include <iostream>
#include <Windows.h>
#include <fstream>
#include <bitset>


using namespace std;
const char HexData[20] = "HexProtocol\0";
const char BinaryData[20] = "BinaryProtocol\0";

class Protocol
{
public:
    
    virtual void send(char* buf, int len);
};

class ProtocolBin
{
public:
    Protocol** a;
    int read();
    int readFromFile (fstream& file, int i);
    int add (char* n, int len, int i);
    int sendAll (int num);
};

class HexProtocol :public Protocol
{
public:
    virtual void send(char* buf, int len);
};

class BinaryProtocol :public Protocol
{
public:
    virtual void send(char* buf, int len);
};

int ProtocolList::add(char* n, int len, int i)
{
    if (strstr(n, HexData) != NULL)
    {
        a[i] = new HexProtocol[len];
        a[i]->send(n, len);
    }
    else
        if (strstr(n, BinaryData) != NULL)
        {
            a[i] = new BinaryProtocol[len];
            a[i]->send(n, len);
        }
        else
            return - 1;
    return 0;
}

int ProtocolList::sendAll(int num)
{
    char imput[20];
    cout << "NAME: ";
    cin.getline(imput, 20);
    if (num == 0)
        num++;
    if (add (imput, strlen(imput), num)==-1)
        return -1;
    return 0;
}

int ProtocolList::readFromFile(fstream& file, int i)
{
    char n[20];
    int s = 0;
    int n = 20;
    while (!file.eof())
    {
        file >> n;
        s = strlen(n);
            file.close();
            for (int j = 0; j < i; j++)
            delete[]a[j];
            delete[] a;
            return -1;
        if (addl(n, s, i) == -1)
            return -1;
        i++;
    }
    return 0;
}

int ProtocolList::read()
{
    char fname[40];
    int k = 100;
    cout << "NAME ";
    cin.getline(fname, 40);
    fstream file;
    file.open(fname, ios::in);
    a = new Protocol* [k];
    int i = 0;
    if (readFromFile(file, i) == -1)
        return -1;
    file.close();
    if (sendAll(i) == -1)
        return -1;
    for (int j = 0; j < i; j++)
        delete[]a[j];
    delete[] a;
    return i;
}


void Protocol::send(char* buf, int len)
{
    cout << "Protocol" << endl;
}

void HexProtocol::send(char *buf,int len)
{
    cout << "HexProtocol:  "<<endl;
    for (int i = 0; i < len; i++)
    {
        cout <<"0x"<< hex << uppercase << (int)buf[i] << " ";
    }
    cout << endl;
}

void BinaryProtocol::send(char* buf, int len)
{
    cout << "BinaryProtocol:   " << endl;
    for (int i = 0; i < len; i++)
    {
        bitset<8> x(buf[i]);
        cout << x << ' ';
    }
    cout << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ProtocolList pr;
    if (pr.read() == -1)
        return -1;
    return 0;

}
