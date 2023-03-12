#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

    ifstream Read("CHUOI.INP");
    ofstream Print("CHUOI.OUT");
    vector <string> vtChuoi;
    vector <string> vtDem;
    vector <int> vtSoLanXuatHien;
int main(){
    int N;
    Read >> N;
    string text="";
    while(!Read.eof()){
        getline(Read, text);
        vtChuoi.push_back(text);
    }
    string tam="";
    for(int i=1; i<vtChuoi.size(); i++){
        for(int j=i+1; j<vtChuoi.size(); j++){
            if(vtChuoi[j]<vtChuoi[i]){
                tam=vtChuoi[i];
                vtChuoi[i]=vtChuoi[j];
                vtChuoi[j]=tam;
            }
        }
    }
    int dem=0;
    //vtDem.push_back(vtChuoi[1]);
    for(int i=0; i<vtChuoi.size(); i++){
        if(vtChuoi[i]!=vtChuoi[i+1]){
            vtDem.push_back(vtChuoi[i]);
        }
    }
    for(int i=0; i<vtDem.size(); i++){
        for(int j=1; j<vtChuoi.size(); j++){
            if(vtDem[i]==vtChuoi[j]){
                dem++;
            }
        }
        vtSoLanXuatHien.push_back(dem);
        dem=0;
    }
    for(int i=1; i<vtChuoi.size(); i++){
        cout << vtChuoi[i] << endl;
    }
    cout << endl;
    for(int i=1; i<vtDem.size(); i++){
        cout << vtDem[i] << endl;
    }
    cout << endl;
    for(int i=0; i<vtSoLanXuatHien.size(); i++){
        if(vtSoLanXuatHien[i]%2 != 0){
            cout << vtDem[i];
        }
    }
    return 0;
}
