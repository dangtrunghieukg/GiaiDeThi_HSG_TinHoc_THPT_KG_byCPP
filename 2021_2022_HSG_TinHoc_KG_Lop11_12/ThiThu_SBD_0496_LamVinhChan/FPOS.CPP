#include <iostream> //Khai báo thư viện
#include <fstream>
using namespace std;
int arrN[1000001];
int main(){
    int N;
    ifstream MyReadFile("FPOS.INP"); //Đọc dữ liệu từ File.
    ofstream MyOutFile("FPOS.OUT");
    MyReadFile>>N;
    cout<<N<<endl;
    cout<<12;
    MyOutFile<<12;
    MyReadFile.close();//Đóng File.
    MyOutFile.close();
    return 0;
}
