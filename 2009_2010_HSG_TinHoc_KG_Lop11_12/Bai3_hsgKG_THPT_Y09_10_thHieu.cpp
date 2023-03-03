#include <iostream>
#include <fstream>
using namespace std;
int uv[10001][5];
int arrBenTrai[100001][2], arrBenPhai[100001][2];
int main() {
    ifstream ReadFile("DUONGBO.INP");
    ofstream OutFile("DUONGBO.OUT");
    int n, m;
    ReadFile >> n;
    ReadFile >> m;
    for(int i=1; i<=m; i++){
        ReadFile >> uv[i][1];
        ReadFile >> uv[i][2];
    }
    //Xuất kiểm tra đọc dữ liệu thành công hay chưa
    cout << "--------Input data----------" << endl;
    cout << n << " " << m << endl;
    for(int i=1; i<=m; i++){
        cout << uv[i][1] << " " << uv[i][2] << endl;
        arrBenTrai[uv[i][1]][0]++;
        arrBenTrai[uv[i][2]][1]++;
        arrBenPhai[uv[i][2]][0]++;
        arrBenPhai[uv[i][1]][1]++;
    }
    cout << "----------Output ------------\n";
    int soConDuongTrongYeu=0;
    for(int i=1; i<=m; i++){
        //cout << uv[i][1] << " " << uv[i][2] << " | " << arrBenTrai[uv[i][1]][0] << " " << arrBenPhai[uv[i][2]][0] << " | " << arrBenTrai[uv[i][1]][1] << " " << arrBenPhai[uv[i][2]][1] << endl;
        if (arrBenTrai[uv[i][1]][0] == 1 && arrBenPhai[uv[i][2]][0] == 1){
            soConDuongTrongYeu ++;
            cout << uv[i][1] << " " << uv[i][2] << endl;
            OutFile << uv[i][1] << " " << uv[i][2] << endl;
        } else if (arrBenTrai[uv[i][1]][1] == 0 &&  arrBenPhai[uv[i][2]][1] == 0) {
            soConDuongTrongYeu ++;
            cout << uv[i][1] << " " << uv[i][2] << endl;  
            OutFile << uv[i][1] << " " << uv[i][2] << endl;
        }
    }
    if (soConDuongTrongYeu==0){
        cout << "Khong tim thay con duong trong yeu";
    }else{
        cout << "Co " << soConDuongTrongYeu << " con duong trong yeu";
    }
    ReadFile.close();
    OutFile.close();
    return 0;
}