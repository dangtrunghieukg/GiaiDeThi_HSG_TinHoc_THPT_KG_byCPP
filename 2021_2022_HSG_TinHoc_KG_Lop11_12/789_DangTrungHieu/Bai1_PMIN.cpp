#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream ReadFile("PMIN.INP");
    ofstream WriteFile("PMIN.OUT");
    int a, b;
    long long c;
    ReadFile >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;
    vector<unsigned long long> vtTich;
    for(int i = a; i <= 10000; i++){
        for(int j = b; j <= 10000; j++){
            if (i*j >= c) {
                vtTich.push_back(i*j);
            }
        }
    }
    sort(vtTich.begin(), vtTich.end());
    for(unsigned long long x : vtTich){
        if (x > c) {
            cout << x;
            WriteFile << x;
            break;
        }
    }
    ReadFile.close();
    WriteFile.close();
    return 0;
}