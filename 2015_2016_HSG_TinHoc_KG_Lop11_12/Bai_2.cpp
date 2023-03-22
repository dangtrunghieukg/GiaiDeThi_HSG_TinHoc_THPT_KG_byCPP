#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream Read("LAMA.INP");
    ofstream Print("LAMA.OUT");
    string chuoi="";
    Read >> chuoi;
    int M=1000, D=500, C=100, L=50, X=10, V=5, I=1, tong;
    for(int i=0; i<chuoi.length(); i++){
        switch(chuoi[i]){
            case 'M':
                tong+=M;
                break;
            case 'D':
                tong+=D;
                break;
            case 'C':
                tong+=C;
                break;
            case 'L':
                tong+=L;
                break;
            case 'X':
                tong+=X;
                break;
            case 'V':
                tong+=V;
                break;
            case 'I':
                tong+=I;
                break;
        }
    }
    cout << tong;
    Print << tong;
    Read.close();
    Print.close();
    return 0;
}
