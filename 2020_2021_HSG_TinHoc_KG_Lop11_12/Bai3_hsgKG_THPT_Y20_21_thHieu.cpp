#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream ReadFile("AMUSIC.INP");
    ofstream WriteFile("AMUSIC.OUT");
    int N, d;
    ReadFile >> N;
    ReadFile >> d;
    cout << N << " " << d << endl;
    int iTemp;
    vector<int> vtTi, vtZi, vtDayXem;
    for(int i = 1; i <= N; i++){
        ReadFile >> iTemp;
        vtTi.push_back(iTemp);
    }
    for(int i = 1; i <= N; i++){
        ReadFile >> iTemp;
        vtZi.push_back(iTemp);
    }
    for(int x : vtTi) cout << x << " "; cout << endl;
    for(int x : vtZi) cout << x << " "; cout << endl;
    for (int i = 1; i <= N; i++){
        int max_i = 0;
        if ( i >= d) {
            for (int j = 0; j < vtTi.size(); j++){
                if (vtTi[j]==i){
                    if (max_i < vtZi[j]) {
                        max_i = vtZi[j];
                    }
                }
            }
            for (int j = 0; j < vtTi.size(); j++){
                if (vtZi[j]==max_i && max_i >0){
                    vtDayXem.push_back(j+1);
                }
            }
        }
    }
    for (int x : vtDayXem) cout << x << " "; cout << endl;
    ReadFile.close();
    WriteFile.close();
    return 0;
}