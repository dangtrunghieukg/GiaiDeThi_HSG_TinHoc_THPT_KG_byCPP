#include <iostream>
#include <fstream>
int arrTanSo[101][5], Mang[1000001][7];
using namespace std;
int main(){
    ifstream Read("DUONGBO.INP");
    ofstream Out("DUONGBO.OUT");
    int n,m;
    Read>>n;
    Read>>m;
    for(int i=1; i<=m; i++){
        Read>>Mang[i][1];
        Read>>Mang[i][2];
    }
    //cout<<n<<" "<<m<<endl;
    for(int i=1; i<=m; i++){
        //cout << arrTanSo[i][1]<<" "<< arrTanSo[i][2];
        //cout<<endl;
        arrTanSo[Mang[i][1]][1]++;
        arrTanSo[Mang[i][2]][2]++;
        arrTanSo[Mang[i][1]][3]++;
        arrTanSo[Mang[i][2]][4]++;
    }
    for(int i=1; i<=m; i++){
        Mang[i][3]=arrTanSo[Mang[i][1]][1];
        Mang[i][4]=arrTanSo[Mang[i][2]][2];
        Mang[i][5]=arrTanSo[Mang[i][2]][3];
        Mang[i][6]=arrTanSo[Mang[i][1]][4];
    }
    int demTrongYeu=0;
    for(int i=1; i<=m; i++){
        //cout<<Mang[i][1]<<" "<<Mang[i][2]<< " : "<<Mang[i][3]<<" " << Mang[i][4]<< " : "<<Mang[i][5]<<" " << Mang[i][6]<<endl;
        if(Mang[i][3]==1 && Mang[i][4]==1){
            cout<<Mang[i][1]<<" "<<Mang[i][2]<<endl;
            Out<<Mang[i][1]<<" "<<Mang[i][2]<<endl;
            demTrongYeu++;
        }else if(Mang[i][5]==0 && Mang[i][6]==0){
            cout<<Mang[i][1]<<" "<<Mang[i][2]<<endl;
            Out<<Mang[i][1]<<" "<<Mang[i][2]<<endl;
            demTrongYeu++;
        }
    }
    if(demTrongYeu==0){
        cout<<"Khong tim thay con duong trong yeu"<<endl;
    }
Read.close();
Out.close();
return 0;
}
