#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int N, a, b;

int USCLN(int x, int y)
{
    int m;
    m=min(x,y);
    for (int i=m;i>0;i--)
    {
        if(x%i==0 && y%i==0)
        {
            return i;
            break;
        }
    }

}
int main ()
{
    ifstream Ip ("USCLN.INP");
    ofstream Op ("USCLN.OUT");

    Ip >> N;

    for(int i=1;i<=N;i++)
    {
        Ip >> a;
        Ip >> b;
        cout << USCLN(a,b);
        Op << USCLN(a,b) << endl;
    }
    return 0;
}
