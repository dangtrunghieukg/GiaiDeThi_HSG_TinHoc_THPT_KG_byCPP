#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <int> vtBCNN;
vector <string> vtDaySo;

void XuatPhanTich(vector<int> vtInput){
    string chuoitam=to_string(vtInput[0]);
    for(int i=0; i<vtInput.size();i++){
        chuoitam=chuoitam+" "+to_string(vtInput[i]);
    }
    vtDaySo.push_back(chuoitam);
}

void PhanTichRaTong(int N, vector<int> vtPt){
    if(N==0){
        XuatPhanTich(vtPt);
        return;
    }
    int i=1;
    if(!vtPt.empty()){
        i=vtPt.back() + 1;
    }
    for(int i=0; i<=N;i++){
        vector<int> newVtPt(vtPt);
        newVtPt.push_back(i);
        PhanTichRaTong(N-i, newVtPt);
    }
}
int UCLN(int a, int b){
    int soLon, soBe;
    if(a<=b){
        soBe=a;
        soLon=b;
    }else{
        soBe=b;
        soLon=a;
    }
    for(int i=soBe; i>=1;i--){
        if(soLon%i==0 & soBe%i==0){
            return i;
            break;
        }
    }
}
int BCNN(int a, int b){
    return a/UCLN(a,b)*b;
}
int main(){
    ifstream MyReadFile("BOISO.INP");
    ofstream MyOutFile("BOISO.OUT");
    MyReadFile>>n;
    PhanTichRaTong(n, vector<int>());
    for(int i=0; i<vtDaySo.size(); i++){
        string strTemp="";
        string strTemp_vti=vtDaySo[i] + " ";
        int iBCNN = 1;
        for(int j=0;j<strTemp_vti.length(); j++){
            if(strTemp_vti[j]==' '){
                iBCNN=BCNN(iBCNN, stoi(strTemp));
                strTemp="";
            }else{
                strTemp+=strTemp_vti[j];
            }
        }
        vtBCNN.push_back(iBCNN);
    }
    int iBCNN_Max=1;
    for(int i=0;i<vtBCNN.size();i++){
        if( iBCNN_Max<vtBCNN[i]) iBCNN_Max=vtBCNN[i];
    }
    for( int i=0; i<vtBCNN.size(); i++){
        if(iBCNN_Max==vtBCNN[i]){
            cout<<iBCNN_Max<<endl;
            MyOutFile<<iBCNN_Max<<endl;
            cout<<vtDaySo[i];
            MyOutFile<<vtDaySo[i];
            break;
        }
    }
    MyReadFile.close();
    MyOutFile.close();

return 0;
}
