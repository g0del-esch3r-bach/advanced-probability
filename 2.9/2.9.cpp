#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int i;
    for (i=0;i<=25;i=i+1)
    {
        cout<<rand()%2;
    }
    return 0;
}