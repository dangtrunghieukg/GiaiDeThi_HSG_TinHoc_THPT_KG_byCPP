#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> vtXn;

string FXn(int x, int &k){
    vtXn.clear();
    vtXn.push_back(x);
    bool daCo=false; string strTemp="";
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
        ketQua = ketQua  + to_string(vtXn[i]) + " ";
    }
    k=vtXn.size();
    return ketQua;
}
int main(){
    int a, b, x=4;
    ifstream MyReadFile("TEST.INP");
    ofstream MyOutFile("TEST.OUT");
    MyReadFile>>a;
    MyReadFile>>b;
   int doDai=0;
   int chieudaiMax=0;
   int demdong=0;
   int tam=0;
   for( int i=a; i<b; i++ ){
       FXn(i, tam);
        if(chieudaiMax<tam){
            chieudaiMax=tam;
        }
    }
    //cout<<chieudaiMax<<endl;
    MyOutFile<<chieudaiMax<<endl;
    string chuoiXuat="";
    string tam2="";
    for( int i=a; i<b; i++ ){
       tam2=FXn(i, tam);
        if(chieudaiMax==tam){
            chuoiXuat=chuoiXuat+tam2+"\n";
            demdong++;
        }
    }
    //cout<<demdong<<endl;
    MyOutFile<<demdong<<endl;

    //cout<<chuoiXuat;
    MyOutFile<<chuoiXuat<<endl;

    MyReadFile.close();
return 0;
}
