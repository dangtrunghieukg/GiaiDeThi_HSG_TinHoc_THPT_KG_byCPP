#include <iostream>
#include <fstream>
using namespace std;

#define MAX 1001
void TimHoanVi(int k);
void XuatHoanVi();
bool arrDanhDau[MAX];
int arrDayHoanVi[MAX];
int N;
int dem=0;
    ifstream Read("HOANVI.INP");
    ofstream Prt("HOANVI.OUT");
int main(){

    Read >> N;
    for(int i=1; i<=N; i++){
        arrDanhDau[i]=true;
    }
    TimHoanVi(1);
    cout << "So Hoan Vi: " << dem;
    Prt << "So Hoan Vi=" << dem;
    Read.close();
    Prt.close();
    return 0;
}

void XuatHoanVi(){
    bool XuatOk=true;
    for(int i=1; i<=N; i++){
        if(i==arrDayHoanVi[i]){
            XuatOk=false;
            break;
        }
    }
    if(XuatOk==true){
        for(int i=1; i<=N; i++){
            cout << arrDayHoanVi[i] << " ";
            Prt << arrDayHoanVi[i] << " ";
        }
        cout << endl;
        Prt << endl;
        dem++;
    }
}

void TimHoanVi(int k){
    for(int i=1; i<=N; i++){
        if(arrDanhDau[i]==true){
            arrDayHoanVi[k]=i;
            arrDanhDau[i]=false;
            if(k==N){
                XuatHoanVi();
            }else{
                TimHoanVi(k+1);
            }
            arrDanhDau[i]=true;
        }
    }
}
