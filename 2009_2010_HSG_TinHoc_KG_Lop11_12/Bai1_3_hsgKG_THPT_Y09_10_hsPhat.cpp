#include <iostream>
#include <fstream>
using namespace std;
int M[999][999] ;
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

     for (int i=1;i<=m;i++)
    {
        co=false;
        for (int j=1;j<=m;j++)
        {
           if (i==j)  continue ;
            else if(M[i][1]==M[j][1] || M[i][1]==M[j][2] && M[i][2]==M[j][1] || M[i][2]==M[j][2]  )
                {
                    co=true;
                    break;
                }
        }
        if (co==false ) cout << M[i][1] << " " << M[i][2] << endl;
    }
    return 0;
}
