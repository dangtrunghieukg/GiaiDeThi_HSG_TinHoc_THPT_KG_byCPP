#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> vtKQ;
int main(){
    ifstream Read("TAITRONG.INP");
    ofstream Print("TAITRONG.OUT");
    int N, S, T;
    Read >> N;
    Read >> S;
    Read >> T;
    int arrMang[N][N];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            Read >> arrMang[i][j];
        }
    }
    vtKQ.push_back(S);
    for(int i=1; i<=N; i++){
        arrMang[i][S]=0;
    }
    int soMax=0;
    int viTri;
    for(int i=1; i<=N; i++){
        if(arrMang[S][i]>soMax){
            soMax=arrMang[S][i];
            viTri=i;
        }
    }
    vtKQ.push_back(viTri);
    soMax=0;
    for(int i=1; i<=N; i++){
        if(arrMang[viTri][i]>soMax){
            soMax=arrMang[viTri][i];
            viTri=i;
        }
    }

    for(int i=1; i<=N; i++){
        arrMang[i][viTri]=0;
    }

    cout << endl << "_____" << viTri << "_____" << endl;
    vtKQ.push_back(viTri);
    for(int i=1; i<=N; i++){
        arrMang[i][viTri]=0;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << arrMang[i][j] << " ";
        }
        cout << endl;
    }

    soMax=0;
    for(int i=1; i<=N; i++){
        if(arrMang[viTri][i]>soMax){
            soMax=arrMang[viTri][i];
            viTri=i;
        }
    }
    vtKQ.push_back(viTri);
    cout << "-----------" << endl;
    for(int i=0; i<vtKQ.size(); i++){
        cout << vtKQ[i] << " ";
    }
    return 0;
}
