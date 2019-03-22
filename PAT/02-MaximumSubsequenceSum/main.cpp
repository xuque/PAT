#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int sum=0;
    int sum_temp=0;

    int number;
    cin>>number;
    int number_array[number];

    int left=-1;
    int right=-1;

    int temp_left=0;

    bool flag=true;
    bool negative=false;

    int num;
    for(int i=0;i<number;i++){
        cin>>num;
        sum_temp +=num;
        if(sum_temp<0){
             number_array[i]=num;
             sum_temp=0;
             flag=true;
        }
        else{
            negative=true;
            if(flag&&num>=0){ // new Segment's left
                temp_left=num;
                flag=false;
            }
            if(sum<sum_temp){
                sum=sum_temp;
                right=num;
                left=temp_left;
            }
        }
    }
    if(!negative&&left==-1&&right==-1) printf("%d %d %d",sum,number_array[0],number_array[number-1]);
    else if(negative&&left==-1&&right==-1)  printf("%d %d %d",sum,0,0);
    else printf("%d %d %d",sum,left,right);

    system("pause");
    return 0;
}
