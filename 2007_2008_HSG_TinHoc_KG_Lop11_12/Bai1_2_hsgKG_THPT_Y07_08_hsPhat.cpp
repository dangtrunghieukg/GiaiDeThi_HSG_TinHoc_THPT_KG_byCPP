#include <iostream>
#include <fstream>
using namespace std;
int N, dem;
int M[99999];
int KQ[99999];
int main()
{
    ifstream Read("HVTT.INP");
    ofstream OUT("HVTT.OUT");

    Read >> N;

    for(int i=1;i<=N;i++)
    {
        Read >> M[i];
    }


     for(int i=1;i<=N;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(M[j]<M[i]) dem++;

        }
        KQ[i]=dem;
        dem=0;
    }

    for (int i=1 ;i<=N;i++)
    {
        cout << KQ[i];
        OUT << KQ[i];
    }

    return 0;
}
