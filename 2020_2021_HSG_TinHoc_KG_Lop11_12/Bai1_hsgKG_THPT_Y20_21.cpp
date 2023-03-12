#include <iostream>
#include <fstream>
using namespace std;
bool SoHoanHao(int N){
    bool ketQua=false;
    int tongUoc=0;
    for(int i=1; i<=N/2; i++){
        if(N%i==0){
            tongUoc+=i;
        }
    }
    if(tongUoc==N){
        ketQua=true;
    }else{
        ketQua=false;
    }
    return ketQua;
}
int main(){
    int M,N;
    ifstream Read("PERFECT.INP");
    ofstream Out("PERFECT.OUT");
    Read>>M;
    for(int i=1; i<=M; i++){
        Read>>N;
       // cout<<N<<"."<<endl;
         bool daXuat=false;
        for(int j=N; j>=1; j--){
            if(SoHoanHao(j)==true){
                cout<<j<<endl;
                Out<<j<<endl;
                daXuat=true;
                break;
            }
        }
        if(daXuat==false){
            cout<<endl;
            Out<<endl;
        }
    }
Read.close();
Out.close();

return 0;
}
