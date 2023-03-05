#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

    ifstream Read("QUANDAO.INP");
    ofstream Print("QUANDAO.OUT");
int main(){
    int N, M;
    Read >> N;
    Read >> M;
    int arrRoad[101][3];
    for(int i=1; i<=M;   i++){
        Read >> arrRoad[i][1];
        Read >> arrRoad[i][2];
    }
    for(int i=1; i<=M; i++){
        cout << arrRoad[i][1] << " ";
        cout << arrRoad[i][2] << endl;
    }
    cout << endl;

    vector <int> vtQuanDao;
    vector <int> vtQuanDaoFinal;
    vector <int> vtQuanDaoFinalGoc;
    int dem=1;

    cout << "Quan dao thu " << dem  << ": ";
    Print << "Quan dao thu " << dem  << ": ";
    for(int i=1; i<M; i++){
        vtQuanDao.clear();
        vtQuanDao.push_back(arrRoad[i][1]);
        vtQuanDao.push_back(arrRoad[i][2]);
        for(int j=i+1; j<=M; j++){
            bool them=false;
            for(int x: vtQuanDao){
                if(x==arrRoad[j][1] || x==arrRoad[j][2]){
                    them=true;
                    break;
                }
            }
            if(them==true){
                vtQuanDao.push_back(arrRoad[j][1]);
                vtQuanDao.push_back(arrRoad[j][2]);
            }
        }
        vtQuanDaoFinal.clear();
        sort(vtQuanDao.begin(), vtQuanDao.end());
        for(int k=0; k<vtQuanDao.size(); k++){
            if(vtQuanDao[k] != vtQuanDao[k+1]){
                vtQuanDaoFinal.push_back(vtQuanDao[k]);
            }
        }
        //vector <int> vtFinalCoppy(vtQuanDaoFinal);
        if(vtQuanDaoFinalGoc.size()==0){
            for(int k=0; k<vtQuanDaoFinal.size(); k++){
                cout << vtQuanDaoFinal[k] << " ";
                Print << vtQuanDaoFinal[k] << " ";
                vtQuanDaoFinalGoc.push_back(vtQuanDaoFinal[k]);
            }
            cout << endl;
            Print << endl;
            dem++;
        }

        bool xuatOk=true;
        for(int x: vtQuanDaoFinalGoc){
            for(int k=0; k<vtQuanDaoFinal.size(); k++){
                if(x==vtQuanDaoFinal[k]){
                    xuatOk=false;
                    break;
                }
            }
            if(xuatOk==false) break;
        }
        if(xuatOk==true){
            vtQuanDaoFinalGoc.clear();
            cout << "Quan dao thu " << dem << ": ";
            Print << "Quan dao thu " << dem << ": ";
            for(int k=0; k<vtQuanDaoFinal.size(); k++){
                cout << vtQuanDaoFinal[k] << " ";
                Print << vtQuanDaoFinal[k] << " ";
                vtQuanDaoFinalGoc.push_back(vtQuanDaoFinal[k]);
            }
            dem++;
            cout << endl;
            Print << endl;
        }
        //cout << endl;
    }
    return 0;
}
