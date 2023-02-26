#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void FindSum(int N, string output);
int UCLN(int a, int b);
int BCNN(int a, int b);
vector<string>vtDaySo;
vector<int>vtBCNN;
int N;
int main(){
    ifstream Read("BOISO.INP");
    ofstream Print("BOISO.OUT");
    Read >> N;
    FindSum(N, "");
    for(int i=0; i<vtDaySo.size(); i++){
        string strTemp="";
        string strTemp_vtri=vtDaySo[i]+" ";
        int iBCNN=1;
        for(int j=0;j<strTemp_vtri.length(); j++){
            if(strTemp_vtri[j]==' '){
                iBCNN=BCNN(iBCNN, stoi(strTemp));
                strTemp= " ";
            }else{
                strTemp+=strTemp_vtri[j];
            }
        }
        vtBCNN.push_back(iBCNN);
    }
    int iBCNN_Max=1;
    for(int i=0; i<vtBCNN.size(); i++){
        if(iBCNN_Max<vtBCNN[i]) iBCNN_Max = vtBCNN[i];
    }
    for(int i=0; i<vtBCNN.size(); i++){
        if(iBCNN_Max == vtBCNN[i]){
            cout << iBCNN_Max << endl;
            cout << vtDaySo[i];
            break;
        }
    }
    return 0;
}
void FindSum(int N, string output){
    if(N==0){
        cout << output << endl;
        vtDaySo.push_back(output);
        return;
    }
    for(int i=1; i<=N; i++){
        if(output==""){
            FindSum(N-i, to_string(i) + output);
        }
        else if(i<=stoi(output.substr(0, 1))){
            FindSum(N-i, to_string(i) + " " + output);
        }
    }
}
int UCLN(int a, int b){
    int m, kq;
    if(a<b) m=a;
    else m=b;
    for(int i=m; i>0; --i){
        if (a%i==0 && b%i==0){
            kq=i;
            break;
        }
    }
    return kq;
}
int BCNN(int a, int b){
    return a/UCLN(a, b)*b;
}
