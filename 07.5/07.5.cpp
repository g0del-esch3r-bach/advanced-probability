#include<iostream>
#include<cstdlib>
#include<ctime>
#include<set>
#include<vector>
using namespace std;
int simul(int N,int M)
{
    int str,fin,prz,temp,i;
    set<int>open,shut;
    vector<int>V;
    for (i=1;i<=N;i=i+1){
        shut.insert(i);
    }
    str=rand()%N+1;
    prz=rand()%N+1;
    shut.erase(str);
    shut.erase(prz);
    for (i=0;i<=M;i=i+1){
        V.clear();
        copy(shut.begin(),shut.end(),back_inserter(V));
        if (i<M){
            temp=V[rand()%V.size()];
            shut.erase(temp);
            open.insert(temp);
        }
        else{
            if (prz!=str){
                V.push_back(prz);
            }
            fin=V[rand()%V.size()];
        }
    }
    cout<<"init guess: "<<str<<endl<<"monty opens: ";
    for (auto i : open){
        cout<<i<<" ";
    }
    cout<<endl<<"final guess: "<<fin<<endl<<"prize door: "<<prz<<endl<<endl;
    return (fin==prz);
}
int main()
{
    int N,M,T,i,res;
    cout<<"# total doors: ";
    cin>>N;
    cout<<"# goats revealed: ";
    cin>>M;
    cout<<"# iterations: ";
    cin>>T;
    srand(time(0));
    res=0;
    for (i=0;i<=T-1;i=i+1){
        cout<<"round #"<<i+1<<endl;
        res+=simul(N,M);
    }
    cout<<endl<<"win rate: "<<(float)res/(float)T<<endl;
    cout<<"predicted win rate: "<<(float)(N-1)/(float)(N*(N-1-M));
    return 0;
}