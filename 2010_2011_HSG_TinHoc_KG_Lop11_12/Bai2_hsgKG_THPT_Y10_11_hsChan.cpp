#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream MyRead("PN2SND.INP");
    ofstream MyOut("PN2SND.OUT");
    unsigned long long a,b;
    MyRead>>a;
    MyRead>>b;
    string strB=to_string(b);

    cout<<"  "<<a<<endl;
    MyOut<<"  "<<a<<endl;
    cout<<"x"<<endl;
    MyOut<<"x"<<endl;
    cout<<"  "<<b<<endl;
    MyOut<<"  "<<b<<endl;
    cout<<"-----"<<endl;
    MyOut<<"-----"<<endl;
    for(int i=strB.length()-1; i>=0; i--){
        cout<<" "<<(strB[i]-48)*a<<endl;
        MyOut<<" "<<(strB[i]-48)*a<<endl;
    }
    cout<<"-----"<<endl;
    MyOut<<"-----"<<endl;
    cout<<a*b<<endl;
    MyOut<<a*b<<endl;
    MyRead.close();
    MyOut.close();
return 0;
}
