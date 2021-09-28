#include <iostream>


using namespace std;

class Image
{
    int * img;
    int mx;
    int my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy)
    {
        img = new int[mx * my](); 
    }
    virtual ~Image()
    {
        delete[] img;
    }
    int get(int x, int y);
    int set(int x, int y, int color);
    void show();
    Image& operator=(const Image& v)
    {
        int size = v.mx * v.my;
        for (int i = 0; i < size; i++)
        {
            img[i] = v.img[i];
            mx = v.mx;
            my = v.my;
        }
        return *this;
    }
};
int Image::set(int x, int y, int color)
{
    try
    {
        if ((x >= mx) || (y >= my) || (x < 0) || (y < 0))
            throw 204;
        if (mx * my < y * my + x)
            throw 205;
    }
    catch (int error)
    {
        cout << "Error" << endl;
        exit(-1);
    }
    img[y * my + x] = color;
    return color;
}

int Image::get(int x, int y)
{
    try
    {
        if ((x >= mx) || (y >= my) || (x < 0) || (y < 0))
            throw 204;
        if (mx * my < y * my + x)
            throw 205;
    }
    catch (int error)
    {
        cout << "Error" << endl;
        exit(-1);
    }
    return img[y * my + x];
}

void Image::show()
{
    int g;
    for (int i = 0; i < my; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            cout << img[i * my + j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    Image picture(3,2);
    picture.set(0,0,0);
    picture.set(8, 8, 0);
    picture.set(2, 9, 5);
    picture.set(3, 4, 5);
    picture.set(6, 1, 7);
    picture.set(0, 0, 0);
    picture.show();
    picture.get(2, 1);
    Image picture1(3,2);
    picture1 = picture;
    picture1.show();
}

