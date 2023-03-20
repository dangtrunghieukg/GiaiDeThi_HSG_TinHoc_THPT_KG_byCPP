#include <iostream>
#include <fstream>
using namespace std;
int N, k, tam,spt, f, l, dem;
int M[9999999];
int main()

{
    ifstream Read("DEMNGUOI.INP");
    ofstream Out("DEMNGUOI.OUT");

    Read >> N;
    Read >> k;

    for (int i=1;i<=N;i++)
    {
        M[i]=i;
    }


    spt=N;

    while (spt >1)
    {
        f++;
        l++;
        if(f==k)
        {
            for(int i=l;i<spt+1;i++ )
            {
                M[i]=M[i+1];
            }
            spt--;
            l--;
            f=0;
           /* for(int i=1;i<=spt;i++)
            {
                cout << M[i] << " ";
            }
            cout<< endl; */
        }
        if( l==spt) l=0;
    }
    cout << M[1] << " ";
    Out << M[1] << " ";

    Read.close();
    return 0;
}
