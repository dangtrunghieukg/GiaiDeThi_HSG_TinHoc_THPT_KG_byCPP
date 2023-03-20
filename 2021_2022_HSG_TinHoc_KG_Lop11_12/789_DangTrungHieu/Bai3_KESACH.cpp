#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int Hi[2001], Wi[2001];
int main() {
    ifstream ReadFile("KESACH.INP");
    ofstream WriteFile("KESACH.OUT");
    int N, L;
    ReadFile >> N >> L;
    cout << N << " " << L <<"\n";
    int hBookMax = -1, hBookMin = 1000000000, wBookMax = -1, wBookMin = 1000000000;
    for (int i = 1; i <= N; i++) {
        ReadFile >> Hi[i] >> Wi[i];
        cout << Hi[i] << " " << Wi[i] << endl;
        if (hBookMax < Hi[i]) hBookMax = Hi[i];
        if (hBookMin > Hi[i]) hBookMin = Hi[i];
        if (wBookMax < Wi[i]) wBookMax = Wi[i];
        if (wBookMin > Wi[i]) wBookMin = Wi[i];
    }
    cout << "h book max: " << hBookMax << " ; h book min: " << hBookMin << endl;
    cout << "w book max: " << wBookMax << " ; w book min: " << wBookMin << endl;
    int wideMax = 0;
    int hKeSachMax = 0;
    int tongChieuCao = 0;
    for (int i = wBookMin; i <= wBookMax; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == Wi[j]){
                if (wideMax + i <= L) {
                    wideMax +=i;
                    cout << i << " ";
                    if (hKeSachMax < Hi[j]) {
                        hKeSachMax = Hi[j];
                    }
                }
            }
            if (wideMax + i > L) {
                cout << ": " << wideMax << endl;
                tongChieuCao += hKeSachMax;
                hKeSachMax = 0;
                wideMax = 0;
            }
        }
    }
    cout << "Hight Book Min: " << tongChieuCao;
    WriteFile << tongChieuCao;
    ReadFile.close();
    WriteFile.close();
    return 0;
}