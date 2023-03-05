#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int n;
    string strLine;
    ifstream MyRead("CHUOI.INP");
    ofstream MyOut("CHUOI.OUT");
    MyRead>>n;
    cout<<n;
    for(int i=0; i<=n; i++){
        getline(MyRead, strLine);
        cout<<strLine<<endl;
    }
    return 0;
}
