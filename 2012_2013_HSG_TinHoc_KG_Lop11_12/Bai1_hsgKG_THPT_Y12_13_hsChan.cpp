#include <iostream>
#include <fstream>
using namespace std;
int n;
    string strLine;
    ifstream MyRead("CHUOI.INP");
    ofstream MyOut("CHUOI.OUT");

int main(){
    MyRead>>n;
    cout<<n;
    for(int i=0; i<=n; i++){
        getline(MyRead, strLine);
        cout<<strLine<<endl;
    }
    int dem;
    for(int i=0; i<=n;i++){
        dem=0;
        for(int j=0; j<=n; i++){
            if(strLine[i]==strLine[j]){
                dem++;
            }
        }
        if(dem%2==1) cout<<strLine[i]<<endl;
    }
    return 0;
}
