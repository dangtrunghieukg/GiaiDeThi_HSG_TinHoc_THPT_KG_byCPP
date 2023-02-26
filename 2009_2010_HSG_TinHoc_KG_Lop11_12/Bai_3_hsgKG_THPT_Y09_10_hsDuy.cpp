#include <iostream>
#include <fstream>
using namespace std;
int arrMang[10001][2];
int main(){
    ifstream Read("DUONGBO.INP");
    ofstream Print("DUONGBO.OUT");
    int dem=0;
    while(!Read.eof()){
        Read >> arrMang[dem][0];
        Read >> arrMang[dem][1];
        dem++;
    }
    //Nhập File.
    for(int i=0; i<dem; i++){
        cout << arrMang[i][0] << " " << arrMang[i][1] << endl;
    }
    return 0;
}
