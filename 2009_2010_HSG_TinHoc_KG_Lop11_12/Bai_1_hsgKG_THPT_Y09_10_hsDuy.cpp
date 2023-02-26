#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
unsigned long long tongLapPhuong=0, m, n;
int main(){
    ifstream Read("TCLTB3.INP");
    ofstream Print("TCLTB3.OUT");
    while(!Read.eof()){
        Read >> n;
        m=(n*(n+1))/2;
        cout << m << endl;
        Print << m << endl;
        m=0;
        tongLapPhuong=0;
    }
    return 0;
}
