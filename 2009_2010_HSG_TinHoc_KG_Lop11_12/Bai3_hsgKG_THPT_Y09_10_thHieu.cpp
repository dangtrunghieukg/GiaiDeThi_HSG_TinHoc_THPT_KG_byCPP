#include <iostream>
#include <fstream>
using namespace std;
int uv[10001][3];
int arrBenTrai[100001], arrBenPhai[100001];
int main() {
    ifstream ReadFile("DUONGBO.INP");
    ofstream WriteFile("DUONGBO.OUT");
    int n, m;
    ReadFile >> n;
    ReadFile >> m;
    for(int i=1; i<=m; i++){
        ReadFile >> uv[i][1];
        ReadFile >> uv[i][2];
    }
    //Xuất kiểm tra đọc dữ liệu thành công hay chưa
    cout << n << " " << m << endl;
    for(int i=1; i<=m; i++){
        cout << uv[i][1] << " " << uv[i][2] << endl;
        arrBenTrai[uv[i][1]]++;
        arrBenPhai[uv[i][2]]++;
    }
    int soConDuongTrongYeu=0;
    for(int i=1; i<=n; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << arrBenTrai[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << arrBenPhai[i] << " ";
    }
    cout << endl << soConDuongTrongYeu << endl;
    return 0;
}