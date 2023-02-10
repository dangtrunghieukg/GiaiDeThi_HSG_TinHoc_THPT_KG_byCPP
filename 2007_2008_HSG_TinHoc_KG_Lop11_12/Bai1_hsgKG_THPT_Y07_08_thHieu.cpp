#include <iostream>
#include <fstream>
using namespace std;
int arrPhepBienDoi[100];
int arrDaySoNhapVao[1000];
int arrBangTanSo[10];
int arrMaTranBanDau[4][4];
int arrMaTranKetQua[4][4];
int demPhepBienDoi = 0, demSoNhapVao = 0;

void BienDoi_Fn(int x){
    switch (x) {
    case 1:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[1][i] += 2*arrMaTranKetQua[2][i];
        }
        break;
    case 2:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[2][i] += 2*arrMaTranKetQua[3][i];
        }
        break;
    case 3:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[3][i] += 2*arrMaTranKetQua[1][i];
        }
        break;
    case 4:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[i][1] += 2*arrMaTranKetQua[i][2];
        }
        break;
    case 5:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[i][2] += 2*arrMaTranKetQua[i][3];
        }
        break;
    case 6:
        for(int i=1; i<=3; i++){
            arrMaTranKetQua[i][3] += 2*arrMaTranKetQua[i][1];
        }
        break;
    default:
        break;
    }
}

int main(){
    ifstream MyReadFile("BDMATRAN.INP");
    ofstream MyOutFile("BDMATRAN.OUT");
    string strLine1, strLine2;
    getline(MyReadFile, strLine1); strLine1 += " ";
    getline(MyReadFile, strLine2); strLine2 += " ";
    string strTemp = "";
    int iTemp = 0;
    //Vòng lặp dưới đây đọc các số từ dòng 1
    for(int i=0; i<strLine1.length(); i++){
        if(strLine1[i] != ' '){
            strTemp += strLine1[i];
        }else{
            iTemp = stoi(strTemp);
            arrPhepBienDoi[demPhepBienDoi] = iTemp;
            demPhepBienDoi++;
            strTemp = "";
        }
    }
    ////Vòng lặp dưới đây đọc các số từ dòng 2
    strTemp = "";
    for(int i=0; i<strLine2.length(); i++){
        if(strLine2[i] != ' '){
            strTemp += strLine2[i];
        }else{
            iTemp = stoi(strTemp);
            arrDaySoNhapVao[demSoNhapVao] = iTemp;
            demSoNhapVao++;
            strTemp = "";
        }
    }
    // Đêm số lần xuất hiện của các số
    for(int i=0; i<demSoNhapVao; i++){
        arrBangTanSo[arrDaySoNhapVao[i]]++;
    }
    //// Nạp số vào ma trận ban đầu và khởi tạo ma trận kết quả
    int index_i=1;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            arrMaTranBanDau[i][j] = arrBangTanSo[index_i];
            arrMaTranKetQua[i][j] = arrBangTanSo[index_i];
            index_i++;
        }
    }
    for(int i=0; i<demPhepBienDoi; i++){
        BienDoi_Fn(arrPhepBienDoi[i]);
    }
    cout << "Ma tran ban dau: " << endl;
    MyOutFile << "Ma tran ban dau: " << endl;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout << arrMaTranBanDau[i][j] << " ";
            MyOutFile << arrMaTranBanDau[i][j] << " ";
        }
    cout << endl;
    MyOutFile << endl;
    }
    cout << "\nMa tran ket qua: " << endl;
    MyOutFile << "\nMa tran ket qua: " << endl;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout << arrMaTranKetQua[i][j] << " ";
            MyOutFile << arrMaTranKetQua[i][j] << " ";
        }
    cout << endl;
    MyOutFile << endl;
    }
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}