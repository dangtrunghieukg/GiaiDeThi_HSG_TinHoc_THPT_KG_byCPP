#include <iostream>
#include <fstream>
using namespace std;
long long uvc[1001][4];
int main() {
    ifstream readFile("TG.INP");
    ofstream writeFile("TG.OUT");
    int N, M, K, k1, k2, k3;
    readFile >> N >> M >> K;
    readFile >> k1 >> k2 >> k3;
    cout << "--- Input data ---\n";
    cout << N << " " << M << " " << K << endl;
    cout << k1 << " " << k2 << " " << k3 << endl;
    for (int i = 1; i <= M; i++) {
        readFile >> uvc[i][1] >> uvc[i][2] >> uvc[i][3];
    }
    //Kiểm tra xem đọc dữ liệu ok chưa
    for (int i = 1; i <= M; i++) {
        cout << uvc[i][1] << " " << uvc[i][2] << " " << uvc[i][3] << endl;
    }
    cout << "--- Output data ---\n";
    long cMin = 1000000000;
    int cMin_index;
    for (int i = 0; i <= M; i++) {
        if (k1 == uvc[i][1] && cMin > uvc[i][3]) {
            cMin = uvc[i][3];
            cMin_index = i;
        }
    }
    cout << cMin;
    readFile.close();
    writeFile.close();
    return 0;
}