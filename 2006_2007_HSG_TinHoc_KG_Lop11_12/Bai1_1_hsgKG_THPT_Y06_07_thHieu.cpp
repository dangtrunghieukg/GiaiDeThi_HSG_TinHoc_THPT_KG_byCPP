#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<float> vtGiaTriPhanSo={0};
int N, tuSo, mauSo, ketQua = 3;
float fTemp, phanSoInput;
bool daCo = false;
int main(){
    ifstream MyReadFile("PHANSO.INP");
    ofstream MyOutFile("PHANSO.OUT");
    MyReadFile >> N;
    MyReadFile >> tuSo;
    MyReadFile >> mauSo;
    phanSoInput = (float)tuSo/(float)mauSo;
    //Duyệt qua tất cả các phân số và chỉ thêm vào vector các phân số có giá trị khác nhau
    for(int i=N; i>=1; i--){
        for(int j = 1; j<i; j++){
            fTemp = (float)j/(float)i;
            for(int k=1; k<vtGiaTriPhanSo.size(); k++){
                if(fTemp == vtGiaTriPhanSo[k]){
                    daCo = true;
                    break;
                }
            }
            //Nếu là phân số mới thì thêm nó vào phần tử cuối của Vector
            if(!daCo){
                vtGiaTriPhanSo.push_back((float)j/i);
            }
            daCo = false;
        }
    }
    //Sắp xếp các phần tử của Vector (có thể dùng sort nhanh hơn, nhưng nhúng thêm thư viện)
    for(int i=1; i<vtGiaTriPhanSo.size(); i++){
        for(int j=i; j<vtGiaTriPhanSo.size(); j++){
            if(vtGiaTriPhanSo[i]>vtGiaTriPhanSo[j]){
                fTemp = vtGiaTriPhanSo[i];
                vtGiaTriPhanSo[i] = vtGiaTriPhanSo[j];
                vtGiaTriPhanSo[j] = fTemp;
            }
        }
    }
    for(int i=1; i<vtGiaTriPhanSo.size(); i++){
        if(vtGiaTriPhanSo[i]==phanSoInput){
            ketQua = i;
            break;
        }
    }
    //Xuất kết quả vào file PHANSO.OUT
    MyOutFile << ketQua;
    MyReadFile.close();
    return 0;
}