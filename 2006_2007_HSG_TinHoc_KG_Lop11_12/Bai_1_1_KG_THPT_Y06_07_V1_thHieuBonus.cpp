#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> vtTuSo = {0};
vector<int> vtMauSo = {1};
vector<float> vtGiaTriPhanSo={0};
int UCLN(int a, int b);
void DonGianPhanSo(int &tuSo, int &mauSo);
string myText;
int N, tuSo, mauSo, ketQua = 3;
float fTemp, phanSoInput;
int iTemp, tempTu, tempMau;
bool daCo = false;
int main(){
    ifstream MyReadFile("PHANSO.INP");
    ofstream MyOutFile("PHANSO.OUT");
    MyReadFile >> N;
    MyReadFile >> tuSo;
    MyReadFile >> mauSo;
    phanSoInput = (float)tuSo/(float)mauSo;
    for(int i=N; i>=1; i--){
        for(int j = 1; j<i; j++){
            fTemp = (float)j/(float)i;
            for(int k=1; k<vtGiaTriPhanSo.size(); k++){
                if(fTemp == vtGiaTriPhanSo[k]){
                    daCo = true;
                    break;
                }
            }
            if(!daCo){
                tempTu = j;
                tempMau = i;
                DonGianPhanSo(tempTu, tempMau);
                vtTuSo.push_back(tempTu);
                vtMauSo.push_back(tempMau);
                vtGiaTriPhanSo.push_back((float)j/i);
            }
            daCo = false;
        }
    }
    for(int i=1; i<vtGiaTriPhanSo.size(); i++){
        for(int j=i; j<vtGiaTriPhanSo.size(); j++){
            if(vtGiaTriPhanSo[i]>vtGiaTriPhanSo[j]){
                fTemp = vtGiaTriPhanSo[i];
                vtGiaTriPhanSo[i] = vtGiaTriPhanSo[j];
                vtGiaTriPhanSo[j] = fTemp;
                iTemp = vtTuSo[i];
                vtTuSo[i] = vtTuSo[j];
                vtTuSo[j] = iTemp;
                iTemp = vtMauSo[i];
                vtMauSo[i] = vtMauSo[j];
                vtMauSo[j] = iTemp;
            }
        }
    }
    for(int i=1; i<vtGiaTriPhanSo.size(); i++){
        if(vtGiaTriPhanSo[i]==phanSoInput){
            ketQua = i;
            break;
        }
    }
    MyOutFile << ketQua;
    MyReadFile.close();

    for(int i=1; i<vtGiaTriPhanSo.size(); i++){
        cout << "(" << i << ") " << vtTuSo[i] << "/" << vtMauSo[i];
        if(phanSoInput == vtGiaTriPhanSo[i]){
            cout << " <--> " << vtTuSo[i] << "/" << vtMauSo[i] << " (phan so nhap)" << endl;
        }else{
            cout << endl;
        }
    }
    return 0;
}

int UCLN(int a, int b){
    int soLon=a, soBe=b, kq=1;
    if(a<b){
        soLon = b;
        soBe = a;
    }
    for(int i=soBe; i>=1; i--){
        if(soBe % i == 0 && soLon % i == 0){
            kq = i;
            break;
        }
    }
    return kq;
}
void DonGianPhanSo(int &tuSo, int &mauSo){
    int a = tuSo, b = mauSo;
    tuSo = tuSo/UCLN(a, b);
    mauSo = mauSo/UCLN(a, b);
}
