#include <iostream>
#include <fstream>
using namespace std;
int M[9999][9999] ;
int Tanso[999][999][999][999];
int tam,i,n,m;
bool co1, co2;
int main()
{
    ifstream Read ("DUONGBO.INP");
    ofstream Out  ("DUONGBO.OUT");

    Read >>n;
    Read >>m;

    for (int i=1;i<=m;i++)
    {
        Read >> M[i][1]; Read >> M[i][2];
    }

    for (int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
        if(M[i][1]==M[j][1]) Tanso[i][1] ++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
        if(M[i][2]==M[j][2]) Tanso[i][1] ++;
        }
    }


    for (int i=1;i<=m;i++)
        cout << Tanso[i][2];
    return 0;
}
