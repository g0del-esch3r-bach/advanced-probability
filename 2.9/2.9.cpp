#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    int i;
    for (i=0;i<=42;i=i+1)
    {
        cout<<rand()%2;
    }
    return 0;
}