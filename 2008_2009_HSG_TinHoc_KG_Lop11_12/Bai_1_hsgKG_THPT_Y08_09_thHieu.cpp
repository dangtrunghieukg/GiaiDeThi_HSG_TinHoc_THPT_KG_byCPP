#include <iostream>
#include <fstream>
using namespace std;
int N, k;
int arrMang[1000001];
int main(){
    ifstream Read("DEMNGUOI.INP");
    ofstream Print("DEMNGUOI.OUT");
    Read >> N;
    Read >> k;
    for(int i=1; i<=N; i++){
        arrMang[i]=i;
    }
    bool xong=false;
    int viTri=0;
    int demK=0;
    while(!xong){
        xong=true;
        for(int i=1; i<=N; i++){
            if(arrMang[i] != -1){
                xong=false;
                break;
            }
        }
        for(int i=1; i<=N; i++){
            if(arrMang[i]!=-1){
                demK++;
                if(demK==k){
                    arrMang[i]=-1;
                    demK=0;
                    viTri=i;
                }
            }
        }
    }
    cout << viTri;
    return 0;
}
