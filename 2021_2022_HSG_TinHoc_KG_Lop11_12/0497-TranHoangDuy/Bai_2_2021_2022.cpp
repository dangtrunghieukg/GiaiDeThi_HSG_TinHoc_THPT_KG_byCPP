#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ifstream Read("FPOS.INP");
    ofstream Print("FPOS.OUT");
    unsigned long long N;
    Read >> N;
    string chuoi=to_string(N);
    int len=chuoi.length();
    bool f=false;
    int dem=1;
    string daySo="";
    string tam="";
    while(f==false){
        for(int i=0; i<daySo.length(); i++){
            if(chuoi[0]-48==daySo[i]-48){
                for(int j=0; j<len-1; j++){
                    tam+=daySo[i+j];
                    cout << tam;
                }
                bool k=false;
                int m=0;
                while(k==false){
                    if(tam[m]!=chuoi[i+m]){
                        k=true;
                        Print << chuoi[1]-48 << chuoi[0]-48;
                        break;
                    }
                }
            }
        }
        break;
        daySo=daySo+to_string(dem);
        dem++;
    }
    cout << daySo;
    return 0;
}
