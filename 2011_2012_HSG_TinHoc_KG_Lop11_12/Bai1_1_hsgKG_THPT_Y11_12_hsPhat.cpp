#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;

int n, k, dem;
int Bool[MAX] = { 0 };
int A[MAX];
string s;
void xuat() {
bool co;
co=false;
 for (int i = 1; i <= n; i++)
 {
    if(A[i]==i)
    {
        co=true;
        break;
    }
 }
 if(co==false)
 {
     dem++;
     for(int i=1; i<= n; i++)
     {
          s+=to_string(A[i]);
          cout << A[i] << " ";
     }
        cout << endl;
 }
}

void Try(int k) {
 for (int i = 1; i <= n; i++) {

 if (!Bool[i]) {
 A[k] = i;
 Bool[i] = 1;
 if (k == n)
 xuat();
 else
 Try(k + 1);
 Bool[i] = 0;
 }
 }
}

int main() {
 ifstream Read("HOANVI.INP");
 ofstream Out ("HOANVI.OUT");
 Read >> n;
 Try(1);
k=0;
 for(int i=0;i<s.length();i++)
 {
     Out << s[i] << " ";
     k++;
     if(k==n)
     {
        Out << endl;
        k=0;
     }


 }
 cout<< "So hoan vi=" << dem;
 Out << "So hoan vi=" << dem;
}
