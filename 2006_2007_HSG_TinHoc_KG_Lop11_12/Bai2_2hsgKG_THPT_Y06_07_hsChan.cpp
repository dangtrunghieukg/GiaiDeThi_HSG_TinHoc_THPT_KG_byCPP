#include <iostream>
#include <fstream>
using namespace std;
int N, tongDienTichCanRao=0;
int M[1001][5];
bool soHCN[101];
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
    }
    if(yChung==false){
        for(int i=yC; i<=yD; i++){
            if(i>=yA && i<=yB){
                yChung=true;
                break;
            }
        }
    }
    if(xChung==true && yChung==true){
    int chieudaiChung=0, chieucaoChung=0;
    if(xC>=xA){
        if(xD>=xB){
            chieudaiChung=abs(xB-xC);
        }else{
            chieudaiChung=abs(xD-xC);
        }
    }else{
        if(xD>xB){
            chieudaiChung=abs(xB-xA);
        }else{
            chieudaiChung=abs(xD-xA);
        }
    }
    if(yC>=yA){
        if(yD>=yB){
            chieucaoChung=abs(yB-yC);
        }else{
            chieucaoChung=abs(yD-yC);
        }
    }else{
        if(xD>xB){
            chieucaoChung= abs(yB-yA);
        }else{
            chieucaoChung=abs(yD-yA);
        }
    }
    return chieudaiChung * chieucaoChung;
    }else return 0;
}
int Max4So(int a, int b, int c, int d){
    int soMax=max(a,b);
    soMax=max(soMax, c);
    soMax=max(soMax, d);
    return soMax;
}
int Min4So(int a, int b, int c, int d){
    int soMin=min(a,b);
    soMin=min(soMin, c);
    soMin=min(soMin, d);
    return soMin;
}
int main(){
    int demHCHchung=0;
    int dtChung;
    ifstream MyReadFile("HR2.INP");
    ofstream MyOutFile("HR2.OUT");
    MyReadFile>>N;
    for(int i=1; i<=N; i++){
        MyReadFile>>M[i][1];
        MyReadFile>>M[i][2];
        MyReadFile>>M[i][3];
        MyReadFile>>M[i][4];
    }
    cout<<N<<endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=4; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;

    }
    for(int i=1; i<N; i++){
        bool okChung=false;
        for(int j=i+1; j<=N; j++){
            dtChung=DienTichChung(M[i][1], M[i][2], M[i][3], M[i][4], M[j][1], M[j][2], M[j][3], M[j][4]);
            if(dtChung>0){
                demHCHchung++;
                okChung=true;
                soHCN[i+1]=true;
                int xMax=Max4So(M[i][1], M[i][3], M[j][1], M[j][3] );
                int yMax=Max4So(M[i][2], M[i][4], M[j][2], M[j][4] );
                int xMin=Min4So(M[i][1], M[i][3], M[j][1], M[j][3] );
                int yMin=Min4So(M[i][2], M[i][4], M[j][2], M[j][4] );
                tongDienTichCanRao+=abs(xMax-xMin)*(yMax-yMin);
                break;
            }
        }
        if(okChung == false && soHCN[i]==false){
            tongDienTichCanRao+=abs(M[i][3]-M[i][1])*abs(M[i][4]-M[i][2]);
        }
        okChung==false;
    }
    cout<<"HCN biet lap: "<<N-demHCHchung<<", S="<<tongDienTichCanRao<<endl;
    MyOutFile<<N-demHCHchung<<", S="<<tongDienTichCanRao<<endl;

MyReadFile.close();
MyOutFile.close();
return 0;
}
