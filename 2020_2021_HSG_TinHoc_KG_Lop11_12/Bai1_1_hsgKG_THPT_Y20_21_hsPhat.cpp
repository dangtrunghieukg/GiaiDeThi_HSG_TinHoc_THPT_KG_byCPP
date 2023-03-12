#include <iostream>
#include <fstream>
using namespace std;
int N,A;
bool co;
int TongUoc(int x)
{
    int s=0;
    for(int i=(x/2);i>0;i--)
    {
        if(x%i==0) s+=i;
        if(s>x) break;
    }
    return s;
}
int main()
{
    ifstream Read("PERFECT.INP");
    ofstream Out ("PERFECT.OUT");

    Read >> N;

    for(int i=1;i<=N;i++)
    {
        Read >> A;
        co=false;
        for(int j=A;j>0;j--)
        {
            if(TongUoc(j)==j)
            {
                cout << j;
                Out << j << endl;
                co=true;
                break;
            }
        }
        if(co==false) cout << " "  <<endl;
        cout << endl;
    }
    return 0;
}

