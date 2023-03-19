#include <iostream>
#include <fstream>
using namespace std;
int arrMang[1001][7];
int arrTanSo[101][5];
int main(){
    ifstream Read("DUONGBO.INP");
    ofstream Print("DUONGBO.OUT");
    int dem=1;
    int m, n;
    Read >> n;
    Read >> m;
    while(!Read.eof()){
        Read >> arrMang[dem][1];
        Read >> arrMang[dem][2];
        dem++;
    }
    //Nhập File.
    //cout << n << " " << m << endl;
    for(int i=1; i<=m; i++){
        arrTanSo[arrMang[i][1]][1]++;
        arrTanSo[arrMang[i][2]][2]++;
        arrTanSo[arrMang[i][1]][3]++;
        arrTanSo[arrMang[i][2]][4]++;
    }
    for(int i=1; i<=m; i++){
        arrMang[i][3]=arrTanSo[arrMang[i][1]][1];
        arrMang[i][4]=arrTanSo[arrMang[i][2]][2];
        arrMang[i][5]=arrTanSo[arrMang[i][2]][3];
        arrMang[i][6]=arrTanSo[arrMang[i][1]][4];
    }
    for(int i=1; i<=m; i++){
        //cout << arrMang[i][1] << " " << arrMang[i][2] << " : " << arrMang[i][3] << " " << arrMang[i][4] << " : " << arrMang[i][5] << " " << arrMang[i][6] << endl;
        if(arrMang[i][3]==1 && arrMang[i][4]==1){
            cout << arrMang[i][1] << " " << arrMang[i][2] << endl;
            Print << arrMang[i][1] << " " << arrMang[i][2] << endl;
        }else if(arrMang[i][5]==0 && arrMang[i][6]==0){
            cout << arrMang[i][1] << " " << arrMang[i][2] << endl;
            Print << arrMang[i][1] << " " << arrMang[i][2] << endl;
        }
    }
    return 0;
}
