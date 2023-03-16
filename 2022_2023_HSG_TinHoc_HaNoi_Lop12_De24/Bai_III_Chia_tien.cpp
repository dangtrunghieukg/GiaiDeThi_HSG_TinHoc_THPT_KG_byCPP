#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//Thủ tục này xuất phần tử vector cho nhanh
void Xuat(vector<int> X) {
    for (int x : X) cout << x << " ";
    cout << endl;
}
//Thủ tục này đặt lại giá trị của các phần tử vector bằng 0
void Reset(vector<int> &vtA) {
    for (int i = 0; i < vtA.size(); i++) vtA[i]=0;
}
//Nếu số n có thể phân tích thành tổng một số phần tử trong vector thì trả về ok, không thì false
bool PhanTich(vector<int>vtI, int n) {
    sort(vtI.rbegin(), vtI.rend());
    bool chiaOk = false;
    int tienConLai = n;
    for (int i = 0; i < vtI.size(); i++) {
        for (int j = i; j < vtI.size(); j++) {
            if (tienConLai >= vtI[j]) {
                tienConLai = tienConLai - vtI[j];
            }
            if (tienConLai == 0) break;
        }
        if (tienConLai == 0) {
            chiaOk = true;
            break;
        }
        tienConLai = n;
    }
    return chiaOk;
}
vector<int> vtToTien, vtToTien2, vtDaChon;
int main() {
    ifstream ReadFile("CT.INP");
    ofstream WirteFile("CT.OUT");
    int N, iTemp, tongTien=0, tbTien;
    ReadFile >> N;
    //Nạp các mệnh giá tờ tiền vào vector vtToTien và đánh dấu các tờ tiền chưa chọn 0 trong vtDaChon
    for (int i = 1; i <= N; i++){
        ReadFile >> iTemp;
        vtToTien.push_back(iTemp);
        tongTien += iTemp;
        vtDaChon.push_back(0);
    }
    //Sắp xếp phần tử của Vector từ Lớn đến bé
    sort(vtToTien.rbegin(), vtToTien.rend());
    //Xuất kiểm tra xem ok chưa
    cout << "Sort tien: ";
    Xuat(vtToTien);

    //Ta dễ dàng nhận thấy số tiền Max không thể vượt quá Tổng số tiền / 2
    int tienMax = tongTien/2;
    int tienConLai = tienMax;
    bool daChiaOk = false;

    for(int tMax = tienMax; tMax >= 1; tMax--){
        tienConLai = tMax;
        for(int i = 0; i < vtToTien.size(); i++) {
            for (int j = i; j < vtToTien.size(); j++) {
                if (tienConLai >= vtToTien[j]) {
                    tienConLai -= vtToTien[j];
                    vtDaChon[j] = 1;
                }
                if (tienConLai == 0) break;
            }
            if (tienConLai == 0) {
                //Chia cho An ok, bắt đầu kiểm tra xem chia cho Bình hết không
                vtToTien2.clear();
                for(int k = 0; k < vtDaChon.size(); k++){
                    if (vtDaChon[k] == 0) {
                        vtToTien2.push_back(vtToTien[k]);
                    }
                }
                //Nếu chia cho Bình = true thì xuất.
                if (PhanTich(vtToTien2, tMax) == true) {
                    daChiaOk = true;
                    break;
                }
            }
            if (daChiaOk) break;
            Reset(vtDaChon);
            tienConLai = tMax;
        }
        if (daChiaOk) {
            cout << "Tien max: " << tMax << endl;
            WirteFile << tMax;
            break;
        }
    }
    ReadFile.close();
    WirteFile.close();
    return 0;
}