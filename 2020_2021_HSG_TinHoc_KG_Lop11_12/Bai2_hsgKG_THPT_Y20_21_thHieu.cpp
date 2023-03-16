#include <iostream>
#include <fstream>
using namespace std;
int A[10000001][3];
int main() {
    ifstream ReadFile("GRAB.INP");
    ofstream OutFile("GRAB.OUT");
    int N;
    ReadFile >> N;
    int soDong = 0;
    int iTemp1, iTemp2;
    while (!ReadFile.eof()) {
        soDong++;
        ReadFile >> iTemp1;
        ReadFile >> iTemp2;
        A[soDong][1] = iTemp1;
        A[soDong][2] = iTemp2;
    }
    for (int i = 1; i <= soDong; i++) {
        cout << A[i][1] << " " << A[i][2] << endl;
    }
    return 0;
}