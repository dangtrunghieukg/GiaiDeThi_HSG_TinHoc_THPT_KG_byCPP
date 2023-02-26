#include <iostream>
#include <fstream>
using namespace std;
int m, n, tam,g;
int Tien[100],Nhan[100], Sl[9999],Ng[9999][9999];
int main()
{
    ifstream Read("ATM.INP");
    ofstream Out ("ATM.OUT");

    Read >> m;
    Read >> n;

    for (int i=1;i<=m;i++)
    {
        Read >> Tien[i];
    }
    for (int i=1;i<=m;i++)
    {

        Read >> Sl[i];
    }

    for (int i=1;i<=n;i++)
    {
        Read >> Ng[i][1] ; Read >> Ng[i][2];
    }


    for (int i=1;i<=n;i++)
    {
        if (Ng[i][1]>Ng[i][2])
        {
            for (int f=1;f<=m;f++)
            {
                cout << "0" << " ";
                Out << "0" << "0";
            }
            cout << endl;
        }
        else
        {
            for (int j=m;j>0;j--)
            {
                tam=Ng[i][1]/Tien[j];
                if (tam <= Sl[j])
                {
                    Ng[i][1]=Ng[i][1]-(tam*Tien[j]);
                    Sl[j]=Sl[j]-tam;
                    Nhan[j]=tam;
                }
                else if (tam > Sl[j])
                {
                    Ng[i][1]=Ng[i][1]-Tien[j]*Sl[j];
                    Nhan[j]=Sl[j];
                    Sl[j]=0 ;
                }
            }
            for (int h=1;h<=m;h++)
                {
                    cout << Nhan[h] << " ";
                    Out << Nhan[h] << " ";
                }
            cout << endl;
        }
    }
    return 0;
}
