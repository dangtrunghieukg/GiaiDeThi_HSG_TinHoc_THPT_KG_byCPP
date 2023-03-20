#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N, tong, tam, f;

vector <int> vtBCNN;
vector <string> vtDayso;
void findsum(int n, string output)
{
    bool co;
    if (n == 0)
    {
        for (int i=0;i<=output.length();i++)
        {
            co=false;
            if(output[i]!=output[i+1]) co=true;
        }
        if(co==false)
        {
            cout << output << endl;
            vtDayso.push_back(output);
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(output == "")
        {
            findsum(n - i, to_string(i)+output);
        }
        else if (i <= stoi(output.substr(0,1)))
        {
            findsum(n-i, to_string(i)  + output);
        }
    }
}
int UCLN (int x, int y)
{
    int m,kq;
    if(x>y) m=y; else m=x;

    for(int i=m;i>0;--i)
    {
        if (x%i==0 && y%i==0)
        {
            kq =i ;
            break;
        }

    }
return kq;
}
int BCNN(int x, int y)
{
    return (x*y)/UCLN(x,y);
}
int main()
{
    ifstream Read("BOISO.INP");
    ofstream Out("BOISO.OUT");

    Read >> N;
    findsum(N,"");
    /*for (int i=0;i < vtDayso.size();i++)
    {
        string strTemp = "";
        string strTemp_vitri = vtDayso[i]+ " ";
        int iBCNN = 1;
        for(int j=0;j<strTemp_vitri.length();j++)
        {
            if (strTemp_vitri[j] == ' ')
            {
                iBCNN = BCNN(iBCNN, stoi(strTemp));
                strTemp = "";
            }
            else
            {
                strTemp += strTemp_vitri[j];
            }
        }
        vtBCNN.push_back(iBCNN);
    }
    int IBCNN_Max = 1;
    for (int i=0; i < vtBCNN.size();i++)
    {
        if(IBCNN_Max < vtBCNN[i]) IBCNN_Max = vtBCNN[i];
    }
    for(int i=0;i<vtBCNN.size();i++)
    {
        if(IBCNN_Max==vtBCNN[i])
        {
            cout << IBCNN_Max << endl;
            cout << vtDayso[i];
            break;
        }
    } */
    return 0;
}

