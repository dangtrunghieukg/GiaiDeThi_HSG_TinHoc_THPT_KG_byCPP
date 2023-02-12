#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int Mang[1000][5];
int soHCN[1000];
int N, tongDienTichCanRao=0;
int DienTichChung(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD){
    bool xChung=false, yChung=false;
    for(int i=xA; i<=xB; i++){
        if(i>=xC && i<=xD){
            xChung=true;
            break;
        }
    }
    if(xChung==false){
        for(int i=xC; i<=xD; i++){
            if(i>=xA && i<=xB){
                xChung=true;
                break;
            }
        }
    }
    if(xChung==true){
        for(int i=yA; i<=yB; i++){
            if(i>=yC && i<=yD){
                yChung=true;
                break;
            }
        }
        if(yChung==false){
            for(int i=yC; i<=yD; i++){
                if(i>=yA && i<=yB){
                    yChung=true;
                    break;
                }
            }
        }
    }

    if(xChung==true && yChung==true){
        int chieuDaiChung=0, chieuCaoChung=0;
        if(xC>=xA){
            if(xD>=xB){
                chieuDaiChung=abs(xB-xC);
            }else{
                chieuDaiChung=abs(xD-xC);
            }
        }else{
            if(xD>xB){
                chieuDaiChung=abs(xB-xA);
            }else{
                chieuDaiChung=abs(xD-xA);
            }
        }

        if(yC>=yA){
            if(yD>=yB){
                chieuCaoChung=abs(yB-yC);
            }else{
                chieuCaoChung=abs(yD-yC);
            }
        }else{
            if(yD>yB){
                chieuCaoChung=abs(yB-yA);
            }else{
                chieuCaoChung=abs(yD-yA);
            }
        }
        return chieuDaiChung*chieuCaoChung;
    }else{
        return 0;
    }
}

int Max4so(int a, int b, int c, int d){
    int soMax=max(a, b);
    soMax= max(soMax, c);
    soMax= max(soMax, d);
    return soMax;
}

int Min4so(int a, int b, int c, int d){
    int soMin=min(a, b);
    soMin= min(soMin, c);
    soMin= min(soMin, d);
    return soMin;
}

int main(){
    ifstream Read("HR.INP");
    ofstream Out("HR.OUT");

    Read >> N;
    for(int i=1; i<=N; i++){
       for(int j=1; j<5; j++){
            Read >> Mang[i][j];
       }
    }
    int demHCN_Chung=0;
    int dienTichChung=0;
    for(int i=1; i<N; i++){
        bool Chung=false;
        for(int j=i+1; j<=N; j++){
            dienTichChung=DienTichChung(Mang[i][1], Mang[i][2], Mang[i][3],  Mang[i][4], Mang[j][1], Mang[j][2], Mang[j][3], Mang[j][4]);
            if(dienTichChung>0){
                demHCN_Chung++;
                soHCN[i+1]=true;
                int xMax = Max4so(Mang[i][1], Mang[i][3], Mang[j][1], Mang[j][3]);
                int yMax = Max4so(Mang[i][2], Mang[i][4], Mang[j][2], Mang[j][4]);
                int xMin = Min4so(Mang[i][1], Mang[i][3], Mang[j][1], Mang[j][3]);
                int yMin = Min4so(Mang[i][2], Mang[i][4], Mang[j][2], Mang[j][4]);
                tongDienTichCanRao+=abs(xMax-xMin)*abs(yMax-yMin);
                Chung=true;
                break;
            }
        }
        if(Chung==false && soHCN[i]==false){

            tongDienTichCanRao+=abs(Mang[i][3]-Mang[i][1]) * abs(Mang[i][4]-Mang[i][2]);
        }
        Chung=false;
    }
    cout << "HCN biet lap: " << N-demHCN_Chung << ", S= " << tongDienTichCanRao << endl;

    return 0;
}
