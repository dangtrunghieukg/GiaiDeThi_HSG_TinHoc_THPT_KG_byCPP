#include <iostream>
#include <fstream>

using namespace std;
int arrMangSo[10000][2];

int UCLN(int a, int b) {
    if (b==0) return a;
    return UCLN(b, a % b);
};

int main(){
    int N, a, b ;
    ifstream Read("USCLN.INP");
    ofstream Print("USCLN.OUT");
    Read >> N;
    int dem=0;
    while(!Read.eof()){
        Read >> arrMangSo[dem][0];
        Read >> arrMangSo[dem][1];
        dem++;
    }
    int tam1, tam2;
    for(int i=0; i<dem; i++){
        tam1=arrMangSo[i][0];
        cout << tam1 << " ";
        tam2=arrMangSo[i][1];
        cout << tam2 << endl;
        Print << UCLN(tam1, tam2);
        Print << endl;
        cout << endl;
    }
    return 0;
}
