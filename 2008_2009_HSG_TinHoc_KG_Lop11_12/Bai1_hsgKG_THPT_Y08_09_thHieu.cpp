#include <iostream>
#include <fstream>
using namespace std;

int arrN[1000001];
int N, k;
int main(){
    ifstream MyReadFile("DEMNGUOI.INP");
    ofstream MyOutFile("DEMNGUOI.OUT");
    MyReadFile >> N;
    MyReadFile >> k;
    cout << N << endl;
    cout << k << endl;
    for(int i=1; i<=N; i++){
        arrN[i]=i;
    }
    /*
    for(int i=1; i<=N; i++){
        cout << arrN[i] << " ";
    }
    */
    cout << endl;

    bool okXong = false;
    int chiSoLanCuoi=0;
    int demK=0;
    while (!okXong){
        okXong = true;
        for(int i=1; i<=N; i++){
            if(arrN[i] != -1){
                okXong = false;
                break;
            }
        }
        for(int i=1; i<=N; i++){
            if(arrN[i]!=-1){
                demK++;
                if(demK==k){
                    arrN[i]=-1;
                    demK=0;
                    chiSoLanCuoi = i;
                }
            }
        }
        
    }
    /*
    for(int i=1; i<=N; i++){
        cout << arrN[i] << " ";
    }
    */
    cout << endl<< chiSoLanCuoi;
    MyOutFile << chiSoLanCuoi;
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}