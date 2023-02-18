#include <iostream>
using namespace std;
int mangN[101];
int N;
void Xuatchuoi(){
    for(int i=1; i<=N; i++){
        cout << mangN[i];
    }
    cout << endl;
}
void LienKeChuoi(int i){
    for(int j=0; j<=1; j++){
        mangN[i]=j;
        if(i==N){
            XuatChuoi();
        }else{
            LietKeChuoi(i+1);
        }
    }
}
int main(){
    int N=3;
    LienKeChuoi(1);
    return 0;
}
