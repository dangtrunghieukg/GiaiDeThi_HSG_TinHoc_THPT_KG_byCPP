#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool isNgto(int N){
    bool kq=true;
    if(N<2) kq=false;
    if(N==2) kq=true;
    if(N>2){
        for(int i=2; i<=sqrt(N); i++){
            if(N%i==0){
                kq=false;
                break;
            }
        }
    }
    return kq;
};

int main(){
    ifstream Read("CP.INP");
    ofstream Print("CP.OUT");
    int a, b;
    Read >> a; Read >> b;
    int dem=0;
    for(int i=a; i<=b; i++){
        int can=sqrt(i);
        if(can*can==i){
            if(isNgto(can)){
                cout << i << endl;
                dem++;
            }
        }
    }
    cout << dem;
    Print << dem;
    return 0;
}
