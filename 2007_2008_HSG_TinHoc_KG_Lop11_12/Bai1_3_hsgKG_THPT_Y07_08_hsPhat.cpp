#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N,vitri,ddmax,tong,dodai;
int M[99999];

int main()
{
    ifstream Read("DTDDNHAT.INP");
    ofstream Out("DTDDNHAT.OUT");

    Read >> N;

    for (int i=0;i<N;i++)
    {
        Read >> M[i];
    }

    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
        tong+=M[j];
        if(tong >0) dodai=j-i+1;
        if(ddmax < dodai) ddmax=dodai;
        }
        tong=0;
        dodai=0;
    }
    cout << ddmax << endl;
    Out << ddmax << endl;
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
        tong+=M[j];
        if(tong >0) dodai=j-i+1;
        if(ddmax == dodai)
        {
            cout << i+1 << endl;
            cout << j+1 << endl;
            Out << i+1 <<endl;
            Out << j+1 << endl;
            break;
        }
        }
        tong=0;
        dodai=0;
    }

    return 0;
}
