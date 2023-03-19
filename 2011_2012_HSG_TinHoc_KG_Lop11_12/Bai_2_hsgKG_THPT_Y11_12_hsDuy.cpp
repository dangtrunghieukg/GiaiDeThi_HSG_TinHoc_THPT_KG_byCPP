#include <iostream>
#include <fstream>

using namespace std;
    ifstream Read("BIEUTHUC.INP");
    ofstream Print("BIEUTHUC.OUT");
    float N;
    char arrDau[4]={'+', '-', '*', '/'};

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

float kq1, kq2, kq3, kq4, kq5;
int main(){
    Read >> N;
    bool ok=false;
    for(int a=0; a<4; a++){
        kq1=PhepTinh(1, 2, arrDau[a]);
        for(int b=0; b<4; b++){
            kq2=PhepTinh(kq1, 3, arrDau[b]);
            for(int c=0; c<4; c++){
                kq3=PhepTinh(kq2, 4, arrDau[c]);
                for(int d=0; d<4; d++){
                    kq4=PhepTinh(kq3, 5, arrDau[d]);
                    for(int e=0; e<4; e++){
                        kq5=PhepTinh(kq4, 6, arrDau[e]);
                        if(kq5==N){
                            cout << "(((((1" << arrDau[a] <<"2)" << arrDau[b] <<"3)" << arrDau[c] <<"4)" << arrDau[d] <<"5)" << arrDau[e] <<"6)" << "=" << N << endl;
                            Print << "(((((1" << arrDau[a] <<"2)" << arrDau[b] <<"3)" << arrDau[c] <<"4)" << arrDau[d] <<"5)" << arrDau[e] <<"6)" << "=" << N << endl;
                            ok=true;
                        }
                    }
                }
            }
        }
    }
    if(ok==false) cout << "0";
    return 0;
}
