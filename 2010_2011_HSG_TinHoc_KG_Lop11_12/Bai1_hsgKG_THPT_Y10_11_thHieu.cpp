#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <string> vtDaySo;
vector <int> vtTich;
int n;
void XuatPhanTich(vector<int> vtInput){
    string chuoiTam = to_string(vtInput[0]);
    int kqTich = vtInput[0];
    for(int i=1; i<vtInput.size(); i++){
        chuoiTam = chuoiTam + " " + to_string(vtInput[i]);
        kqTich *= vtInput[i];
    }
    vtDaySo.push_back(chuoiTam);
    vtTich.push_back(kqTich);
}
void PhanTichRaTong(int N, vector<int> vtPT){
    if(N==0){
        XuatPhanTich(vtPT);
        return;
    }
    int i=1;
    if(!vtPT.empty()){
        i = vtPT.back() + 1;
    }
    for(; i<=N; i++){
        vector<int> newVtPT(vtPT);
        newVtPT.push_back(i);
        PhanTichRaTong(N-i, newVtPT);
    }
}

int main(){
    ifstream ReadFile("PHANTICH.INP");
    ofstream WriteFile("PHANTICH.OUT");
    ReadFile >> n;
    PhanTichRaTong(n, vector<int>());
    int tichMax = 0;
    for(int i=0; i<vtDaySo.size(); i++){
        if(tichMax < vtTich[i]) tichMax = vtTich[i];
    }
    for(int i=0; i<vtDaySo.size(); i++){
        if(vtTich[i]==tichMax){
            cout << vtDaySo[i] << endl;
            WriteFile << vtDaySo[i];
        }
    }
    ReadFile.close();
    WriteFile.close();
    return 0;
}