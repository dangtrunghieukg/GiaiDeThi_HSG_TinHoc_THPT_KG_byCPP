#include <iostream>
#include <fstream>
using namespace std;
ifstream ReadFile("ROBOT.INP");
ofstream OutFile("ROBOT.OUT");
int arrR[101][101];
int Ai, Aj, Bi, Bj;
int m, n;
int main() {
    // Input data
    ReadFile >> m;
    ReadFile >> n;
    cout << m << " " << n << endl;
    for(int i=1; i <=m; i++){
        for(int j=1; j<=n; j++){
            ReadFile >> arrR[i][j];
            cout << arrR[i][j] << " ";
        }
        cout << endl;
    }
    //Output data
    Ai=1; Aj=1;
    Bi=m; Bj=n;
    while (!(Ai == Bi & Aj == Bj)) {
        if (arrR[Ai+1])
    }
    return 0;
}