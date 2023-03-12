#include <iostream>
#include <fstream>
using namespace std;
int s, N, f, dem,tam;
int M[9999][9999], K[9999][9999];

int main()
{
    ifstream Read ("GRAP.INP");
    ofstream Out  ("GRAP.OUT");
    Read >> N;
    dem=0;
    while (!(Read.eof()))
        {
         dem++;
         Read >> M[dem][1] ;
         Read >> M[dem][2] ;
        } ;

    K[1][1]=M[1][1];
    K[1][2]=M[1][2];
    f=1;

     for(int i=1;i<dem;i++)
     {
         for(int j=1;j<dem;j++)
         {
            if(M[i][1] < M[j][1] )
            {
                tam=M[i][1];
                M[i][1]=M[j][1];
                M[j][1]=tam;
                tam=M[i][2];
                M[i][2]=M[j][2];
                M[j][2]=tam;
            }
         }
     }


    K[1][1]=M[1][1];
    K[1][2]=M[1][2];
    f=1;
    for(int i=1;i<dem;i++)
    {
        if(M[i][1]>K[f][1] && M[i][2]>=K[f][2] && M[i][2]!=K[f][2])
        {
            f++;
            K[f][1]=M[i][1];
            K[f][2]=M[i][2];
        }
    }
    cout << f << endl;
    Out  << f << endl;
    for (int i=1;i<=f;i++)
        {
            cout << K[i][1] << " " << K[i][2] << endl;
            Out << K[i][1] << " " << K[i][2] << endl;
        }
    return 0;
}
