#include <iostream>
#include <fstream>
using namespace std;
bool TimChuoiCon(string strMe, string strCon){
    if (strMe.length() < strCon.length()) return false;
    bool timOk = false;
    strMe = strMe + " ";
    string strTemp = "";
    for (int i = 0; i < strMe.length() - strCon.length(); i++){
        for (int j = i; j < i + strCon.length(); j++) {
            strTemp += strMe[j];
        }
        if (strCon == strTemp){
            timOk = true;
            break;
        }
        strTemp = "";
    }
    return timOk;
}
int main() {
    ifstream ReadFile("FPOS.INP");
    ofstream WriteFile("FPOS.OUT");
    string strN;
    getline(ReadFile, strN);
    cout << strN << endl;
    string strS = "";
    bool daTimGap = false;
    for(int i = 1; i <= 1000000; i++) {
        strS += to_string(i);
        if (TimChuoiCon(strS, strN)) {
            strS = "";
            for (int j = i; j >=1; j--){
                strS = to_string(j)+strS;
                if (TimChuoiCon(strS, strN)){
                    cout << strS << endl;
                    cout << j << endl;
                    WriteFile << j << endl;
                    daTimGap = true;
                    break;
                }
            }
        }
        if (daTimGap) break;
    }
    ReadFile.close();
    WriteFile.close();
    return 0;
}