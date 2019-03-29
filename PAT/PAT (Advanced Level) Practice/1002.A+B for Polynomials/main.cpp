#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float arr[1001]={0};
    int a,b,i;
    int index;
    int t=0;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&index);
        scanf("%f",&arr[index]);
    }
    scanf("%d",&b);
    for(i=0;i<b;i++){
        scanf("%d",&index);
        float num;
        scanf("%f",&num);
        arr[index] +=num;
    }
    for(i=1000;i>=0;i--) if(arr[i]!=0) t++;
    printf("%d",t);
    if(t!=0){
        printf(" ");
        for(i=1000;i>=0;i--){
            if(arr[i]!=0){
                printf("%d %.1f",i,arr[i]);
                t--;
                if(t!=0) printf(" ");
            }
        }
    }

    return 0;
}
