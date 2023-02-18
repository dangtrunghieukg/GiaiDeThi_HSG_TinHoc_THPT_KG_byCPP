#include <iostream>
#include <fstream>
using namespace std;
int N;
int a[10000];
int b[10000];
int main(){
    ifstream MyReadFile("HVTT.INP");
    ofstream MyOutFile("HVTT.OUT");
    MyReadFile>>N;
    cout<<N<<endl;
    for(int i=1; i<=N; i++){
        MyReadFile>>a[1];
    }
    for(int i=1; i<=N; i++){
        cout<<a[i]<<" ";
    }
    int dem=0;
    for(int i=1; i<=N; i++){
        for(int j=i; j>=1; j--){
            if(a[j]<a[i]){
                dem++;
            }
        }
        b[i]=dem;
        dem=0;
    }
    cout<<endl;
    for(int i=1; i<=N; i++){
        cout<<b[i]<<" ";
        MyOutFile<<b[i]<<" ";
    }
MyReadFile.close();
MyOutFile.close();


return 0;
}
