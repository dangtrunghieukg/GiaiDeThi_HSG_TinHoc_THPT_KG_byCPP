#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vtInputString;
int n;
string strLine;
int main() {
    ifstream ReadFile("CHUOI.INP");
    ofstream OutFile("CHUOI.OUT");
    ReadFile >> n;
    for(int i=1; i<=n+1; i++){
        getline(ReadFile, strLine);
        if(strLine.length()>0){
            vtInputString.push_back(strLine);
        }
    }
    cout << "---- Input Data ---" << endl;
    for(string x : vtInputString) {
        cout << x << endl;
    }
    cout << "--- Output Data ---" << endl;
    int dem = 1;
    sort(vtInputString.begin(), vtInputString.end());
    vtInputString.push_back("##");
    for(int i=0; i<vtInputString.size()-1; i++){
        if (vtInputString[i]==vtInputString[i+1]){
            dem++;
        }else {
            if ( dem % 2 == 0){
                dem = 1;
            }else {
                cout << vtInputString[i] << endl;
                OutFile << vtInputString[i] << endl;
            }
        }
    }
    ReadFile.close();
    OutFile.close();
    return 0;
}