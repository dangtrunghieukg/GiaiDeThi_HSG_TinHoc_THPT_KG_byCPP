#include <iostream>
#include <fstream>

using namespace std;
int arrMang[10000];

bool SoHoanHao(int N){
    bool isPerfect=false;
    int tongUoc=0;
    for(int i=1; i<=N/2; i++){
        if(N%i==0){
            tongUoc+=i;
        }
    }
    if(tongUoc==N){
        isPerfect=true;
    }
    return isPerfect;
};

int main(){
    int M;
    ifstream Read("PERFECT.INP");
    ofstream Print("PERFECT.OUT");
    Read >> M;
    int dem=1;
    while(!Read.eof()){
        Read >> arrMang[dem];
        dem++;
    }
    int tam=0;
    bool daXuat=false;
    for(int i=1; i<dem; i++){
        cout << arrMang[i] << ": ";
        for(int j=arrMang[i]; j>0; j--){
            if(SoHoanHao(j)==true){
                cout << j << endl;
                Print << j << endl;
                daXuat=true;
                break;
            }
        }
        cout << endl;
        if(daXuat==false){
            Print << endl;
        }
    }
    return 0;
};
