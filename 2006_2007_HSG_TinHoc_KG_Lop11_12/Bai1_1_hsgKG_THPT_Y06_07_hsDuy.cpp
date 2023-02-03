#include <iostream>
#include <fstream>
using namespace std;
float mangSo[1000000];
float mangSo2[10000000];
int dem=0;
int main(){
    ifstream MyReadFile("PHANSO.INP");
    ofstream MyOutFile("PHANSO.OUT");
    int a,b,N;
    MyReadFile >> N;
    MyReadFile >> a;
    MyReadFile >> b;
    float phanSoab=(float)a/b;
    float phanSo;
    for(int i=N; i>1; i--){
        for(int j=1; j<i; j++){
            phanSo=j/(float)i;
            mangSo[dem]=phanSo;
            dem++;
        }
    }
    float tam;
    for(int i=0; i<dem; i++){
        for(int j=i; j<dem; j++){
            if(mangSo[j]<mangSo[i]){
                tam=mangSo[i];
                mangSo[i]=mangSo[j];
                mangSo[j]=tam;
            }
        }
    }
    int dem2=0;
    for(int i=0; i<dem; i++){
        if(mangSo[i]!=mangSo[i+1]){
            mangSo2[dem2]=mangSo[i];
            dem2++;
        }
    }
    int viTri=0;
    for(int i=0; i<dem2; i++){
        if(mangSo2[i]==phanSoab){
            viTri=i+1;
            //cout << viTri;
            break;
        }
    }
    MyOutFile << viTri;
    MyReadFile.close();
    return 0;
}
