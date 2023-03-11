#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int ab[101][3];
int n, m;
int main() {
    ifstream ReadFile("QUANDAO.INP");
    ofstream OutFile("QUANDAO.OUT");
    ReadFile >> n;
    ReadFile >> m;
    for(int i=1; i<=m; i++){
        ReadFile >> ab[i][1];
        ReadFile >> ab[i][2];
    }
    //Xuất file kiểm tra Input
    cout << "---Input data ------- " << endl;;
    cout << n << " " << m << endl;
    for(int i=1; i<=m; i++){
        cout << ab[i][1] << " " << ab[i][2] << endl;
    }
    cout << "---Output data---"<<endl;
    vector<int> vtQuanDao;
    vector<int> vtQuanDaoFinal_Goc, vtQuanDaoFinal;
    int demQuanDao = 1;
    for(int i=1; i<m; i++){
        vtQuanDao.clear();
        vtQuanDao.push_back(ab[i][1]);
        vtQuanDao.push_back(ab[i][2]);
        for(int j=i+1; j<=m; j++){
            bool themOk=false;
            for(int x : vtQuanDao){
                if(x==ab[j][1] || x==ab[j][2]){
                    themOk = true;
                    break;
                }
            }
            if(themOk){
                vtQuanDao.push_back(ab[j][1]);
                vtQuanDao.push_back(ab[j][2]);
            }
        }
        vtQuanDaoFinal.clear();
        sort(vtQuanDao.begin(), vtQuanDao.end());
        for(int k=0; k<vtQuanDao.size(); k++){
            if(vtQuanDao[k]!=vtQuanDao[k+1]){
                vtQuanDaoFinal.push_back(vtQuanDao[k]);
            }
        }
        if(vtQuanDaoFinal_Goc.size()==0){
            cout << "Quan dao thu " << demQuanDao <<": ";
            OutFile << "Quan dao thu " << demQuanDao <<": ";
            demQuanDao++;
            for(int k=0; k<vtQuanDaoFinal.size(); k++){
                (k==vtQuanDaoFinal.size()-1) ? cout << vtQuanDaoFinal[k] : cout << vtQuanDaoFinal[k] << ", ";
                (k==vtQuanDaoFinal.size()-1) ? OutFile << vtQuanDaoFinal[k] : OutFile << vtQuanDaoFinal[k] << ", ";
                vtQuanDaoFinal_Goc.push_back(vtQuanDaoFinal[k]);
            }
            cout << endl;
            OutFile << endl;
        }else{
            bool xuatOk = true;
            for(int x : vtQuanDaoFinal_Goc){
                for(int y : vtQuanDaoFinal){
                    if(x==y){
                        xuatOk = false;
                        break;
                    }
                }
                if (xuatOk == false) break;
            }
            if(xuatOk == true){
                vtQuanDaoFinal_Goc.clear();
                cout << "Quan dao thu " << demQuanDao <<": ";
                OutFile << "Quan dao thu " << demQuanDao <<": ";
                demQuanDao++;
                for(int k=0; k<vtQuanDaoFinal.size(); k++){
                    (k==vtQuanDaoFinal.size()-1) ? cout << vtQuanDaoFinal[k] : cout << vtQuanDaoFinal[k] << ", ";
                    (k==vtQuanDaoFinal.size()-1) ? OutFile << vtQuanDaoFinal[k] : OutFile << vtQuanDaoFinal[k] << ", ";
                    vtQuanDaoFinal_Goc.push_back(vtQuanDaoFinal[k]);
                }
                cout << endl;
                OutFile << endl;
            }
        }
    }
    return 0;
}