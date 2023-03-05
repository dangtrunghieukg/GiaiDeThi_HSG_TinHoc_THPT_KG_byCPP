#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
int arrMang[101][3];
using namespace std;
int main(){
    int n,m;
    ifstream MyRead("QUANDAO.INP");
    ofstream MyOut("QUANDAO.OUT");
    MyRead>>n;
    MyRead>>m;
    //cout<<n<<" "<<m<<endl;
    for(int i=1; i<=m; i++){
        MyRead>>arrMang[i][1];
        MyRead>>arrMang[i][2];
        //cout<<arrMang[i][1]<<" "<<arrMang[i][2]<<endl;
    }
    cout<<"out put data"<<endl;
    vector <int> vtQD;
    vector <int> vtQDFinal;
    vector <int> vtQDFinalGoc;
    vector <string> vtKQ;
    for(int i=1;i<m; i++){
        vtQD.clear();
        vtQD.push_back(arrMang[i][1]);
        vtQD.push_back(arrMang[i][2]);
        for(int j=i+1; j<=m; j++){
            bool themOk=false;
            for(int x:vtQD){
                if(x==arrMang[j][1] || x==arrMang[j][2]){
                    themOk=true;
                    break;
                }
            }
            if(themOk){
                vtQD.push_back(arrMang[j][1]);
                vtQD.push_back(arrMang[j][2]);
            }
        }
        vtQDFinal.clear();
        sort(vtQD.begin(), vtQD.end());
        for(int k=0; k<vtQD.size(); k++){
            if(vtQD[k]!=vtQD[k+1]){
                vtQDFinal.push_back(vtQD[k]);
            }
        }
        string strXuatKq="";
        if(vtQDFinalGoc.size()==0){
            for(int k=0; k<vtQDFinal.size();k++){
                //cout<<vtQDFinal[k]<<" ";
                strXuatKq+=to_string(vtQDFinal[k])+ " ";
                vtQDFinalGoc.push_back(vtQDFinal[k]);
            }
            //cout<<strXuatKq<<endl;
            vtKQ.push_back(strXuatKq);
            strXuatKq="";
        }
        bool xuatOk=true;
        for(int x: vtQDFinalGoc){
            for(int k=0; k<vtQDFinal.size(); k++){
                if(x==vtQDFinal[k]){
                    xuatOk=false;
                    break;
                }
            }
            if(xuatOk==false) break;
        }
        strXuatKq="";
        if(xuatOk==true){
            vtQDFinalGoc.clear();
            for(int k=0; k<vtQDFinal.size();k++){
                //cout<<vtQDFinal[k]<<" ";
                vtQDFinalGoc.push_back(vtQDFinal[k]);
                strXuatKq+=to_string(vtQDFinal[k])+ " ";
            }
            vtKQ.push_back(strXuatKq);
        }
    }
    for(int i=0; i<vtKQ.size(); i++){
        cout<<"Quan dao thu "<<i+1<<": "<<vtKQ[i]<<endl;
        MyOut<<"Quan dao thu "<<i+1<<": "<<vtKQ[i]<<endl;
    }
    MyRead.close();
    MyOut.close();
    return 0;
}
