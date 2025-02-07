#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
int A[2][2][2][10000];
void simul(int N)
{
    vector<int>V;
    int res,ctr,i,j,k;
    res=0;
    ctr=0;
    int B[][2][2]={{{0,0},{0,0}},{{0,0},{0,0}}};
    while(res<8){
        V.push_back(rand()%2);
        //cout<<V[ctr];
        ctr+=1;
        if (ctr<3){
            continue;
        }
        if (B[V[ctr-3]][V[ctr-2]][V[ctr-1]]==0){
            B[V[ctr-3]][V[ctr-2]][V[ctr-1]]=ctr;
            res+=1;
        }
    }
    //cout<<endl<<endl;
    for (i=0;i<=1;i=i+1){
        for (j=0;j<=1;j=j+1){
            for (k=0;k<=1;k=k+1){
                A[i][j][k][N]=B[i][j][k];
                //cout<<i<<j<<k<<" "<<B[i][j][k]<<endl;
            }
        }
    }
    return;
}
int main()
{
    srand(time(0));
    int N,i,j,k,l,temp[3];
    float E[2][2][2],P[2][2][2];
    cout<<"# iterations to simulate for: ";
    cin>>N;
    for (i=0;i<=N-1;i=i+1){
        simul(i);
        //cout<<endl<<"================================"<<endl<<endl;
    }
    for (i=0;i<=1;i=i+1){
        for (j=0;j<=1;j=j+1){
            for (k=0;k<=1;k=k+1){
                E[i][j][k]=0;
                P[i][j][k]=0;
                //cout<<i<<j<<k<<endl;
                for (l=0;l<=N-1;l=l+1){
                    //cout<<A[i][j][k][l]<<endl;
                    E[i][j][k]+=(float)A[i][j][k][l]/(float)N;
                }
                //cout<<endl;
            }
        }
    }
    /*for (l=0;l<=N-1;l=l+1){
        temp[0]=0;
        temp[1]=0;
        temp[2]=0;
        for (i=0;i<=1;i=i+1){
            for (j=0;j<=1;j=j+1){
                for (k=0;k<=1;k=k+1){
                    if (A[i][j][k][l]<A[temp[0]][temp[1]][temp[2]][l])
                    {
                        temp[0]=i;
                        temp[1]=j;
                        temp[2]=k;
                    }
                }
            }
        }
        //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" winner round"<<N<<endl;
        P[temp[0]][temp[1]][temp[2]]+=(float)1/(float)N;
    }*/
    for (i=0;i<=1;i=i+1){
        for (j=0;j<=1;j=j+1){
            for (k=0;k<=1;k=k+1){
                cout<<"E[flips --> "<<i<<j<<k<<"] = "<<E[i][j][k]<<endl;
                //cout<<"P[win "<<i<<j<<k<<"] = "<<P[i][j][k]<<endl;
            }
        }
    }
    return 0;
}