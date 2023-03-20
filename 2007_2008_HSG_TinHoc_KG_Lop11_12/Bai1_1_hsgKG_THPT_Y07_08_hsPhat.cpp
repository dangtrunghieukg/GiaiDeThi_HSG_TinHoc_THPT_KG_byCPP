#include <iostream>
#include <fstream>
using namespace std;
int arrTs[10];
int PhepBD[10000], DaySo[10000];
int MaTranKQ[4][4];
int demday,demphep,dem;
string strLine1,strLine2;
void BienDoi(int x)
{
    switch (x)
    {
    case 1:
        for (int i=1;i<=3;i++)
        {
            MaTranKQ[1][i]+=2*MaTranKQ[2][i];
        }
        break;
    case 2:
         for (int i=1;i<=3;i++)
        {
            MaTranKQ[2][i]+=2*MaTranKQ[3][i];
        }
        break;
    case 3:
         for (int i=1;i<=3;i++)
        {
            MaTranKQ[3][i]+=2*MaTranKQ[1][i];
        }
        break;
    case 4:
         for (int i=1;i<=3;i++)
        {
            MaTranKQ[i][1]+=2*MaTranKQ[i][2];
        }
        break;
    case 5:
         for (int i=1;i<=3;i++)
        {
            MaTranKQ[i][2]+=2*MaTranKQ[i][3];
        }
        break;
    case 6:
         for (int i=1;i<=3;i++)
        {
            MaTranKQ[i][3]+=2*MaTranKQ[i][1];
        }
        break;
    }
}
int main()
{
    ifstream MyReadFile("BDMATRAN.INP");
    ofstream MyOutFile("BDMATRAN.OUT");

    getline(MyReadFile,strLine1);
    getline(MyReadFile,strLine2);

    for (int i=0;i<strLine1.length();i++)
    {
        if (strLine1[i] != ' ')
        {
            demphep++;
            PhepBD[demphep]=char16_t(strLine1[i])-48;
        }
    }
    demday=0;
    for (int i=0;i<strLine2.length();i++)
    {
        if (strLine2[i] != ' ')
        {
            demday++;
            DaySo[demday]=char16_t(strLine2[i])-48;
        }
    }
    for (int i=1;i<=demday;i++)
    {
        arrTs[DaySo[i]]++;
    }

    for (int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
    {
        dem++;
        MaTranKQ[i][j]=arrTs[dem];
    }

    cout << "Ma Tran Ban Dau: " << endl;
    MyOutFile << "Ma Tran Ban Dau: " << endl;
    for (int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
    {

       MyOutFile << MaTranKQ[i][j] << " ";
       cout << MaTranKQ[i][j] << " ";
    }
     MyOutFile  << endl;
     cout << endl;
    }

    cout << "Ma Tran Ket Qua: " << endl;
    MyOutFile << "Ma Tran Ket Qua: " << endl;
    for (int f=1;f<=demphep;f++)
    {
     BienDoi(PhepBD[f]);
    }

    for (int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
    {
        MyOutFile << MaTranKQ[i][j] << " ";
        cout << MaTranKQ[i][j] << " ";
    }
    MyOutFile << endl;
    cout << endl;
    }
    return 0;
}
