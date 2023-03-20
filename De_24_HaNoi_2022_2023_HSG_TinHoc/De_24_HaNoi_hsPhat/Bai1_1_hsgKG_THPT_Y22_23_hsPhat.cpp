#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int a, b, dem;
bool snt(int x)
{
    bool co=true;
    if(x < 2) co=false;
    else if(x == 2) co=true;
    else if(x > 2)
    {
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                co=false;
                break;
            }
        }
    }
    return co;
}
int main()
{
    ifstream Ip ("CP.INP");
    ofstream Op  ("CP.OUT");

    Ip >> a;
    Ip >> b;

    for(int i=a;i<=b;i++)
    {
        if(snt(sqrt(i))==true && sqrt(i)*sqrt(i)==i)
        {
            dem++;
        }
    }
    cout << dem;
    Op << dem;
    Ip.close();
    return 0;
}
