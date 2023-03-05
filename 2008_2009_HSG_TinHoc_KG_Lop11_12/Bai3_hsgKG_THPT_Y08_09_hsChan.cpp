#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
#define ptMax 1000001
int arrM[ptMax][4];
vector<int> vtThuTuCuocHop, vtThuTuCuocHopMax;
void CoppyVector(vector<int>vtIn, vector<int>&vtOut){
    vtOut.clear();
    for(int i=0; i<vtIn.size(); i++){
        vtOut.push_back(vtIn[i]);
    }
}

int main()
{
    ifstream Read("PHONGHOP.INP");
    ofstream Out("PHONGHOP.OUT");
    Read>>N;
    for(int i = 1; i<=N; i++){
        Read>>arrM[i][1];
        Read>>arrM[1][2];
        arrM[i][3]=i;
    }
    for(int i=0; i<N; i++){
        for(int j=i; j<=N;j++){
            if(arrM[i][1]>arrM[j][1]){
                swap(arrM[i][1], arrM[j][1]);
                swap(arrM[i][2], arrM[j][2]);
                swap(arrM[i][3], arrM[j][3]);
            }
        }
    }
    int demCuocHop=1, cuocHopMax=0;
    int timeBD, timeKT;
    for(int i=1; i<N; i++){
        timeBD=arrM[i][1];
        timeKT=arrM[i][2];
        vtThuTuCuocHop.clear();
        vtThuTuCuocHop.push_back(arrM[i][3]);
        for(int j=i+1; j<=N;j++){
            if(timeKT<=arrM[j][1]){
                demCuocHop++;
                vtThuTuCuocHop.push_back(arrM[j][3]);
                if(cuocHopMax < demCuocHop){
                    cuocHopMax=demCuocHop;
                    CoppyVector(vtThuTuCuocHop, vtThuTuCuocHopMax);
                }
                timeBD=arrM[j][1];
                timeKT=arrM[j][2];
            }
        }
        demCuocHop=1;
    }
    cout<<cuocHopMax<<endl;
    Out<<cuocHopMax<<endl;
    sort(vtThuTuCuocHopMax.begin(), vtThuTuCuocHopMax.end());
    for(int i=0; i<vtThuTuCuocHopMax.size();i++){
        cout<<vtThuTuCuocHopMax[i]<<" ";
        Out<<vtThuTuCuocHopMax[i]<<" ";
    }
    Read.close();
    Out.close();
    return 0;
}
