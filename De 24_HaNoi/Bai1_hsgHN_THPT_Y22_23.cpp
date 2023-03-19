#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool SoNgTo(int N){
    bool ketQua=true;
    if(N<=1) return false;
    else{
        for(int i=2; i<=sqrt(N); i++){
            if(N%i==0){
                ketQua=false;
                break;
            }
        }
    }
    return ketQua;
}
int main(){
    int a,b;
    ifstream Read("CP.INP");
    ofstream Out("CP.OUT");
    Read>>a;
    Read>>b;
    //cout<<a<<" "<<b<<endl;
    int can;
    int dem;
    for(int i=a; i<=b; i++){
        can= sqrt(i);

        if(can*can==i){
            if(SoNgTo(can)==true){
                dem++;
            }
        }
    }
    cout<<dem<<endl;
    Out<<dem<<endl;

return 0;
}
