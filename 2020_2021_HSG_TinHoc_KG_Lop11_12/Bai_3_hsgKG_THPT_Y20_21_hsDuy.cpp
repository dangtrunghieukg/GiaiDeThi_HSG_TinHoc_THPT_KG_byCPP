#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector <int> vtTime;
vector <int> vtGift;
vector <int> vtDayXem, vtDayXem2;

int main(){
    ifstream Read("AMUSIC.INP");
    ofstream Print("AMUSIC.OUT");
    int N, d;
    Read >> N; Read >> d;
    int tam=0;
    for(int i=1; i<=N; i++){
        Read >> tam;
        vtTime.push_back(tam);
    }
    for(int i=1; i<=N; i++){
        Read >> tam;
        vtGift.push_back(tam);
    }
    cout << N << " " << d << endl;
    for(int i=0; i<vtTime.size(); i++){
        cout << vtTime[i] << " ";
    }
    cout << endl;
    for(int i=0; i<vtGift.size(); i++){
        cout << vtGift[i] << " ";
    }
    cout << endl << "\t----------------------------------------------------" << endl;
    int tongQua=0;
    for(int i=1; i<=N; i++){
        int iMax=0;
        if(i>=d){
            for(int j=0; j<vtTime.size(); j++){
                if(vtTime[j]==i){
                    if(iMax<vtGift[j]){
                        iMax=vtGift[j];
                    }
                }
            }
            for(int j=0; j<vtTime.size(); j++){
                if(vtGift[j]==iMax && iMax>0){
                    vtDayXem.push_back(j+1);
                }
            }
        }

    }
    for(int x=0; x<vtDayXem.size(); x++){
        if(vtDayXem[x]!=1){
            vtDayXem2.push_back(vtDayXem[x]);
        }else{
            vtDayXem2.push_back(vtDayXem[x]);
            vtDayXem2.push_back(vtDayXem[x]+2);
        }
    }
    for(int x=0; x<vtDayXem2.size(); x++){
        tongQua+=vtGift[vtDayXem2[x]-1];
    }
    cout << endl << tongQua << endl;
    Print << tongQua << endl;
    for(int x=0; x<vtDayXem2.size(); x++){
        cout << vtDayXem2[x] << " ";
        Print << vtDayXem2[x] << " ";
    }
    Read.close();
    Print.close();
    return 0;
};
