#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vtDayso;
int n, dem,vitri,kmax;
string s;
void XuatPhanTich(vector<int> vtInput)
{
    int kq=vtInput[0];
    dem++;
    string chuoiTam = to_string(vtInput[0]);
    for(int i=1;i<vtInput.size();i++)
    {
        chuoiTam = chuoiTam + " " + to_string(vtInput[i]);
        kq*=vtInput[i];
    }

    vtDayso.push_back(chuoiTam);
    if (kmax <kq)
    {
        kmax=kq;
    vitri=dem-1;
    }
}
void PhanTichRaTong(int N, vector<int> vtPT)
{
    if(N==0)
    {
        XuatPhanTich(vtPT);
        return;
    }
    int i=1;
    if(!vtPT.empty())
    {
        i=vtPT.back() +1;
    }
    for(;i<=N;i++)
    {
        vector<int> newVtPT(vtPT);
        newVtPT.push_back(i);
        PhanTichRaTong(N-i, newVtPT);
    }
}

int main()
{
    ifstream Read("PHANTICH.INP");
    ofstream Out ("PHANTICH.OUT");
    Read >> n;
    PhanTichRaTong(n,vector<int>());

    cout << vtDayso[vitri] << endl;


    return 0;
}
