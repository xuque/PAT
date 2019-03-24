//#include <stdio.h>
//#include <string.h>
//#include <cstring>
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//int Max3( int A, int B, int C );
//int DivideAndConquer( int List[], int left, int right );
//int MaxSubseqSum3( int List[], int N );
//
//int main()
//{
//    cout<<"要输入数字数量："<<endl;
//    int i;
//    cin>>i;
//    int Num[i];
//    if(i>0)
//    {
//       cout<<"下面请输入数字:"<<endl;
//       for(int n=0;n<i;n++)
//       {
//        cin>>Num[n];
//       }
//    }
//    MaxSubseqSum3(Num,i);
//
//    return 0;
//}
//int Max3( int A, int B, int C )
//{ /* 返回3个整数中的最大值 */
//    return A > B ? A > C ? A : C : B > C ? B : C;
//}
//
//int DivideAndConquer( int List[], int left, int right )
//{ /* 分治法求List[left]到List[right]的最大子列和 */
//    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
//    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
//
//    int LeftBorderSum, RightBorderSum;
//    int center, i;
//
//    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
//        if( List[left] > 0 )  return List[left];
//        else return 0;
//    }
//
//    /* 下面是"分"的过程 */
//    center = ( left + right ) / 2; /* 找到中分点 */
//    /* 递归求得两边子列的最大和 */
//    MaxLeftSum = DivideAndConquer( List, left, center );
//    MaxRightSum = DivideAndConquer( List, center+1, right );
//
//    /* 下面求跨分界线的最大子列和 */
//    MaxLeftBorderSum = 0; LeftBorderSum = 0;
//    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
//        LeftBorderSum += List[i];
//        if( LeftBorderSum > MaxLeftBorderSum )
//            MaxLeftBorderSum = LeftBorderSum;
//    } /* 左边扫描结束 */
//
//    MaxRightBorderSum = 0; RightBorderSum = 0;
//    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
//        RightBorderSum += List[i];
//        if( RightBorderSum > MaxRightBorderSum )
//            MaxRightBorderSum = RightBorderSum;
//    } /* 右边扫描结束 */
//
//    /* 下面返回"治"的结果 */
//    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
//}
//
//int MaxSubseqSum3( int List[], int N )
//{ /* 保持与前2种算法相同的函数接口 */
//    return DivideAndConquer( List, 0, N-1 );
//}
//


#include <iostream>

using namespace std;

static int Left=0;
static int Right=0;
static int more=0; //more代表了有几段正整数和的序列

int Maxnum(int list[], int i);
int shuzu_max(int shuzu[]);

int main()
{
    int max_num;
    int n;
    cin>>n;

    int number[n];

    for(int i=0;i<n;i++){
        cin>>number[i];
        //输入数组
    }
    max_num=Maxnum(number,n);

    cout<<max_num<<" ";

    int xxx=0;
    for(int i=0;i<n;i++){
        if(number[i]>=0) {
            xxx=1;break;
        }
    }

    if(xxx==0){
        Left=number[0];
        Right=number[n-1];
    }
    else{
        if(Left<0){
            Left=0;
        }
    }

    cout<<Left<<" "<<Right;

    return 0;
}

int Maxnum(int List[], int i)
{
    int max_num;
    max_num=0;

    int temporary_num;
    temporary_num=0;

    int k=0;
    int flag=1;
    int open=0;

    int shuzu[5000];

    for(int j=0;j<i;j++){
        temporary_num +=List[j];

        if(temporary_num<0){
            temporary_num=0;
            if(open==1){
            more++;
            flag=1;
            open=0;
            }
        }
        else if(temporary_num==0){;}
        else{
            if(flag==1){
            List[more]=List[j];
            flag=0;
            open=1;
            }
        }

        if(temporary_num>max_num){
            Right=List[j];
            max_num=temporary_num;
            shuzu[more]=max_num;
        }
    }

    int g;
    g=shuzu_max(shuzu);

    Left=List[g];

    return max_num;
}

int shuzu_max(int shuzu[])
{
    int shuzu_max;
    shuzu_max=0;

    int flag;
    flag=0;

    for(int t=0;t<more+1;t++){
        if (shuzu[t]>shuzu_max){
            shuzu_max=shuzu[t];
            flag=t;
        }
    }
//    cout<<"flag="<<flag<<endl;
    return flag;
}


#include <stdio.h>
#include <iostream>

int main()
{
    int num,sum=0,temp=0,a;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&a);
        temp +=a;
        if(temp<0) temp=0;
        if(temp>sum) sum=temp;
    }
    printf("%d",sum);
    return 0;
}
