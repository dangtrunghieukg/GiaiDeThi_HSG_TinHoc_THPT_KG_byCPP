#include <iostream>
#include <fstream>

using namespace std;

void Bien_Doi(int x);

int arrPhepBienDoi[1000];
int arrSoNhapVao[1000000];
int arrTanSo[10];
int arrBanDau[4][4];
int arrKetQua[4][4];
int main(){
    ifstream Read("BDMATRAN.INP");
    ofstream Out("BDMATRAN.OUT");
    string line1="";
    string line2="";
    getline(Read, line1); getline(Read, line2);
    line1+=" ";
    line2+=" ";
    string strTemp="";
    int demPBD=0;
    for(int i=0; i<line1.length(); i++){
        if(line1[i]!=' '){
            strTemp+=line1[i];
        }else{
            arrPhepBienDoi[demPBD]=stoi(strTemp);
            strTemp="";
            demPBD++;
        }
    }
    int demSNV=0;
    for(int i=0; i<line2.length(); i++){
        if(line2[i]!=' '){
            strTemp+=line2[i];
        }else{
            arrSoNhapVao[demSNV]=stoi(strTemp);
            strTemp="";
            demSNV++;
        }
    }

    for(int i=0; i<demSNV; i++){
        arrTanSo[arrSoNhapVao[i]]++;
    }
    int dem=1;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            arrBanDau[i][j]=arrTanSo[dem];
            arrKetQua[i][j]=arrTanSo[dem];
            dem++;
        }
    }

     for(int i=0; i<=demPBD; i++){
        Bien_Doi(arrPhepBienDoi[i]);
    }
    cout << "Ma tran ban dau: " << endl;
    Out << "Ma tran ban dau: " << endl;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout << arrBanDau[i][j] << " ";
            Out << arrBanDau[i][j] << " ";
        }
        cout << endl;
        Out << endl;
    }
    cout << "Ma tran ket qua: " << endl;
    Out <<  "Ma tran ket qua: " << endl;
      for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout << arrKetQua[i][j] << " ";
            Out << arrKetQua[i][j] << " ";
        }
        cout << endl;
        Out << endl;
    }
}
void Bien_Doi(int x){
    switch(x){
        case 1:
            for(int i=1; i<=3; i++){
                arrKetQua[1][i]+= 2*arrKetQua[2][i];
            }
            break;
        case 2:

            for(int i=1; i<=3; i++){
                arrKetQua[2][i]+= 2*arrKetQua[3][i];
            }
            break;
        case 3:
            for(int i=1; i<=3; i++){
                arrKetQua[3][i]+= 2*arrKetQua[1][i];
            }
            break;
        case 4:
            for(int i=1; i<=3; i++){
                arrKetQua[i][1]+= 2*arrKetQua[i][2];
            }
            break;
        case 5:
            for(int i=1; i<=3; i++){
                arrKetQua[i][2]+= 2*arrKetQua[i][3];
            }
            break;
        case 6:
            for(int i=1; i<=3; i++){
                arrKetQua[i][3]+= 2*arrKetQua[i][1];
            }
            break;
        }
}
