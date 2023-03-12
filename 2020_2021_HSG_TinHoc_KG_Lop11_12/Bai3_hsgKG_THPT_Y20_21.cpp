#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int N,d;
    ifstream Read("AMUSIC.INP");
    ofstream Out("AMUSIC.OUT");
    Read>>N;
    Read>>d;
    cout<<N<<" "<<d<<endl;
    int iTemp;
    vector<int>vtTi, vtZi,vtDayXem, vtXem2;
    for(int i=1; i<=N; i++){
        Read>>iTemp;
        vtTi.push_back(iTemp);
    }
    for(int i=1; i<=N; i++){
        Read>>iTemp;
        vtZi.push_back(iTemp);
    }
    for(int x:vtTi) cout << x << " "; cout << endl;
    for(int x:vtZi) cout << x << " "; cout << endl;
    for(int i=1; i<=N; i++){
        int max_i=0;
        if(i>=d){
            for(int j=0; j<vtTi.size();j++){
                if(vtTi[j]==i){
                    if(max_i<vtZi[j]){
                        max_i=vtZi[j];
                    }
                }
            }
            for(int j=0; j<vtTi.size(); j++){
                if(vtZi[j]==max_i && max_i>0){
                    vtDayXem.push_back(j+1);
                }
            }
        }
    }
    for(int x: vtDayXem){
        if( x!=1){
            vtXem2.push_back(x);
        }else{
            vtXem2.push_back(x);
            vtXem2.push_back(x+2);
        }
    }
    int tongQua=0;
    for(int i=0; i<vtXem2.size(); i++){
        tongQua+=vtZi[vtXem2[i]-1];
    }
    cout<<tongQua<<endl;
    Out<<tongQua<<endl;
    for(int i=0; i<vtXem2.size(); i++){
        cout<<vtXem2[i]<<" ";
        Out<<vtXem2[i]<<" ";
    }
    cout<<endl;
    Out<<endl;

    Read.close();
    Out.close();

return 0;
}
