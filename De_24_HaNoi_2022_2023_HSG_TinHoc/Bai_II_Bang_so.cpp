#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream ReadFile("BS.INP");
    ofstream OutFile("BS.OUT");
    int n, x, dem = 0;
    ReadFile >> n;
    ReadFile >> x;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (x == i*j) {
                dem ++;
            }
            if (i*j > x) break;
        }
    }
    cout << dem;
    ReadFile.close();
    OutFile.close();
    return 0;
}