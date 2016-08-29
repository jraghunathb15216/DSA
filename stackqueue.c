#include <stdio.h>
#include <glib.h>
GSList *stack1=NULL,*stack2=NULL;
void push1(int i)
{
	stack1=g_slist_prepend(stack1,GINT_TO_POINTER(i));
}
int  pop1( )
{
	int i=GPOINTER_TO_INT(stack1->data);
	stack1=g_slist_remove(stack1,stack1->data);
	return i;
}
int pop2()
{
	int i=GPOINTER_TO_INT(stack2->data);
	stack2=g_slist_remove(stack2,stack2->data);
	return i;
}
void push2(int i)
{
	stack2=g_slist_prepend(stack2,GINT_TO_POINTER(i));
}
int main()
{
	int n;
	printf("enter the number of element in the queue\n");
	scanf("%d",&n);
	int i=0;
	int queuelement;
	for(i=n;i>0;i--)
	 {                                           //SOURCE STACK PUSHING STARTS
		//stack1=g_slist_prepend(stack1,GINT_TO_POINTER(i));
        push1(i);
	 }
	printf("done %d\n",g_slist_length(stack1));
	GSList *temp;
	temp=stack1; 
	while(stack1)
	{
		stack2=g_slist_prepend(stack2,stack1->data);
		stack1=stack1->next;
	}
	while(stack2)
	{
		printf("%d\n",GPOINTER_TO_INT(stack2->data));
		stack2=stack2->next;
	}
	/*while(stack1!=NULL)
	{
		stack2=g_slist_prepend(stack2,GINT_TO_POINTER(stack1->data));
			stack1=g_slist_remove(stack1,stack1->data);
		printf("done\n");
	}

	while(stack2)
		{
			printf("%d\n",pop(stack2));
		}*/
		return 0;
}