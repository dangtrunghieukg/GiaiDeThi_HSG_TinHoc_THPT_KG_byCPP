#include <iostream>
#include <fstream>
using namespace std;
bool SoHoanHao(int n) {
    int tongUoc = 0;
    bool flag = false;
    int n_new=n;
    for(int i=n_new/2; i >=1; i--){
        if (n%i == 0){
            tongUoc += i;
            n_new = n_new/i;
            if(tongUoc>n){
                break;
            }
        }
    }
    if (tongUoc == n){
        flag = true;
    }
    return flag;
}
int main() {
    int n;
    ifstream ReadFile("PERPECT.INP");
    ofstream OutFile("PERPECT.OUT");
    ReadFile >> n;
    int soInput;
    for (int i = 1; i <= n; i++) {
        ReadFile >> soInput;
        bool xuatOk = false;
        for (int j = soInput; j >= 1; j--) {
            if (SoHoanHao(j)){
                cout << j << endl;
                xuatOk = true;
                break;
            }
        }
        if (!xuatOk) {
            cout << endl;
        }
    }
    return 0;
}