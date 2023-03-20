#include <iostream>
#include <fstream>
using namespace std;
int N, s,s1,s2;
int A[9999];
int main()

{
    ifstream Ip ("CT.INP");
    ofstream Op ("CT.OUT");

    Ip >> N;

    for(int i=1;i<=N;i++)
    {
        Ip >> A[i];
        s+=A[i];
    }

    if(s%2==0) s=s/2;

    for(int i=1;i<=N;i++)
    {

    }


    return 0;
}
