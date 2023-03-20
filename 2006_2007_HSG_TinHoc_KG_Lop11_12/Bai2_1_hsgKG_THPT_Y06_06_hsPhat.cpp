#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string s;
int tam,chuso,x, a, b,maxx,temp,demdong;
vector<int> vtXn;
int Tong(int N)
{
int tong;

    while (N!=0)
    {
        chuso=N%10;
        tong+=(chuso*chuso);
        N=N/10;
    }
    return tong;
}
string FXn(int x, int &k)
{
    bool co=false;
    string ketqua="";
    vtXn.clear();
    vtXn.push_back(x);
    while (co!=true)
    {
        x=Tong(x);
        cout <<"";
        for(int i=0;i<vtXn.size();i++)
        {
            if (x==vtXn[i])
            {
                co=true;
                vtXn.push_back(x);
                break;
            }
        }
        if(co==false) vtXn.push_back(x);
    }
    for (int i=0;i<vtXn.size();i++)
    {
        ketqua=ketqua+to_string(vtXn[i])+" ";
    }
    k=vtXn.size();
    return ketqua;
}
int main()
{
    ifstream MyReadFile("TEST.INP");
    ofstream MyOutFile("TEST.OUT");
    MyReadFile >> a;
    MyReadFile >> b;

    for (int i=a;i<=b;i++)
    {
    FXn(i,temp);
    if (maxx < temp ) maxx=temp;
    }

    for (int i=a;i<=b;i++)
    {
    FXn(i,temp);
    if (maxx == temp ) demdong++;
    }

    MyOutFile << maxx << endl;
    MyOutFile << demdong << endl;
    for (int i=a;i<=b;i++)
    {
    FXn(i,temp);
    if (maxx == temp ) MyOutFile << FXn(i,temp) << endl ;
    }
    MyReadFile.close();
return 0;
}
