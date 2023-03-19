#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool isPrime(int N){
    bool okFlag = true;
    if (N <=1 ) okFlag = false;
    else {
        for (int i = 2; i*i <= N; i++){
            if (N % i == 0) {
                okFlag = false;
                break;
            }
        }
    }
    return okFlag;
}
int main() {
    ifstream ReadFile("CP.INP");
    ofstream OutFile("CP.OUT");
    int a, b, canBacHai;
    ReadFile >> a;
    ReadFile >> b;
    int dem = 0;
    for (int i = a; i <= b; i++){
        canBacHai = (int)sqrt(i);
        if (i == canBacHai*canBacHai) {
            if (isPrime(canBacHai)) {
                dem++;
            }
        }
    }
    cout << dem;
    OutFile << dem;
    ReadFile.close();
    OutFile.close();
    return 0;
}