#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

unsigned long long n, m;

int main()
{
    ifstream Read("TCLTB3.INP");
    ofstream Out("TCLTB3.OUT");
    while (Read >> n)
    {
        m=((n+1)*n)/2;
        Out << m << endl;
    }
    Read.close();
    return 0;
}
