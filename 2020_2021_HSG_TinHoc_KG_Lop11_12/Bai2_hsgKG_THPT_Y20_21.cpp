#include <iostream>
#include <fstream>
using namespace std;
int arrN[101][101];
int main(){
    int N;
    ifstream MyRead("GRAB.INP");
    ofstream MyOut("GRAB.OUT");
    MyRead>>N;
    cout<<N<<endl;
    while(!MyRead.eof()){
        MyRead>>arrN[0][1];
        cout<<arrN[1][1]<<" ";
    }cout<<endl;
return 0;
}
