#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int N;
#define ptMax 1000001
int arrM[ptMax][4];
vector<int> vtThuTuCuocHop, vtThuTuCuocHopMax;

void CopyVector(vector<int>vtIn, vector<int>&vtOut){
    vtOut.clear();
    for(int i=0; i<vtIn.size(); i++){
        vtOut.push_back(vtIn[i]);
    }
}

int main() {
    ifstream MyReadFile("PHONGHOP3.INP");
    ofstream MyOutFile("PHONGHOP.OUT");
    MyReadFile >> N;
    for (int i = 1; i <= N; i++) {
        MyReadFile >> arrM[i][1];
        MyReadFile >> arrM[i][2];
        arrM[i][3]=i;
    }
    //Sắp xếp các cuộc họp theo thứ tự ưu tiên giờ bắt đầu từu bé tới lớn
    for(int i=0; i<N; i++){
        for(int j=i; j<=N; j++){
            if(arrM[i][1]>arrM[j][1]){
                swap(arrM[i][1], arrM[j][1]);
                swap(arrM[i][2], arrM[j][2]);
                swap(arrM[i][3], arrM[j][3]);
            }
        }
    }
    int demCuocHop=1, cuocHopMax=0;
    int timeBatDau, timeKetThuc;
    for (int i = 1; i < N; i++) {
        timeBatDau = arrM[i][1];
        timeKetThuc = arrM[i][2];
        vtThuTuCuocHop.clear();
        vtThuTuCuocHop.push_back(arrM[i][3]);
        for (int j = i + 1; j <= N; j++) {
            if (timeKetThuc <= arrM[j][1]){
                demCuocHop++;
                vtThuTuCuocHop.push_back(arrM[j][3]);
                if (cuocHopMax < demCuocHop ) {
                    cuocHopMax = demCuocHop;
                    CopyVector(vtThuTuCuocHop, vtThuTuCuocHopMax);
                }
                timeBatDau = arrM[j][1];
                timeKetThuc = arrM[j][2];
            }
        }
        demCuocHop = 1;
    }

    cout <<  cuocHopMax << endl;
    MyOutFile <<  cuocHopMax << endl;
    sort(vtThuTuCuocHopMax.begin(), vtThuTuCuocHopMax.end());
    for(int i=0; i<vtThuTuCuocHopMax.size(); i++){
        cout << vtThuTuCuocHopMax[i] << " ";
        MyOutFile << vtThuTuCuocHopMax[i] << " ";
    }
    MyReadFile.close();
    MyOutFile.close();
    return 0;
}