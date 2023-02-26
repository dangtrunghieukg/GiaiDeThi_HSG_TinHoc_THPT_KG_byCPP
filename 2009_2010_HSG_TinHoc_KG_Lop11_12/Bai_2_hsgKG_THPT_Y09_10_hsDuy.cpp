#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> vtLoaiTien;
vector <int> vtSoToTien;
vector <int> vtKQ;
int soKhachHang[100001][2];
int arrMang[100001];
int main(){
    ifstream Read("ATM.INP");
    ofstream Print("ATM.OUT");
    int m, n;
    Read >> m; Read >> n;
    int i=1;
    for(int i=1; i<=m; i++){
        int tam;
        Read >> tam;
        vtLoaiTien.push_back(tam);
    }
    for(int i=1; i<=m; i++){
        int tam;
        Read >> tam;
        vtSoToTien.push_back(tam);
    }
    for(int i=1; i<=n; i++){
        Read >> soKhachHang[i][0];
        Read >> soKhachHang[i][1];
    }
    for(int i=1; i<=n; i++){
        if(soKhachHang[i][0]>soKhachHang[i][1]){
            for(int i=1; i<m; i++){
                cout << 0 << " ";
                Print << 0 << " ";
            }
            Print << endl;
            cout << endl;
        }else{
            int demTo=0;
            int tienHienCon=soKhachHang[i][0];
            string tam="";
            for(int j=vtLoaiTien.size()-1; j>=0; j--){
                while(tienHienCon-vtLoaiTien[j]>=0){
                    if(vtSoToTien[j]<=0) break;
                    vtSoToTien[j]--;
                    demTo++;
                    tienHienCon=tienHienCon-vtLoaiTien[j];
                }
                //cout << demTo << " ";
                tam=to_string(demTo)+ " " + tam;
                demTo=0;
            }
            cout << tam;
            Print << tam;
            tam="";
            cout << endl;
            Print << endl;
        }
    }
    return 0;
}
