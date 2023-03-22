#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream Read("SAPXEP.INP");
    ofstream Print("SAPXEP.OUT");
    int N, M;
    vector <int> vtSo;
    Read >> N >> M;
    cout << N << " " << M << endl;
    int A[100][100]={0};
    int B[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            Read >> A[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "---------------------" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            vtSo.push_back(A[i][j]);
        }
    }
    int tam=0;
    for(int k=0; k<vtSo.size(); k++){
        for(int x=k+1; x<vtSo.size(); x++){
            if(vtSo[k]>vtSo[x]){
                tam=vtSo[k];
                vtSo[k]=vtSo[x];
                vtSo[x]=tam;

            }
        }
    }
    int vitri=0;
    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
            B[a][b]=vtSo[vitri];
            vitri++;
        }
    }

    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
            cout << B[a][b] << " ";
            Print << B[a][b] << " ";
        }
        cout << endl;
        Print << endl;
    }
    Read.close();
    Print.close();
    return 0;
}
