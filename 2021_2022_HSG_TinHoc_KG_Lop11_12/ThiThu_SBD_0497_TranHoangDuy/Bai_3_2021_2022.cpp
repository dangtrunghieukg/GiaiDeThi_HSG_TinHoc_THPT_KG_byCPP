#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream Read("KESACH.INP");
    ofstream Print("KESACH.OUT");
    int N, L;
    Read >> N;
    Read >> L;
    cout << N << " " << L << endl;
    int A[N+1][3];
    for(int i=1; i<=N; i++){
        Read >> A[i][1];
        Read >> A[i][2];
    }
    for(int i=1; i<=N; i++){
        cout << A[i][1] << " " << A[i][2] << endl;
    }
    Read.close();
    Print.close();
    return 0;
}
