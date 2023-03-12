#include <iostream>
#include <fstream>
int arrN[101][101];
using namespace std;

int main(){
    int m,n;
    ifstream MyRead("ROBOT.INP");
    ofstream MyOut("ROBOT.OUT");
    MyRead>>m;
    MyRead>>n;
    cout<<m<<" "<<n<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            MyRead>>arrN[i][j];
            cout<<arrN[i][j]<<" ";
        }
        cout<<endl;
    }
MyRead.close();
MyOut.close();

return 0;
}
