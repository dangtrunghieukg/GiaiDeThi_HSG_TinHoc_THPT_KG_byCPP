#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int M[101][5];
bool SoHCN[101];
int N, tongDienTichCanRao=0;
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
            if(xD>xB){
                chieuDaiChung = abs(xB-xA);
            }else{
                chieuDaiChung = abs(xD-xA);
            }
        }

        if(yC>=yA){
            if(yD>=yB){
                chieuCaoChung = abs(yB-yC);
            }else{
                chieuCaoChung = abs(yD-yC);
            }
        }else{
            if(yD>yB){
                chieuCaoChung = abs(yB-yA);
            }else{
                chieuCaoChung = abs(yD-yA);
            }
        }
        return chieuDaiChung * chieuCaoChung;
    }else return 0;
}
int Max4So(int a, int b, int c, int d){
    int soMax = max(a,b);
    soMax = max(soMax,c);
    soMax = max(soMax,d);
    return soMax;
}
int Min4So(int a, int b, int c, int d){
    int soMin = min(a,b);
    soMin = min(soMin,c);
    soMin = min(soMin,d);
    return soMin;
}
int main(){
    ifstream MyReadFile("HR.INP");
    ofstream MyOutFile("HR.OUT");
    MyReadFile >> N;
    for(int i=1; i<=N; i++){
        MyReadFile >> M[i][1] >> M[i][2] >> M[i][3] >> M[i][4];
    }
    cout << N << endl;
    for(int i=1; i<=N; i++){
        cout << M[i][1] << " " << M[i][2] << " " << M[i][3] << " " << M[i][4] << endl;
    }
    int demHCN_Chung = 0;
    int dienTichChung;
    for(int i=1; i<N; i++){
        bool okChung = false;
        for(int j=i+1; j<=N; j++){
            dienTichChung =  DienTichChung(M[i][1], M[i][2], M[i][3], M[i][4], M[j][1], M[j][2], M[j][3], M[j][4]);
            if( dienTichChung > 0 ){
                demHCN_Chung++;
                okChung = true;
                SoHCN[i+1] = true;
                int xMax = Max4So (M[i][1], M[i][3], M[j][1], M[j][3]);
                int yMax = Max4So (M[i][2], M[i][4], M[j][2], M[j][4]);
                int xMin = Min4So (M[i][1], M[i][3], M[j][1], M[j][3]);
                int yMin = Min4So (M[i][2], M[i][4], M[j][2], M[j][4]);
                tongDienTichCanRao += abs(xMax - xMin)*abs(yMax - yMin);
                break;
            }
        }
        if(okChung == false && SoHCN[i]==false){
            tongDienTichCanRao += abs(M[i][3]-M[i][1])*abs(M[i][4]-M[i][2]);
        }
        okChung = false;
    }
    cout << "HCN biet lap: " << N - demHCN_Chung << ", S = "<< tongDienTichCanRao << endl;
    MyOutFile << N - demHCN_Chung;
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}