#include <stdio.h>
#include <glib.h>
GSList *queue=NULL,*head=NULL,*tail=NULL;       //global definition of list;
int j=1,del;                                       //global definition of iterator j and deleted element;
int n,d,c=1;
void enqueue(int i);                 //appends the element at the end of the queue
int  dequeue();                      //deletes the element at the front of the queue
void hot_potato();                  //imlements the logic of the game
int main()
{
	printf("enter the number of children and the elemination rule\n");       //prompts the user to enter number of partcipants and the number for elemination rule
	scanf("%d%d",&n,&d);
    int i=0;
    for (i=1;i<=n;i++)       //intialize the queue with all elements of the range 
    enqueue(i);
    printf("printing the queue formed\n");   //prints the elements in the queue
    GSList *t;
    t=queue;
    while(t!=NULL)
    {
    	printf("%d\n",GPOINTER_TO_INT(t->data));
    	t=t->next;
    }
    printf(" entered %d %d %d\n",g_slist_length(queue),j,d);
     while(g_slist_length(queue)!=0)
     hot_potato();
  printf("Hence,the person at position %d survives. (winner)\n",del);
}
void enqueue(int i)
{
	if(g_slist_length(queue)==0)
	{
		queue=g_slist_append(queue,GINT_TO_POINTER(i));
		head=tail=queue;
	}
	else
	{
		queue=g_slist_append(queue,GINT_TO_POINTER(i));
		head=queue;
		tail=g_slist_find(queue,GINT_TO_POINTER(i));
	}
}
int dequeue()
{
	int temp;
   if(g_slist_length(queue)==0)
   	{
   		temp=-1;
   	}
   else
   {
   	  temp=GPOINTER_TO_INT(head->data);
   	  queue=g_slist_remove(queue,head->data);
   	  head=queue;
   }
  return temp;
}
void hot_potato()
	{
        if(j%d!=0)
        {
            del=dequeue();
            enqueue(del);
            j++;
        }
        else
        {
        	del=dequeue();
        	if(c==1)
        	printf("firstly,the person at position %d is removed\n",del);
            else if(c<n-1)
            	printf("then,the person at position %d is removed\n",del);
            else if(c==n-1)
            	printf("Finally,the person at position %d is removed\n",del);
        	j=1;c++;
        }

    }
