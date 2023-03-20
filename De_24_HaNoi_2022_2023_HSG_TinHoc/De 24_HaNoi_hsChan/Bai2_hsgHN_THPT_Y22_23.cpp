#include <iostream>
#include <fstream>
using namespace std;
int arrN[10001][10001];
int main(){
    int n,x;
    ifstream Read("BS.INP");
    ofstream out("BS.OUT");
    Read>>n;
    Read>>x;
    cout<<n<<" "<<x<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arrN[i][j]=i*j;

        }
    }
    int dem=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //cout<<arrN[i][j]<<" ";
            if(arrN[i][j]==x){
                dem++;
            }
        }
      //  cout<<endl;
    }
    cout<<dem;
    out<<dem;
    return 0;
}
