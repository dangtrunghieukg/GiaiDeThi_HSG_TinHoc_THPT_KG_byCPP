#include <iostream> //Khai báo thư viện.
#include <fstream>
using namespace std;
int main(){
    unsigned long long  a,b,c;
    ifstream MyReadFile("PMIN.INP"); //Đọc dữ liệu từ File
    ofstream MyOutFile("PMIN.OUT");
    string strTemp="";
    MyReadFile>>a;
    MyReadFile>>b;
    MyReadFile>>c;
    unsigned long long z=0;
    if(a*b>=c){
        z=a*b;
    }else if(a*b<=c){
        z=a*(c/a+1);
    }
    cout<<z;
    MyOutFile<<z;
    MyReadFile.close(); //Đóng File.
    MyOutFile.close();
    return 0;
}
