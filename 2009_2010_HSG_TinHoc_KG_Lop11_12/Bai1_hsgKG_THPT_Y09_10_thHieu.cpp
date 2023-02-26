#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
/* Nếu bài này phát hiện ra tính chất: 1^3+2^3+..+k^3=(1+2+...+k)^2 = (n(n+1)/2)^2 thì làm rất nhanh*/
int main() {
    ifstream MyReadFile("TCLTB3.INP");
    ofstream MyOutFile("TCLTB3.OUT");
    unsigned long long n, m;
    while(!MyReadFile.eof()){
        MyReadFile >> n;
        unsigned long long tongLapPhuong = 0, kq;
        /*
        for(unsigned long long i=1; i<=n; i++){
            tongLapPhuong += i*i*i;
        }
        m = sqrtl(tongLapPhuong);
        cout << m << endl;
        MyOutFile << m << endl;
        */
       kq = n*(n+1)/2;
       cout << kq << endl;
       MyOutFile << kq << endl;
    }
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}
