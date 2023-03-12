#include <iostream>
#include <fstream>

using namespace std;
int arrMang[1000000][2];
int main(){
    ifstream Read("GRAB.INP");
    ofstream Print("GRAB.OUT");
    int N;
    Read >> N;
    int dem=0;
    while(!Read.eof()){
        Read >> arrMang[dem][0];
        Read >> arrMang[dem][1];
        dem++;
    }
    for(int i=1; i<dem; i++){
        if(arrMang[i][0]<=arrMang[i][1]){
            cout << arrMang[i][0] << " " << arrMang[i][1];
        }
        cout << endl;
    }
    cout << N << endl;
    for(int i=0; i<dem; i++){
        cout << arrMang[i][0] << " ";
        cout << arrMang[i][1] << endl;
    }
    Read.close();
    Print.close();
    return 0;
}
