#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int arrN[101];
int N, K;
string strTemp = "";
vector<string> vtketqua;
void XuatChuoiNhiPhan()
{
    strTemp="";
    for (int i=1; i<=K;i++)
    {
        strTemp+= to_string(arrN[i]);
    }
    sort(strTemp.begin(), strTemp.end());
    vtketqua.push_back(strTemp);
}

void LietKeChuoiNhiPhan(int i)
{
    for(int j=1; j<=N ;j++)
    {
        arrN[i]=j;
        if(i==K)
        {
            XuatChuoiNhiPhan();
        }
        else
        {
            LietKeChuoiNhiPhan(i+1);
        }
    }
}

int main()
{
    ifstream MyReadFile("MHANG.INP");
    ofstream MyOutFile("MHANG.OUT");

    MyReadFile >> N;
    MyReadFile >> K;

    LietKeChuoiNhiPhan(1);
    sort(vtketqua.begin(), vtketqua.end());
    int demCachchon;
    for (int i=0; i<vtketqua.size();i++)
    {
        if(vtketqua[i] != vtketqua[i+1]) demCachchon++;

    }
    MyOutFile << "Co: " << demCachchon;

    MyReadFile.close();
    return 0;
}
