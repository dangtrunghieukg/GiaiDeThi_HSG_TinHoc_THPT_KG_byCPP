#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream ReadFile("TAITRONG2.INP");
    ofstream OutFile("TAITRONG.OUT");
    int N, startPos, endPos;
    int arrN[101][101];
    ReadFile >> N;
    ReadFile >> startPos;
    ReadFile >> endPos;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ReadFile >> arrN[i][j];
        }
    }
    //Xuất dữ liệu kiểm tra đọc thành công chưa
    cout << "--- Input data --- " << endl;
    cout << N << " " << startPos << " " << endPos << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << arrN[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--- Output data --- " << endl;
    int dangDi = startPos;
    int taiTrongMax=0;
    vector<int> vtTaiTrongMax;
    vector<int> vtConDuong;
    vtConDuong.push_back(startPos);
    while (dangDi < endPos){
        int columMax=0;
        for(int i=1; i<=N; i++){
            if(taiTrongMax<=arrN[dangDi][i]){
                taiTrongMax = arrN[dangDi][i];
            }
        }
        for(int i=1; i<=N; i++){
            if(taiTrongMax == arrN[dangDi][i]){
                if(columMax<i){
                    columMax =i;
                }
            }
        }
        for(int i=1; i<=N; i++){
            bool ok = true;
            if (taiTrongMax == arrN[dangDi][i] && i==columMax){
                for(int x:vtConDuong){
                    if(x == i){
                        ok = false;
                        break;
                    }
                }
                if(ok == true){
                    dangDi = i;
                    vtConDuong.push_back(dangDi);
                    break;
                }
            }
        }
        vtTaiTrongMax.push_back(taiTrongMax);
        taiTrongMax = 0;
    }//end while
    taiTrongMax = 0;
    for(int x : vtTaiTrongMax){
        if (taiTrongMax < x) taiTrongMax = x;
    }
    cout << taiTrongMax << endl;
    OutFile << taiTrongMax << endl;
    for(int i=0; i<vtConDuong.size(); i++){
        cout << vtConDuong[i] << " ";
        OutFile << vtConDuong[i] << " ";
    }
    ReadFile.close();
    OutFile.close();
    return 0;
}