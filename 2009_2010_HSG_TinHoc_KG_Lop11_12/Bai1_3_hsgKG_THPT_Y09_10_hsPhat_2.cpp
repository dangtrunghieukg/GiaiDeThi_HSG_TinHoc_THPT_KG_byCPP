#include <iostream>
#include <fstream>
using namespace std;
int M[9999][9999] ;
int Tanso[101][5]
int tam,i,n,m;
bool co;
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
    (M[i][1]==M[j][1] || M[i][1]==M[j][2] /*&& M[i][2]==M[j][1] || M[i][2]==M[j][2] */  )

    return 0;
}
