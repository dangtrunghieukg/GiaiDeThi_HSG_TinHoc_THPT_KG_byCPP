#include <iostream>
#include <fstream>
using namespace std;
int Hw[9999][9999];
int Htong, Hke, Lke, N, L, H, tam;
int main()
{
    ifstream Ip ("KESACH.INP");
    ofstream Op ("KESACH.OUT");

    Ip >> N;
    Ip >> L;

    for(int i=1;i<=N;i++)
    {
        Ip >> Hw[i][1];
        Ip >> Hw[i][2];
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(Hw[i][2]>Hw[j][2])
            {
                tam=Hw[i][1];
                Hw[i][1]=Hw[j][1];
                Hw[j][1]=tam;

                tam=Hw[i][2];
                Hw[i][2]=Hw[j][2];
                Hw[j][2]=tam;
            }
        }
    }

    Hke=0;
    Lke=0;

    for(int i=1;i<=N;i++)
    {
        if(Lke+Hw[i][2]<=L)
        {
            Lke+=Hw[i][2];
            Hke=max(Hke,Hw[i][1]);
        }
        if(Lke+Hw[i+1][2] > L)
        {
            Htong+=Hke;
            Hke=0;
            Lke=0;
        }
    }
    Htong+=Hke;

    cout << Htong;
    Op << Htong;

    Ip.close();
    return 0;
}
