#include <iostream>
#include <fstream>

using namespace std;
bool ktrSo(unsigned long long N){
    bool isF=true;
    while(N!=0){
        if(N%10!=0 && N%10!=1){
            return false;
        }
        else if(N%10==0 || N%10==1){
            N=N/10;
        }
    }
    return true;
};

int main(){
    unsigned long long N;
    ifstream Read("BOISO.INP");
    ofstream print("BOISO.OUT");
    Read >> N;
    //cout << N;
    unsigned long long tam=0;
    tam=N;
    unsigned long long i=2;
    while(ktrSo(tam)==false){
        tam=N*i;
        i++;
    }
    //cout << tam;
    unsigned long long A=1111111122111111111111;
    cout << A;
    return 0;
}
