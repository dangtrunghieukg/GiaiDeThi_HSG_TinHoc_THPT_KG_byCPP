#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int M[9];
int chuso, tam, ptM, m;
string x;
int NhiPhan(int X[9])
{
    int m=0;
    int tong=0;
    for(int i=7;i>1;i--)
    {
        tong+=X[i]*pow(2,m);
        m++;
    }
    if(M[0]==1 && tong > 0) tong*=-1;
        else if(M[0]==1 && tong < 0) tong*=1;
            else if(M[0]==0 && tong <0) tong*=-1;
                else tong*=1;
    return tong;
}
int main()
{
    ifstream Ip ("GIAIMA.INP");
    ofstream Op ("GIAIMA.OUT");

    while (!Ip.eof())
    {
    x="";
    Ip >> x;
    for(int i=0;i<8;i++)
    {
        M[i]=char16_t(x[i]-48);
    }
    cout << NhiPhan(M) << endl;
    Op << NhiPhan(M) << endl;
    }
    return 0;
}
