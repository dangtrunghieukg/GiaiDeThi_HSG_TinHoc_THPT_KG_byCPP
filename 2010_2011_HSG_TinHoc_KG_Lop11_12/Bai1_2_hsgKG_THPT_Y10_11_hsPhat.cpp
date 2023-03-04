#include <iostream>
#include <fstream>
using namespace std;
unsigned long long m, n, tam, chuso, tich, j, h;
int main()
{
    ifstream Read("PN2SND.INP");
    ofstream Out ("PN2SND.OUT");

    Read >> m;
    Read >> n;
    tam=m;
    while (tam !=0 )
    {
        tam/=10;
        j++;
    }

    tam=n;
    for(int i=1;i<=j+1;i++) cout << " ";
    cout <<m << endl;
    for(int i=1;i<=j;i++) cout << " ";
    cout << "x" << endl;
    for(int i=1;i<=j+1;i++) cout << " ";
    cout << n << endl;
    cout << " ";
    for(int i=1;i<=2*j;i++) cout << "-";
    cout << endl;
    h=j;
    while (tam !=0 )
    {
        chuso=tam % 10;
        tich=chuso*m;
        for(int i=1;i<=j;i++)
            cout << " ";
        if(tich==0)
            {
                for(int i=1;i<=h;i++)
                    cout << "0";
                    cout << endl;
            }
        else
        {
            cout << tich << endl;
        }
        tam=tam/10;
        j--;
    }
    cout << " ";
    for(int i=1;i<=2*h;i++) cout << "-";
    cout << endl;
    cout << " "<<m*n;
    return(0);
}
