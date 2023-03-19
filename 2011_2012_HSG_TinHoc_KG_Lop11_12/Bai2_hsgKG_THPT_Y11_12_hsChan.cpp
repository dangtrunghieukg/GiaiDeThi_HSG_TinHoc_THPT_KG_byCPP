#include <iostream>
#include <fstream>
using namespace std;
char kiTuToanHoc[4]={'+', '-', '*', '/'};
float kq1, kq2, kq3, kq4, kq5;

float PhepTinh(float a, float b, char c){
    switch(c){
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return (float)a/b;
        break;
    default:
        break;
    }
}
int main(){
    int n;
    ifstream Read("BIEUTHUC.INP");
    ofstream Out("BIEUTHUC.OUT");
    Read>>n;
    bool phanTichOk=false;
    for(int a=0; a<4; a++){
        kq1=PhepTinh(1,2,kiTuToanHoc[a]);
        for(int b=0; b<4; b++){
            kq2=PhepTinh(kq1,3, kiTuToanHoc[b]);
            for(int c=0; c<4; c++){
                kq3=PhepTinh(kq2,4, kiTuToanHoc[c]);
                for(int d=0; d<4; d++){
                    kq4=PhepTinh(kq3,5, kiTuToanHoc[d]);
                    for(int e=0; e<4; e++){
                        kq5=PhepTinh(kq4,6, kiTuToanHoc[e]);
                        if(kq5==n){
                            cout<<"((((1"<<kiTuToanHoc[a]<<"2)"<<kiTuToanHoc[b]<<"3)"<<kiTuToanHoc[c]<<"4)"<<kiTuToanHoc[d]<<"5)"<<kiTuToanHoc[e]<<"6)"<<"="<<n<<endl;
                            Out<<"((((1"<<kiTuToanHoc[a]<<"2)"<<kiTuToanHoc[b]<<"3)"<<kiTuToanHoc[c]<<"4)"<<kiTuToanHoc[d]<<"5)"<<kiTuToanHoc[e]<<"6)"<<"="<<n<<endl;
                            phanTichOk=true;
                            }
                        }
                    }
                }
            }
        }
        if(phanTichOk==false){
            cout<<0;
            Out<<0;
        }
        return 0;
    }

