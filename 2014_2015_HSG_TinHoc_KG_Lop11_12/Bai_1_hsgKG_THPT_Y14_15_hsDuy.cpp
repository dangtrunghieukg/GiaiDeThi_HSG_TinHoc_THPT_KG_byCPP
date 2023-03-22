#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream Read("GIAIMA.INP");
    ofstream Print("GiAIMA.OUT");
    string chuoi="";
    Read >> chuoi;
    cout << chuoi << endl;
    string chuoi2="";
    for(int i=1; i<chuoi.length(); i++){
        chuoi2+=chuoi[i];
    }
    long soNhiPhan=stoi(chuoi2);
    long soThapPhan=0;
    long tam=0;
    long tachSo=0;
    while(soNhiPhan!=0){
        tachSo=soNhiPhan%10; // tách số.
        soNhiPhan=soNhiPhan/10; // xóa số đã xử lí.
        soThapPhan=soThapPhan+tachSo*pow(2, tam);
        tam++;
    }
    if(chuoi[0]==1){
        cout << "-" << soThapPhan;
        Print << "-" << soThapPhan;
    }else{
        cout << soThapPhan;
        Print << soThapPhan;
    }
    Read.close();
    Print.close();
    return 0;
}
