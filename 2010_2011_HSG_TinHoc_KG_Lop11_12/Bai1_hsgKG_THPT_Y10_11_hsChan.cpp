#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> vtDaySo;
vector<int> vtTich;

void XuatPhanTich(vector<int> vtInput){
    string chuoiTam=to_string(vtInput[0]);
    int tich=vtInput[0];
    for(int i=1; i<vtInput.size(); i++){
        tich*=vtInput[i];
        chuoiTam=chuoiTam+" "+to_string(vtInput[i]);
    }
    vtDaySo.push_back(chuoiTam);
    vtTich.push_back(tich);
}

void PhanTichRaTong(int n, vector<int> vtPt){
    if(n==0){
        XuatPhanTich(vtPt);
        return;
    }
    int i=1;
    if(!vtPt.empty()){
        i=vtPt.back()+1;
    }
    for(; i<=n; i++){
        vector<int> newVtPt(vtPt);
        newVtPt.push_back(i);
        PhanTichRaTong(n-i, newVtPt);
    }
}

int M;
int main(){
    int n=155;
    ifstream Read("PHANTICH.INP");
    ofstream Out("PHANTICH.OUT");
    Read>>M;
    PhanTichRaTong(M, vector<int>());
    int tichMax=0;
    for(int i=0; i<vtDaySo.size(); i++){
        if(tichMax < vtTich[i]) tichMax=vtTich[i];
    }
    for(int i=0; i<vtDaySo.size(); i++){
        if(vtTich[i]==tichMax)
        cout<<vtDaySo[i];
    }
    Read.close();
    Out.close();
return 0;
}
