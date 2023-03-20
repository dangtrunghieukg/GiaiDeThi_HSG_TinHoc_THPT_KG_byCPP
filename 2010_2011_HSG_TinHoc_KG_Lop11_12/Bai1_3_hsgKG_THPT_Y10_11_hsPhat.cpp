#include <iostream>
#include <fstream>
using namespace std;
int N, S, T, klmax , tam, i, q, maxx;
bool co;
int main()
{
    ifstream Read("TAITRONG.INP");
    ofstream Out ("TAITRONG.OUT");

    Read >> N;
    Read >> S;
    Read >> T;

    int M[N][N];
    int K[N];
    for (int i=1;i<=N;i++)
         K[i]=0;

    for (int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            Read >> M[i][j];
        }
    }
    maxx=0;
    for (int i=1;i<=N;i++)
    {
        klmax=0;
        for(int j=1;j<=N;j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    tam=S;
    q++;
    K[q]=tam;
    while (tam != T)
    {
        i=tam;
        klmax=0;
        for(int j=1;j<=N;j++)
        {
            if (klmax < M[i][j]) klmax = M[i][j];
            if(maxx <klmax) maxx =klmax;
        }
        for(int g=1;g<=N;g++)
        {
            if (klmax == M[i][g])
            {
               tam=g;
            }
        }

                q++;
                K[q]=tam;

    }

    cout << maxx << endl;
    for (int i=1;i<=N;i++)
    {
       if(K[i]!=0) cout << K[i] << " ";
    }

    return 0;
}
