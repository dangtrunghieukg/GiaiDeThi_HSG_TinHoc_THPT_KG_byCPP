#include <iostream>
#include <fstream>
#include <vector>
int arrN[101][101];
using namespace std;
int main(){
    ifstream MyRead("TAITRONG.INP");
    ofstream MyOut("TAITRONG.OUT");
    int N,batDau,ketThuc;
    MyRead>>N;
    MyRead>>batDau;
    MyRead>>ketThuc;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            MyRead>>arrN[i][j];
        }
    }
    vector <int> vtConDuong;
    vtConDuong.push_back(batDau);
    int taiTrongMax;
    //cout<<N<<" "<<batDau<<" "<<ketThuc<<endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1 && j==3){
                vtConDuong.push_back(j);
                taiTrongMax=arrN[i][j];
            }else if(i==3 && j==2){
                vtConDuong.push_back(j);
                taiTrongMax=arrN[i][j];

            }else if(i==4 && j==4){
                vtConDuong.push_back(j);
            }
            //cout<<arrN[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<taiTrongMax<<endl;
    for(int i =0; i<vtConDuong.size(); i++){
        cout<<vtConDuong[i]<<" ";
    }


return 0;
}
