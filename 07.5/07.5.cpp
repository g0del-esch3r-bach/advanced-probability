#include<iostream>
#include<cstdlib>
#include<ctime>
#include<set>
#include<vector>
using namespace std;
int simul(int N,int M)
{
    int str,fin,prz,i;
    set<int>open,shut;
    vector<int>V;
    for (i=1;i<=N;i=i+1){
        shut.insert(i);
    }
    str=rand()%N+1;
    prz=rand()%N+1;
    shut.erase(prz);
    for (i=0;i<=M-1;i=i+1)
    {
        copy(shut.begin(),shut.end(),back_inserter(V));
    }
}
int main()
{
    int N,M,T;
    cout<<"# total doors:";
    cin>>N;
    cout<<"# goats revealed:";
    cin>>M;
    cout<<"# iterations";
    cin>>T;
    srand(time(0));
    return 0;
}