#include <iostream>
#include <fstream>
using namespace std;
int N, a, b,tam, ps, dem,vitri, ptF;
float tem, psKiem;
float  M[2000];
float  F[200];
string Read;
bool co;

int main ()
{
    co=false;
    tam=0;
    ifstream MyReadFile("PHANSO.INP");
    ofstream MyOutFile("PHANSO.OUT");

    MyReadFile >> N;
    MyReadFile >> a;
    MyReadFile >> b;

    for (int i=N;i>1;i--)
    {
        for (int j=1;j<i;j++)
        {
                tam++;
                M[tam]=(float)j/i;
        }
    }
    for (int i=1;i<=tam;i++)
    {
        for(int j=1;j<=tam;j++)
        {
            if (M[i]>M[j])
            {
            tem=M[i];
            M[i]=M[j];
            M[j]=tem;
            }
        }

    }

    psKiem=(float)a/b;
    for (int i=1;i<=tam;i++)
    {
    if (M[i] != M[i+1])
    {
    ptF++;
    F[ptF]=M[i];
    }
    }

    for (int i=1;i<=ptF;i++)
    if (F[i]==psKiem) vitri=i;

    cout << vitri;

    MyOutFile << vitri;
    MyReadFile.close();


    return 0;
}
