#include <iostream>
#include <fstream>
using namespace std;

bool arrDanhDau[20]; //Mảng đánh dấu true = chọn, false = không chọn
int arrDayHoanVi[20]; //Mảng lưu trữ phần tử trong dãy hoán vị
int N;
int demHoanViXuat = 0;
ifstream ReadFile("HOANVI.INP");
ofstream OutFile("HOANVI.OUT");
void XuatHoanVi() {
    bool xuatOk = true;
    for(int i = 1; i <= N; i++){
        if (i == arrDayHoanVi[i]){
            xuatOk = false;
            break;
        }
    }
    if (xuatOk == true) {
        for (int i = 1; i <= N; i++) {
            cout << arrDayHoanVi[i] << " ";
            OutFile << arrDayHoanVi[i] << " ";
        }
        demHoanViXuat++;
        cout << endl;
        OutFile << endl;
    }
}
//Thuật toán quy lui, có đệ quy
void TimHoanVi(int k) {
    for (int i = 1; i <= N; i++) {
        if (arrDanhDau[i] == true){
            arrDayHoanVi[k] = i;
            arrDanhDau[i] = false; //Đánh dấu phần tử i không chọn nữa
            if (k == N) {
                XuatHoanVi();
            } else {
                TimHoanVi(k+1); //Đệ quy
            }
            arrDanhDau[i] = true;
        }
    }
}

int main(){
    ReadFile >> N;
    //Đánh dấu tất cả các phần tử ban đầu đều sẵn sàng được chọn = true
    for(int i=1; i<=N; i++)
        arrDanhDau[i] = true;
    TimHoanVi(1);
    cout << "So hoan vi = " << demHoanViXuat;
    OutFile << "So hoan vi = " << demHoanViXuat;
    ReadFile.close();
    OutFile.close();
    return 0;
}
