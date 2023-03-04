#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream ReadFile("PN2SND.INP");
    ofstream OutFile("PN2SND.OUT");
    unsigned long long M, N, tich;
    ReadFile >> M;
    ReadFile >> N;
    tich = M*N;
    string strM, strN, strTich, strKhoangTrong = "";
    strM = to_string(M);
    strN = to_string(N);
    strTich = to_string(tich);
    for(int i=0; i< strTich.length() - strM.length(); i++){
        OutFile << " ";
        cout << " ";
    }
    OutFile << M << endl;
    cout << M << endl;
    for(int i=0; i< strTich.length() - 1; i++){
        OutFile << " ";
        cout << " ";
    }
    OutFile << "x" << endl;
    cout << "x" << endl;
    for(int i=0; i< strTich.length() - strN.length(); i++){
        OutFile << " ";
        cout << " ";
    }
    OutFile << N << endl;
    cout << N << endl;
    for(int i=0; i< strTich.length(); i++){
        OutFile << "-";
        cout << "-";
    }
    OutFile << endl;
    cout << endl;
    int demSpace = 0;
    for(int i = strN.length()-1; i>=0; i--){
        if (strN[i] == '0'){
            for(int j=0; j<strTich.length()-strM.length()-demSpace; j++){
                OutFile << " ";
                cout << " ";
            }
            for(int j=0; j<strM.length(); j++){
                OutFile << 0;
                cout << 0;
            }
            OutFile << endl;
            cout << endl;
        }else{
            int tichTemp = M * (strN[i]-48);
            string strTichTemp = to_string(tichTemp);
            for(int j=0; j<strTich.length()-strTichTemp.length()-demSpace; j++){
                OutFile << " ";
                cout << " ";
            }
            OutFile << tichTemp << endl;
            cout << tichTemp << endl;
        }
        demSpace++;
    }
    for(int i=0; i< strTich.length(); i++){
        OutFile << "-";
        cout << "-";
    }
    OutFile << endl << tich<< endl;
    cout << endl << tich<< endl;
    return 0;
}