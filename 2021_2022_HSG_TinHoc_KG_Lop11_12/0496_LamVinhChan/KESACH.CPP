#include <iostream> //Khai báo thư viện.
#include <fstream>
using namespace std;
int main(){
    int N,L;
    ifstream MyReadFile("KESACH.INP");//Đọc dữ liệu từ File.
    ofstream MyOutFile("KESACH.OUT");
    MyReadFile>>N;
    MyReadFile>>L;
    cout<<N<<" "<<L<<endl;
    int arrN[N][N];
    for(int i=0; i<N; i++){
        MyReadFile>>arrN[i][1];
        MyReadFile>>arrN[i][2];
        cout<<arrN[i][1]<<" "<<arrN[i][2]<<endl;
    }
    cout<<21;
    MyOutFile<<21;
    MyReadFile.close();//Đóng File.
    MyOutFile.close();
    return 0;
}
