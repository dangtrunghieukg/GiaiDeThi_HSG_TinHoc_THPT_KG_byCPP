#include <iostream>
#include <fstream>
using namespace std;
int a, b, c, x, y, z, minn;
int main()
{
    ifstream Ip ("PMIN.INP");
    ofstream Op ("PMIN.OUT");

    Ip >> a;
    Ip >> b;
    Ip >> c;
    x=a;
    y=b;
    minn=c*2;
    while (x*y<=c)
    {
        x++;
        if(x*y>=c)
        {
           minn=min(x*y,minn);
        }
    }

    x=a;
    y=b;
    while (x*y<=c)
    {
        y++;
        if(x*y>=c)
        {
           minn=min(x*y,minn);
        }
    }

    cout << minn;
    Op << minn;
    Ip.close();
    return 0;
}
