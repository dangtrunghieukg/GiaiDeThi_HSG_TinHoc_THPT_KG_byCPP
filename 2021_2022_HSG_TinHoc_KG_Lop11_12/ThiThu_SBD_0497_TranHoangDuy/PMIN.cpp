#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream Read("PMIN.INP");
    ofstream Print("PMIN.OUT");
    int a, b, c;
    Read >> a; Read >> b; Read >> c;
    int x=a, y=b, z, soMax=0, tam1, tam2;
    bool f=false;
    //cout << x << endl << y << endl << x*y << " " << c << endl;
    while(f==false){
        z=x*y;
        if(z>=c){
            f=true;
        }else{
            x++;
            z=x*y;
            tam1=(x-1)*(y+1);
            if(z>=c && z<tam1){
                f=true;
            }else{
                x--;
                y++;
            }
            z=x*y;
            if(z>=c){
                f=true;
            }else{
                x++;
                z=x*y;
                if(z>=c) f=true;
            }
        }
    }
    cout << x << "*" << y << "=" << z;
    Print << z;
    Read.close();
    Print.close();
    return 0;
}
