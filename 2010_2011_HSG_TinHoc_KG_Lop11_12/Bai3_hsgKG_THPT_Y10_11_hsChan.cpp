#include <iostream>
#include <fstream>
#include <vector>
int arrN[101][101];
using namespace std;
int main(){
    ifstream MyRead("TAITRONG.INP");
    ofstream MyOut("TAITRONG.OUT");
    int N,batDau,ketThuc;
    MyRead>>N;
    MyRead>>batDau;
    MyRead>>ketThuc;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            MyRead>>arrN[i][j];
        }
    }
    //cout<<N<<" "<<batDau<<" "<<ketThuc<<endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            //cout<<arrN[i][j]<<" ";
        }
        //cout<<endl;
    }
    int dangDi=batDau;
    int taiTrongMax=0;
    vector<int> vtTaiTrongMax;
    vector<int> vtConDuong;
    vtConDuong.push_back(batDau);
    while(dangDi<ketThuc){
        int columMax=0;
        for(int i=0; i<=N; i++){
            if(taiTrongMax<=arrN[dangDi][i]){
                taiTrongMax=arrN[dangDi][i];
            }
        }
        for(int i=1; i<=N; i++){
            if(taiTrongMax==arrN[dangDi][i]){
                if(columMax<i){
                    columMax=i;
                }
            }
        }
        for(int i=1; i<=N; i++){
            bool ok=true;
            if(taiTrongMax==arrN[dangDi][i] && i==columMax){
                for(int x:vtConDuong){
                    if(x==i){
                        ok=false;
                        break;
                    }
                }
                if(ok==true){
                    dangDi=i;
                    vtConDuong.push_back(dangDi);
                    break;
                }
            }
        }
        vtTaiTrongMax.push_back(taiTrongMax);
        taiTrongMax=0;
    }
    taiTrongMax=0;
    for(int x:vtTaiTrongMax){
        if(taiTrongMax < x) taiTrongMax=x;
    }
    cout<<taiTrongMax<<endl;
    for(int i=0; i<vtConDuong.size(); i++){
        cout<<vtConDuong[i]<<" ";
    }
MyRead.close();
MyOut.close();
return 0;
}
