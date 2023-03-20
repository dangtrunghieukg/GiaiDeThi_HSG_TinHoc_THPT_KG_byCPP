#include <iostream>
#include <fstream>
using namespace std;
int n, x, dem;
int main()
{
    ifstream Ip ("BS.INP");
    ofstream Op ("BS.OUT");

    Ip >> n;
    Ip >> x;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(i*j==x) dem++;
    }

    cout << dem;
    Op << dem;
    return 0;
}
