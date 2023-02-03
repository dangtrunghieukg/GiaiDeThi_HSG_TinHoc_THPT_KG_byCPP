#include <iostream>
#include <fstream>
using namespace std;

float arrPhanSo[1000000];
float arrPhanSo2[1000000];

int main(){
    ifstream MyReadFile("PHANSO.INP");
    ofstream MyOutFie("PHANSO.OUT");
    int N, a, b, dem;
    MyReadFile>>N;
    MyReadFile>>a;
    MyReadFile>>b;
    float phanSo;
    float phanSoab=(float)a/b;
    dem=0;
    float temp;
    for(int i=N; i>1; i--){
        for(int j=1; j<i; j++){
            phanSo=(float)j/i;
            //cout<<phanSo<<endl;
            arrPhanSo[dem]=phanSo;
            dem++;
        }
    }
    for(int i=0; i<dem;i++){
        for(int j=i; j<dem; j++){
            if(arrPhanSo[i]>arrPhanSo[j]){
                temp=arrPhanSo[i];
                arrPhanSo[i]=arrPhanSo[j];
                arrPhanSo[j]=temp;
            }
        }
    }
    int dem2=0;
    for(int i=0; i<dem; i++){
        if(arrPhanSo[i]!=arrPhanSo[i+1]){
            arrPhanSo2[dem2]=arrPhanSo[i];
            dem2++;
        }
    }
    int viTri;
    for(int i=0; i<dem2; i++){
        if (arrPhanSo2[i]==phanSoab){
            viTri=i+1;
            break;
        }
    }
   MyOutFie<<viTri;
   MyReadFile.close();

    return 0;
}
