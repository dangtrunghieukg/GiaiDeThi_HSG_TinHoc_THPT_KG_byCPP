#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream Read("PN2SND.INP");
    ofstream Print("PN2SND.OUT");
    long long a,b;
    long long tam=0, dem=0;
    long long chuSo=0;
    long long tich=0;
    string strDem="            ";
    Read >> a;
    Read >> b;
    cout << "  " << a << endl << "x" << endl << "  " << b << endl;
    cout << "----" << endl;
    tam=a;
    while(tam!=0){
        tam=tam/10;
        dem++;
    }
    tam=b;
    while(tam!=0){
        chuSo=tam%10;
        tich=chuSo*a;
        cout << " " << tich << endl;
        if(tich==0){
            for(int i=1; i<=dem; i++){
                cout << "0";
            }
        }
        tam=tam/10;
    }
    cout << "----" << endl;
    cout << a*b;
    return 0;
}
