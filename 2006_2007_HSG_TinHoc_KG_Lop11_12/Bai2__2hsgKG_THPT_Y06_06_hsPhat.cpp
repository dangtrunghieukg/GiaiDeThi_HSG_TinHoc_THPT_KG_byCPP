#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int M[1000][5];
int N;
bool SoHCN[1001];
int tongDienTichCanRao=0,demHCN;
int DienTichChung(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD){
    bool xChung = false, yChung = false;
    for(int i=xA; i<=xB; i++){
        if(i>=xC && i<=xD){
            xChung = true;
            break;
        }
    }
    if(xChung==false){
        for(int i=xC; i<=xD; i++){
            if(i>=xA && i<=xB){
                xChung = true;
                break;
            }
        }
    }
    if(xChung==true){
        for(int i=yA; i<=yB; i++){
            if(i>=yC && i<=yD){
                yChung = true;
                break;
            }
        }
        if(yChung==false){
            for(int i=yC; i<=yD; i++){
                if(i>=yA && i<=yB){
                    yChung = true;
                    break;
                }
            }
        }
    }
    if(xChung==true && yChung==true){
        int chieuDaiChung=0, chieuCaoChung=0;
        if(xC>=xA){
            if(xD>=xB){
                chieuDaiChung = abs(xB-xC);
            }else{
                chieuDaiChung = abs(xD-xC);
            }
        }else{
            if(xD>xB)
            {
                chieuDaiChung = abs(xB-xA);
            }
            else
            {
                chieuDaiChung = abs(xD-xA);
            }
        }

        if(yC>=yA)
        {
            if(yD>=yB)
            {
                chieuCaoChung = abs(yB-yC);
            }
            else
            {
                chieuCaoChung = abs(yD-yC);
            }
        }
        else
        {
            if(yD>yB)
            {
                chieuCaoChung = abs(yB-yA);
            }
            else
            {
                chieuCaoChung = abs(yD-yA);
            }
        }
        return chieuDaiChung * chieuCaoChung;
    }else return 0;
}
int DienTichBietLap(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD)
{
    int xmin,ymin,xmax,ymax,chieuDai,chieuRong, S;
    xmin=min(xA,xB);
    xmin=min(xmin,xC);
    xmin=min(xmin,xD);

    ymin=min(yA,yB);
    ymin=min(ymin,yC);
    ymin=min(ymin,yD);

    xmax=max(xA,xB);
    xmax=max(xmax,xC);
    xmax=max(xmax,xD);

    ymax=max(yA,yB);
    ymax=max(ymax,yC);
    ymax=max(ymax,yD);

    chieuDai=abs(xmax-xmin);
    chieuRong=abs(ymax-ymin);

    S=chieuDai*chieuRong;
    return S;
}
int main ()
{
    ifstream MyReadFile("HR2.INP");
    ofstream MyOutFile("HR.OUT");

    MyReadFile >> N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=4;j++)
        {
            MyReadFile >> M[i][j];
        }
    }
      for(int i=1;i<N;i++)
    {
        bool okChung = false;
        for (int j=i+1;j<=N;j++)
        {
        if (j==i) continue;
        else
        {
        if(DienTichChung(M[i][1],M[i][2],M[i][3],M[i][4],M[j][1],M[j][2],M[j][3],M[j][4])>0)
        {
        tongDienTichCanRao+=DienTichBietLap(M[i][1],M[i][2],M[i][3],M[i][4],M[j][1],M[j][2],M[j][3],M[j][4]);
        demHCN++;
        okChung = true;
          SoHCN[i+1] = true;
        break;
        }
        }
        }
        if(okChung == false && SoHCN[i]==false){
            tongDienTichCanRao += abs(M[i][3]-M[i][1])*abs(M[i][4]-M[i][2]);
        }
        okChung = false;
    }
    MyOutFile << N-demHCN << " ";

    MyOutFile << tongDienTichCanRao;
    MyReadFile.close();
return 0;
}
