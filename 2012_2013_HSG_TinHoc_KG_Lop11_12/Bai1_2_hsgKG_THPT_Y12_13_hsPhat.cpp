#include <iostream>
#include <fstream>
using namespace std;
unsigned long long n, tam, chuso,i, ketqua;
bool co,co2;
int main()
{
    ifstream Read("BOISO.INP");
    ofstream Out ("BOISO.OUT");

    Read >> n;
    i=0;
    co=true;
    co2=false;
    while (co2!=true)
    {
        co=true;
        i++;
        tam=i*n;
        while (tam != 0)
        {
            chuso=tam%10;

            if(chuso != 0 && chuso != 1)
            {
                co=false;
                break;
            }

            tam=tam/10;
        }
       if(co==true)
       {
           ketqua=i*n;
          cout << ketqua << endl;
          co2=true;
       }

    }
    return 0;
}
