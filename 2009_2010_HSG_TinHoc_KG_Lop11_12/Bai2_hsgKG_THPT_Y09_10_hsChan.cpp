#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int soLoaiTien, soKhachHang;
int khachHang[10001][2];
int main(){
    ifstream Read("ATM.INP");
    ofstream Out("ATM.OUT");
    Read>>soLoaiTien;
    Read>>soKhachHang;
    vector<int> vtLoaiTien;
    vector<int> vtSoToTien;
    for(int i=1; i<=soLoaiTien; i++){
        int iTemp;
        Read>>iTemp;
        vtLoaiTien.push_back(iTemp);
    }

    for(int i=1; i<=soLoaiTien; i++){
        int iTemp;
        Read>>iTemp;
        vtSoToTien.push_back(iTemp);
    }
    for(int i=1; i<=soKhachHang; i++){
        Read>>khachHang[i][0];
        Read>>khachHang[i][1];
    }
    cout<<soLoaiTien<<" "<<soKhachHang<<endl;
    for(int i=0; i<vtLoaiTien.size();i++){
        cout<<vtLoaiTien[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<vtSoToTien.size();i++){
        cout<<vtSoToTien[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=soKhachHang; i++){
        cout<<khachHang[i][0]<<" "<<khachHang[i][1]<<endl;
    }
    cout<<endl;
    for(int i=1; i<=soKhachHang;i++){
        if(khachHang[i][0] > khachHang[i][1]){
            for(int i=1; i<=soLoaiTien; i++){
                cout<<0<<" ";
                Out<<0<<" ";
            }
            cout<<endl;
            Out<<endl;
        }else{
            int demTo=0;
            int tienHienCon=khachHang[i][0];
            string strTemp="";
            for(int j=vtLoaiTien.size()-1; j>=0; j--){
                while(tienHienCon-vtLoaiTien[j]>=0){
                    if(vtSoToTien[j]<=0) break;
                    vtSoToTien[j]--;
                    demTo++;
                    tienHienCon=tienHienCon-vtLoaiTien[j];
                }
                //cout<<demTo<<" ";
                strTemp=to_string(demTo)+" "+strTemp;
                demTo=0;
            }
            cout<<strTemp;
            Out<<strTemp;
            cout<<endl;
            Out<<endl;
            strTemp=" ";
        }
    }


Read.close();
Out.close();

return 0;
}
