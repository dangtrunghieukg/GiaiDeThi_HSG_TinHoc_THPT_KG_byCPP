#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int KhachHang[10001][2];
int main() {
    ifstream MyReadFile("ATM.INP");
    ofstream MyOutFile("ATM.OUT");
    int soLoaiTien, soKhachHang;
    MyReadFile >> soLoaiTien;
    MyReadFile >> soKhachHang;
    vector<int> vtLoaiTien;
    vector<int> vtSoToTien;
    for(int i=1; i<=soLoaiTien; i++){
        int iTemp;
        MyReadFile >> iTemp;
        vtLoaiTien.push_back(iTemp);
    }
    for(int i=1; i<=soLoaiTien; i++){
        int iTemp;
        MyReadFile >> iTemp;
        vtSoToTien.push_back(iTemp);
    }
    for(int i=1; i<=soKhachHang; i++){
        MyReadFile >> KhachHang[i][0];
        MyReadFile >> KhachHang[i][1];
    }
    //Kiểm tra xem thông tin nhập vào chuẩn hay chưa
    cout << soLoaiTien << " " << soKhachHang << endl;
    for(int i=0; i<vtLoaiTien.size(); i++){
        cout << vtLoaiTien[i] << " ";
    }
    cout << endl;
    for(int i=0; i<vtSoToTien.size(); i++){
        cout << vtSoToTien[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=soKhachHang; i++){
        cout << KhachHang[i][0] << " " << KhachHang[i][1] << endl;
    }
    cout << endl;
    cout << " -------------- OUTPUT -------" << endl;
    string strTemp = "";
    for(int i=1; i<=soKhachHang; i++){
        if (KhachHang[i][0]>KhachHang[i][1]){
            for(int i=1; i<=soLoaiTien; i++){
                cout << 0 << " ";
                MyOutFile << 0 << " ";
            }
            cout << endl;
        }else{
            int demTo=0;
            int tienHienCon = KhachHang[i][0];
            for(int j=vtLoaiTien.size()-1; j>=0; j--){
                while (tienHienCon-vtLoaiTien[j]>=0)
                {
                    if(vtSoToTien[j]<=0) break;
                    vtSoToTien[j]--;
                    demTo++;
                    tienHienCon = tienHienCon - vtLoaiTien[j];
                }
                //cout << demTo << " ";
                strTemp = to_string(demTo) + " " + strTemp;
                demTo = 0;
            }
            MyOutFile << strTemp << endl;
            cout << strTemp << endl;
            strTemp = "";
        }
    }
    return 0;
}
