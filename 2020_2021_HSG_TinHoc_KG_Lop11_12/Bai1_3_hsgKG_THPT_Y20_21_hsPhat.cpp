#include <iostream>
#include <fstream>
using namespace std;
int N, d, time, maxx, tmax, s, spt, kemax;
int t[9999];
int z[9999];
int kq[999];
bool co;
int main()
{
    ifstream Read  ("AMUSIC.INP");
    ofstream Out   ("AMUSIC.OUT");

    Read >> N; Read >> d;
    for(int i=1;i<=N;i++)
        Read >> t[i];

    for(int i=1;i<=N;i++)
        Read >> z[i];
    time=0;
    for(int i=1;i<=N;i++)
        if (tmax < t[i]) tmax=t[i];

    while(time < tmax)
    {
        time++;
        maxx =0;
        co=false;
        for(int i=1;i<=N;i++)
        {
            if(t[i]==time)
            {
                if(maxx < z[i])
                {
                    maxx=z[i];
                    spt++;
                    kq[spt]=i;
                }
            }
        }
    s+=maxx;
    cout << kq[spt] << endl;
    }
    cout << s;
    return 0;
}

