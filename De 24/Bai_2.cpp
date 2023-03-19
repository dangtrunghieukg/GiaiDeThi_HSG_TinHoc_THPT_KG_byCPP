#include <iostream>
#include <fstream>

using namespace std;
int A[10000][1000];

int main(){
    ifstream Read("BS.INP");
    ofstream Print("BS.OUT");
    int N, M;
    Read >> N;
    Read >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            A[i][j]=j*i;
        }
    }
    int dem=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(A[i][j]==M){
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}
