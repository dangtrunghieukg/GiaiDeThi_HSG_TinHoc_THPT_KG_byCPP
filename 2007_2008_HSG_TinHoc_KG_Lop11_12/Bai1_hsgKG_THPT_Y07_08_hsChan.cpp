#include <iostream>
#include <fstream>
int arrBienDoi[1000000];
int arrSoNhapVao[1000000];
int arrTanSo[10];
int arrMaTranBD[4][4];
int arrMaTranKQ[4][4];

void BienDoi(int x){
 switch(x){
    case 1:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[1][i]+=2*arrMaTranKQ[2][i];
        }
    break;
    case 2:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[2][i]+=2*arrMaTranKQ[3][i];
        }
    break;
    case 3:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[3][i]+=2*arrMaTranKQ[1][i];
        }
    break;
    case 4:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[i][1]+=2*arrMaTranKQ[i][2];
        }
    break;
    case 5:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[i][2]+=2*arrMaTranKQ[i][3];
        }
    break;
    case 6:
        for(int i=1;i<=3; i++){
            arrMaTranKQ[i][3]+=2*arrMaTranKQ[i][1];
        }
    break;
    default:
        break;
    }
}
using namespace std;
int main(){
    string strLine1, strLine2 = "";
    ifstream MyReadFile("BDMATRAN.INP");
    ofstream MyOutFile("BDMATRAN.OUT");
    getline(MyReadFile, strLine1);
    getline(MyReadFile, strLine2);
    strLine1 = strLine1 + " ";
    strLine2 = strLine2 + " ";
    string strTemp="";
    int demPBD=0;
    for(int i=0; i<strLine1.length(); i++){
        if(strLine1[i]!=' '){
            strTemp+=strLine1[i];
        }else{
            arrBienDoi[demPBD]=stoi(strTemp);
            strTemp="";
            demPBD++;
        }
    }
    strTemp="";
    int demSNV=0;
    for(int i=0; i<strLine2.length(); i++){
        if(strLine2[i]!=' '){
            strTemp+=strLine2[i];

        }else{
            arrSoNhapVao[demSNV]=stoi(strTemp);
            strTemp="";
            demSNV++;
        }
    }
   for(int i=0; i<demSNV;i++){
        arrTanSo[arrSoNhapVao[i]]++;
   }

   int dem=1;
   for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            arrMaTranBD[i][j]=arrTanSo[dem];
            arrMaTranKQ[i][j]=arrTanSo[dem];
            dem++;
        }
   }
   for(int i=0; i<demPBD; i++){
    BienDoi(arrBienDoi[i]);
   }
   cout<<"Ma tran ban dau: "<<endl;
   MyOutFile<<"Ma tran ban dau: "<<endl;
   for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout<<arrMaTranBD[i][j]<< " ";
           MyOutFile<<arrMaTranBD[i][j]<< " ";
        }
        cout<<endl;
        MyOutFile<<endl;
   }
   cout<<"Ma tran ket qua: "<<endl;
   MyOutFile<<"Ma tran ket qua: "<<endl;
   for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout<<arrMaTranKQ[i][j]<< " ";
           MyOutFile<<arrMaTranKQ[i][j]<< " ";
        }
        cout<<endl;
        MyOutFile<<endl;
   }
    MyReadFile.close();
    MyOutFile.close();


return 0;
}
