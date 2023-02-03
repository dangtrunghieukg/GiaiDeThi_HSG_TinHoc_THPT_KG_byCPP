#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
string FXn(int x, int &k);
string doc;
int a, b, x=7;
vector<int> vtXn;

int main(){
    ifstream MyReadFile("TEST.INP");
    ofstream MyOutFile("TEST.OUT");
    MyReadFile >> a;
    MyReadFile >> b;
    int doDai=0;
    string chuoi=FXn(x, doDai);
    int chieuDaiMax=0;
    int tam=0;
    int demDong=0;
    for(int i=a; i<=b; i++){
        FXn(i, tam);
        if(chieuDaiMax<tam){
            chieuDaiMax=tam;
        }
    }
    //cout << chieuDaiMax << endl;
    MyOutFile << chieuDaiMax << endl;
    string chuoiXuat="";
    string tam2="";
    for(int i=a; i<=b; i++){
        tam2=FXn(i, tam);
        if(chieuDaiMax==tam){
            chuoiXuat=chuoiXuat+tam2+"\n";
            demDong++;
        }
    }
    //cout << demDong << endl << chuoiXuat;
    MyOutFile << demDong << endl << chuoiXuat;
    return 0;
}



string FXn(int x, int &k){
    vtXn.clear();
    vtXn.push_back(x);
    bool daCo=false;
    string strTemp="";
    int tongBinh=0;
    while(!daCo){
        strTemp=to_string(x);
        for(int i=0; i<strTemp.length(); i++){
            tongBinh+=(strTemp[i]-48)*(strTemp[i]-48);
        }
        x=tongBinh;
        tongBinh=0;
        for(int i=0; i<vtXn.size(); i++){
            if(vtXn[i]==x){
                daCo=true;
                vtXn.push_back(x);
                break;
            }
        }
        if(daCo==false){
            vtXn.push_back(x);
        }
    }
    string ketQua="";
    for(int i=0; i<vtXn.size(); i++){
        ketQua = ketQua + to_string(vtXn[i]) + " ";
    }
    k=vtXn.size();
    return ketQua;
}
