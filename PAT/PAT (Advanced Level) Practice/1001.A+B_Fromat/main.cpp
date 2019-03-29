#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int a,b,c,number;
    bool flag = false;
    scanf("%d %d",&a,&b);
    c = a + b;

    if(c<0){
        printf("-");
        c = -1 * c;
    }
    stack<int>stack_int;
    while(!stack_int.empty()) stack_int.pop();
    do{
        number = c%1000;
        c /= 1000;
        stack_int.push(number);
    }while(c!=0);
    while(!stack_int.empty()){
        number=stack_int.top();
        stack_int.pop();
        if(number<1000 && flag){
            printf("%03d",number);
        }
        else {
            printf("%d",number);
            flag = true;
        }
        if(!stack_int.empty()) printf(",");
    }

    return 0;
}
