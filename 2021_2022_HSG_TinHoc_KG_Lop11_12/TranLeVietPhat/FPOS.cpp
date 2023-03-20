#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
string s, s2, x;
int i,m,tam;

int main()
{
    ifstream Ip ("FPOS.INP");
    ofstream Op ("FPOS.OUT");

    getline(Ip,s);
    tam=s.length()/3;

    m=-1;
    //i=pow(10,tam-1);
    i=0;
    while (m<0)
    {
        i++;
        x+=to_string(i);
        m=x.find(s);
    }

    x="";
    i=0;
    while (x.length()<=m)
    {
        i++;
        x+=to_string(i);
    }
    cout  << i;
    Op << i;
    Ip.close();
    return 0;
}
