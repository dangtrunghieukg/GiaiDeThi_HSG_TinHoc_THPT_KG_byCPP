#include <iostream>
#include <fstream>
using namespace std;
char arrPhepToan[4] = {'+', '-', '*', '/'};
int PhepToan(int a, int b, char c){
    float ketQua;
    switch (c) {
        case '+':
            ketQua = a + b;
            break;
        case '-':
            ketQua = a - b;
            break;
        case '*':
            ketQua = a*b;
            break;
        case '/':
            ketQua = (float)a/b;
            break;
        default:
            break;
    }
}
int main() {
    ifstream ReadFile("BIEUTHUC.INP");
    ofstream OutFile("BIEUTHUC.OUT");
    int N;
    ReadFile >> N;
    float kq1, kq2, kq3, kq4, kq5;
    int demSoPhuongAn = 0;
    for(int a=0; a<4; a++){
        kq1 = PhepToan(1,2,arrPhepToan[a]);
        for(int b=0; b<4; b++){
            kq2 = PhepToan(kq1, 3, arrPhepToan[b]);
            for(int c=0; c<4; c++){
                kq3 = PhepToan(kq2, 4, arrPhepToan[c]);
                for(int d=0; d<4;d++){
                    kq4 = PhepToan(kq3, 5, arrPhepToan[d]);
                    for(int e=0; e<4; e++){
                        kq5 = PhepToan(kq4, 6, arrPhepToan[e]);
                        if ( kq5 == N){
                            cout << "(((((1"<<arrPhepToan[a]<<"2)"<<arrPhepToan[b]<<"3)"<<arrPhepToan[c]<<"4)"<<arrPhepToan[d]<<"5)"<<arrPhepToan[e]<<"6) = " << N << endl;
                            OutFile << "(((((1"<<arrPhepToan[a]<<"2)"<<arrPhepToan[b]<<"3)"<<arrPhepToan[c]<<"4)"<<arrPhepToan[d]<<"5)"<<arrPhepToan[e]<<"6) = " << N << endl;
                            demSoPhuongAn++;
                        }
                    }
                }
            }
        }
    }
    if (demSoPhuongAn == 0) {
        cout << 0;
        OutFile << 0;
    }
    ReadFile.close();
    OutFile.close();
    return 0;
}