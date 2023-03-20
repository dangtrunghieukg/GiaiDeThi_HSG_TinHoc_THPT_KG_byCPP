#include <iostream>
#include <fstream>
using namespace std;
int n, f, dem;
int M[9999][9999];
int main()
{
    ifstream Read("PHONGHOP.INP");
    ofstream Out("PHONGHOP.OUT");


    Read >> n;

    for (int i=1;i<=n;i++)
    {
        Read >> M[i][1] ; Read >> M[i][2];
    }
    f=1;
    dem=1;
    for (int i=2;i<=n;i++)
    {
        if(M[i][1]>=M[f][2])
        {
            cout << M[i][1] << " " << M[i][2] << endl;
            f=i;
            dem++;
        }
    }
    Out << dem << endl;
    Out << "1" << " ";
    f=1;
    for (int i=2;i<=n;i++)
    {
        if(M[i][1]>=M[f][2])
        {
            Out << i << " ";
            f=i;
        }
    }
    return 0;
}
