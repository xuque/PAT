#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int n;
    scanf("%d",&n);

    List T;
    T = (List)malloc(sizeof(struct Node));
    T->Next = NULL;

    List T1;
    T1=T;
    while(n--)
	{
        List x;
        x = (List)malloc(sizeof(struct Node));
        x->Next = NULL;
        scanf("%d",&x->Data);
        T1->Next = x;//首节点为空
        T1 = T1->Next;
    }
    return T;
}

void Print(List L)
{
    if(L->Next==NULL) 
	{
        printf("NULL\n");
        return;
    }
    else
	{
        List A;
        A=L->Next;
        while(A)
		{
            printf("%d ",A->Data);
            A=A->Next;
        }
        printf("\n");
        return;
    }
}

List Merge(List L1, List L2)
{
	List result;
	result = (List)malloc(sizeof(struct Node));
	result->Next = NULL;

	List p1 = L1->Next;
	List p2 = L2->Next;
	List my_result_ptr = result;

	while (p1 != NULL && p2 != NULL)
	{
		List small = p1->Data <= p2->Data ? p1 : p2;
		p1->Data <= p2->Data ? (p1 = p1->Next) : (p2 = p2->Next);

		my_result_ptr->Next = small;
		my_result_ptr = my_result_ptr->Next;
	}

	if (p1 != NULL || p2 != NULL)
	{
		List ptr = p1 != NULL ? p1 : p2;
		while (ptr)
		{
			my_result_ptr->Next = ptr;
			ptr = ptr->Next;
			my_result_ptr = my_result_ptr->Next;
		}
	}

	my_result_ptr->Next = NULL;
	L1->Next = NULL;
	L2->Next = NULL;
	return result;
}
