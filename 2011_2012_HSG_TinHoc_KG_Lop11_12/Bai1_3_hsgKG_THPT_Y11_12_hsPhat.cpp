#include <iostream>
#include <fstream>
using namespace std;
int n, m, tam, ptA, dem;
int D[9999][9999];
int A[999];

bool Tontai(int x)
{
    bool co;
    co=false;
    for(int i=1;i<=ptA;i++)
    {
        if(x==A[i])
        {
            co=true;
            break;
        }
    }

    return co;
}
void sapxep()
{
   int tam;
    for(int i=1;i<=ptA;i++)
    {
        for(int j=1;j<=ptA;j++)
        {
            if (A[i]<A[j])
            {
                tam=A[j];
                A[j]=A[i];
                A[i]=tam;
            }
        }
    }
}
int main()
{
    ifstream Read ("QUANDAO.INP");
    ofstream Out  ("QUANDAO.OUT");

    Read >> n;
    Read >> m;

    for(int i=1;i<=m;i++)
    {
        Read >> D[i][1] ;
        Read >> D[i][2] ;
    }
    tam=1;
    A[1]=D[1][1];
    A[2]=D[1][2];
    ptA=2;
    for(int i=2;i<=m;i++)
    {
        if(Tontai(D[i][1])==true && Tontai(D[i][2])==false)
        {
            ptA++;
            A[ptA]=D[i][2];
        }
        if(Tontai(D[i][2])==true && Tontai(D[i][1])==false)
        {
            ptA++;
            A[ptA]=D[i][1];
        }
        if(Tontai(D[i+1][1])==false && Tontai(D[i+1][2])==false)
        {
            sapxep();
            dem++;
            cout << "Quan dao thu " << dem << ":";
            for(int j=1;j<=ptA;j++)
            cout << A[j] << " ";
            cout << endl;
            for(int j=1;j<=ptA;j++)
                A[j]=0;
            ptA=2;
            A[1]=D[i+1][1];
            A[2]=D[i+1][2];
        }
    }

    return 0;
}
