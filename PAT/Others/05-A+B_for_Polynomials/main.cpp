#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
const int maxsize=1001;

struct PolyNumber{
    int index;
    double number;
};

int main()
{

    int k;
    int count = 0;
    double a[1000] = {0};
    double b[1000] = {0};
    cin>>k;
for(int i = 0;i<k;i++)
{
    int num;
    cin>>num;
    cin>>a[num];
    }
    cin>>k;
for(int i = 0;i<k;i++)
{
    int num;
    cin>>num;
    cin>>b[num];
}
for(int i = 999;i>=0;i--)
{
    a[i] += b[i];
    if(a[i]!=0)
    {
        count++;
    }
}
cout<<count;
for(int i = 999;i>=0;i--)
{
    if(a[i]!=0)
    {
        printf(" %d %.1f",i,a[i]);
    }
}

    return 0;
}
