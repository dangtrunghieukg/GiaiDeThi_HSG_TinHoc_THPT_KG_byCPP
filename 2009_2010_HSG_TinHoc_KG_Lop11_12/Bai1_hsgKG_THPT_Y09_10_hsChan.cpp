#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int n,m;
int main(){
    ifstream Read("TCLTB3.INP");
    ofstream Out("TCLTB3.OUT");
    //unsigned long long n, m;
    while(!Read.eof()){
        Read>>n;
        /*unsigned long long tongLapPhuong=0;
    for(unsigned long long i=1;i<=n;i++){
        tongLapPhuong+=i*i*i;
    }
    m=sqrtl(tongLapPhuong);
    cout<<m<<endl;
    Out<<m<<endl;*/
    m=n*(n+1)/2;
    cout<<m<<endl;
    }

    Read.close();
    Out.close();
    return 0;
}
