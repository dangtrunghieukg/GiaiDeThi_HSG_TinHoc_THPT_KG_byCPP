#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> vtDaySo;
vector<int>vtTich;
void XuatPhanTich(vector<int> vtInput);
void PhanTichRaTong(int N, vector<int> vtPT);
int main(){
    ifstream Read("PHANTICH.INP");
    ofstream Print("PHANTICH.OUT");
    int M;
    Read >> M;
    PhanTichRaTong(M, vector<int>());
    int soMax=0;
    for(int i=0; i<vtTich.size(); i++){
        if(soMax<vtTich[i]){
            soMax=vtTich[i];
        }
    }
    for(int i=0; i<vtTich.size(); i++){
        if(vtTich[i]==soMax){
            cout << vtDaySo[i];
        }
    }
    return 0;
}
void XuatPhanTich(vector<int> vtInput){
    string strTam=to_string(vtInput[0]);
    int kqTich=vtInput[0];
    for(int i=1; i<vtInput.size(); i++){
        strTam=strTam+" "+to_string(vtInput[i]);
        kqTich*=vtInput[i];
    }
    vtDaySo.push_back(strTam);
    vtTich.push_back(kqTich);
}
void PhanTichRaTong(int N, vector<int> vtPT){
    if(N==0){;
        XuatPhanTich(vtPT);
        return;
    }
    int i=1;
    if(!vtPT.empty()){
        i=vtPT.back()+1;
    }
    for(; i<=N; i++){
        vector<int> newVtPT(vtPT);
        newVtPT.push_back(i);
        PhanTichRaTong(N-i, newVtPT);
    }
}
