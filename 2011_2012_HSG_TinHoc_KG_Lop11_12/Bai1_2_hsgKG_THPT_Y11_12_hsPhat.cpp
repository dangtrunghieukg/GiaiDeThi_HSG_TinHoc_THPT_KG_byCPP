#include <iostream>
#include <fstream>
using namespace std;
int n, dem;
double kq1,kq2,kq3,kq4,kq5;
char Kt[4]={'+','-','*','/'};
double phepTinh(float a,float b, char c)
{
    switch(c)
        {
        case '+':
            {
                return a+b;
                break;
            }
        case '-':
            {
                return a-b;
                break;
            }
        case '*':
            {
                return a*b;
                break;
            }
        default:
            {
                return (float)a/b;
                break;
            }
        }
}
int main()
{

    ifstream Read ("BIEUTHUC.INP");
    ofstream Out  ("BIEUTHUC.OUT");

    Read >> n;

   for(int a=0;a<4;a++)
   {
       for(int b=0;b<4;b++)
       {
           for(int c=0;c<4;c++)
           {
               for(int d=0;d<4;d++)
               {
                   for(int e=0;e<4;e++)
                   {
                       kq1=phepTinh(1,2,Kt[a]);
                       kq2=phepTinh(kq1,3,Kt[b]);
                       kq3=phepTinh(kq2,4,Kt[c]);
                       kq4=phepTinh(kq3,5,Kt[d]);
                       kq5=phepTinh(kq4,6,Kt[e]);
if(kq5==n){ cout<<"(((((1"<<Kt[a]<<"2)"<<Kt[b]<<"3)"<<Kt[c]<<"4)"<<Kt[d]<<"5)"<<Kt[e]<<"6)" <<"="<< kq5 << endl;
            dem++;    }
                   }
               }
           }
       }
   }
    if(dem==0)
    {
        cout << "0";
        Out << "0";
    }

    return 0;
}
