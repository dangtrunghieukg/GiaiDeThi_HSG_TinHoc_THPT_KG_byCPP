#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;

bool arrDanhDau[20];
int arrDayHoanVi[20];
int N;
int dem=0;

ifstream MyRead("HOANVI.INP");
ofstream MyOut("HOANVI.OUT");

void XuatHoanVi(){
    bool xuatOk=true;
    for(int i=1; i<=N; i++){
        if(i==arrDayHoanVi[i]){
            xuatOk=false;
            break;
        }
    }
    if(xuatOk==true){
        for(int i=1; i<=N; i++){
            cout<<arrDayHoanVi[i]<<" ";
            MyOut<<arrDayHoanVi[i]<<" ";
        }
        cout<<endl;
        MyOut<<endl;
        dem++;
    }


}

 void TimHoanVi(int k){
    for(int i=1; i<=N;i++){
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
int main(){
    MyRead>>N;
    for(int i=1; i<=N; i++) arrDanhDau[i]=true;
    TimHoanVi(1);
    cout<<"So hoan vi="<<dem;
    MyOut<<"So hoan vi="<<dem;
    MyRead.close();
    MyOut.close();
    return 0;
}
