#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int arrN[101];
vector<string> vtKetQua;
int N, K;
string strTemp="";
void Xuat(){
    strTemp="";
    for(int i=1; i<=K; i++){
        strTemp+=to_string(arrN[i]);
    }
    sort(strTemp.begin(), strTemp.end());
    vtKetQua.push_back(strTemp);
}

void DeQuy(int i){
    for(int j=1; j<=N; j++){
        arrN[i]=j;
        if(i==K){
            Xuat();
        }else{
            DeQuy(i+1);
        }
    }
}

int main(){
    ifstream MyReadFile("MHANG.INP");
    ofstream MyOutFile("MHANG.OUT");
    MyReadFile >> N;
    MyReadFile >> K;

    DeQuy(1);
    sort(vtKetQua.begin(), vtKetQua.end());
    int demCachChon=0;
    for(int i=0; i<vtKetQua.size(); i++){
        if(vtKetQua[i]!=vtKetQua[i+1]) demCachChon++;
    }

    cout << "Co: " << demCachChon;
    MyOutFile << demCachChon;
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}

