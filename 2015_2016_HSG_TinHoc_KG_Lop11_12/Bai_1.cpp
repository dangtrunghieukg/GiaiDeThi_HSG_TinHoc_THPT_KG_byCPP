#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream Read("MINMAX.INP");
    ofstream Print("MINMAX.OUT");
    int N;
    vector <int> vtSo;
    Read >> N;
    int A[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Read >> A[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            vtSo.push_back(A[i][j]);
        }
    }
    int soMax=vtSo[0];
    int soMin=vtSo[0];
    for(int x=1; x<vtSo.size(); x++){
        soMin=min(soMin, vtSo[x]);
        soMax=max(soMax, vtSo[x]);
    }
    cout << soMin << endl << soMax << endl;
    Print << soMin << endl << soMax << endl;
    return 0;
}
