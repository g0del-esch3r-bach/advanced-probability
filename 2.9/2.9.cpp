#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
int main()
{
    srand(time(0));
    vector<int>V;
    int res,ctr,i,j,k;
    res=0;
    ctr=0;
    int A[][2][2]={{{0,0},{0,0}},{{0,0},{0,0}}};
    while(res<8){
        V.push_back(rand()%2);
        cout<<V[ctr];
        ctr+=1;
        if (ctr<3){
            continue;
        }
        if (A[V[ctr-3]][V[ctr-2]][V[ctr-1]]==0){
            A[V[ctr-3]][V[ctr-2]][V[ctr-1]]=ctr;
            res+=1;
        }
    }
    cout<<endl<<endl;
    for (i=0;i<=1;i=i+1){
        for (j=0;j<=1;j=j+1){
            for (k=0;k<=1;k=k+1){
                cout<<i<<j<<k<<" "<<A[i][j][k]<<endl;
            }
        }
    }
    return 0;
}