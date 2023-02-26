#include <iostream>
#include <fstream>
using namespace std;
int N, k;
int arrMang[1000];
int arrMangKQ[10000];
int main(){
    ifstream Read("DEMNGUOI.INP");
    ofstream Print("DEMNGUOI.OUT");
    Read >> N;
    Read >> k;
    int demA=0;
    int demB=0;
    for(int j=1; j<=N; j++){
        arrMang[demA]=j;
        demA++;
    }
    while(demA!=1){
        for(int i=0; i<demA; i++){

        }
        demA--;
    }
    /*for(int i=0; i<demB; i++){
        cout << arrMangKQ[i] << " ";
    }*/
    Read.close();
    Print.close();
    return 0;
}
