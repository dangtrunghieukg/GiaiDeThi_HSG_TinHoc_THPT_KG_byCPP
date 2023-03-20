#include <iostream>
#include <fstream>
using namespace std;
string s, x;
int N, maxx,dai;
bool Doixung(string m)
{
    bool co=true;
    for(int i=0;i<=(m.length())/2;i++)
    {
        if(m[i] != m[(m.length())-i-1])
        {
            co=false;
            break;
        }
    }
    return co;
}
int main()
{
    ifstream Ip ("CHUOI.INP");
    ofstream Op ("CHUOI.OUT");

    Ip >> N;
    getline(Ip,s);
    getline(Ip,s);

    for(int i=0;i<s.length();i++)
    {
        x="";
        x+=s[i];
        for(int j=i+1;j<s.length();j++)
        {
            x+=s[j];
            dai=x.length();
            if(Doixung(x)==true)
            {
                maxx=max(maxx,dai);
            }
        }
    }
    cout << maxx;
    Op << max;
    return 0;
}
