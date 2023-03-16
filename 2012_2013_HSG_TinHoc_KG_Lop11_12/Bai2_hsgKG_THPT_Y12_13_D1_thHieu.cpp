#include <iostream>
#include <fstream>
using namespace std;
unsigned long long m, boiSo, dem=1;
int main() {
    ifstream ReadFile("BOISO.INP");
    ofstream OutFile("BOISO.OUT");
    ReadFile >> m;
    bool daTimOk = false;
    string strM;
    while (!daTimOk) {
        daTimOk = true;
        boiSo = m * dem;
        strM = to_string(boiSo);
        for (char c : strM){
            if (c != '0' && c != '1'){
                daTimOk = false;
                break;
            }
        }
        if (daTimOk == true) {
            cout << boiSo;
            OutFile << boiSo;
            break;
        }
        dem ++;
    }
    ReadFile.close();
    OutFile.close();
    return 0;
}