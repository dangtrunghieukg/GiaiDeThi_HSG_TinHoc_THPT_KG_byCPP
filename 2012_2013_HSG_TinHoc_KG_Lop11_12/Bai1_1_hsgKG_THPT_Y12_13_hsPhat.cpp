#include <iostream>
#include <fstream>

using namespace std;
string M[9999];
string s;
int dem;
bool co;
    ifstream Read("CHUOI.INP");
    ofstream Out ("CHUOI.OUT");
int n;
int main()
{

    Read >> n;

    for(int i=0;i<=n;i++)
    {
        getline(Read,M[i]);
    }

    for(int i=0;i<=n;i++)
    {
        dem=0;
        for(int j=0;j<=n;j++)
        {
            if(M[i]==M[j])
            {
                dem++;
            }
        }
        if(dem%2==1 ) cout << M[i] << endl;
    }



    return 0;
}
