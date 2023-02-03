#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Hàm này tính tổng bình phương các chữ số của đối số X
int FX(int X){
    string strX = to_string(X);
    int tongBinhPhuong = 0;
    for(int i=0; i<strX.length(); i++){
        tongBinhPhuong += (strX[i] - 48)*(strX[i] - 48);
    }
    return tongBinhPhuong;
}

//Hàm này trả về chiều dài của dãy và xuất ngược string kết quả vào biến strX
//Ví dụ: DayXn(13, strX) thì kết quả bằng = 4 và strX ="13 10 1 1 "
int DayXn(int x, string &strX){
    vector<int> vtDayXn;
    vtDayXn.push_back(x);
    bool soDaCo = false;
    while(!soDaCo){
        x = FX(x);
        for(int i=0; i<vtDayXn.size(); i++){
            if(vtDayXn[i]==x){
                soDaCo = true;
                vtDayXn.push_back(x);
                break;
            }
        }
        if(!soDaCo){
            vtDayXn.push_back(x);
        }
    }
    for(int i=0; i<vtDayXn.size(); i++){
        strX = strX + to_string(vtDayXn[i]) + " ";
    }
    return vtDayXn.size();
}

int main(){
    ifstream MyReadFile("TEST.INP");
    ofstream MyOutFile("TEST.OUT");
    int a, b;
    MyReadFile >> a;
    MyReadFile >> b;

    vector<int> vtChieuDaiXn;
    vector<string> vtStringXn;

    string chuoiXuat = "";
    int chieuDaiXn, chieuDaiMax = 0, demSoX=0;

    for(int x = a; x<=b; x++){
        chuoiXuat = "";
        chieuDaiXn = DayXn(x, chuoiXuat);
        vtChieuDaiXn.push_back(chieuDaiXn);
        vtStringXn.push_back(chuoiXuat);
        if(chieuDaiMax<chieuDaiXn) chieuDaiMax = chieuDaiXn;
    }
    
    for(int x:vtChieuDaiXn){
        if(chieuDaiMax == x) demSoX++;
    }

    MyOutFile << chieuDaiMax << endl;
    MyOutFile << demSoX << endl;

    for(int i=0; i<vtChieuDaiXn.size(); i++){
        if(vtChieuDaiXn[i]==chieuDaiMax){
            MyOutFile << vtStringXn[i] << endl;
        }
    }
    MyReadFile.close();
    return 0;
}