#include <glib.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
void moveprinter(char s,char d,int des)
{
	 printf("Move the disk %d from \'%c\' to \'%c\'\n",des,s,d);
}
void move(GSList **source,GSList **dest,char s,char d)
{
	int src,des;
	if(*source==NULL)
	{
       src=INT_MIN;
	}
	else
	{
		src=GPOINTER_TO_INT((*source)->data);
	    *source=g_slist_remove(*source,(*source)->data);

	}
	if((*dest)==NULL)
		des=INT_MIN;
	else
	{
		des=GPOINTER_TO_INT((*dest)->data);
		*dest=g_slist_remove(*dest,(*dest)->data);
	}
	if(src==INT_MIN)
	{
		*source=g_slist_prepend(*source,GINT_TO_POINTER(des));
		moveprinter(d,s,des);
	}
	else if(des==INT_MIN)
	{
		*dest=g_slist_prepend(*dest,GINT_TO_POINTER(src));
		moveprinter(s,d,src);
	}
	else if(src>des)
	{
		*source=g_slist_prepend(*source,GINT_TO_POINTER(src));
		*source=g_slist_prepend(*source,GINT_TO_POINTER(des));
		moveprinter(d,s,des);
	}
	else
	{
		*dest=g_slist_prepend(*dest,GINT_TO_POINTER(des));
		*dest=g_slist_prepend(*dest,GINT_TO_POINTER(src));
		moveprinter(s,d,src);
	}

}
int main()
{
	GSList *source=NULL,*dest=NULL,*aux=NULL,**psource,**pdest,**paux;
	psource=&source;
	pdest=&dest;
	paux=&aux;
	int n;
	printf("enter the number if disk \n");
	scanf("%d",&n);
	int total_moves,i;
	char s='A',d='C',a='B';
	printf("done\n");
	if(n%2==0)
	{ 
		printf("done\n");
		char temp;
		temp=d;
		d=a;
		a=temp;
	}
	printf("done\n");
	total_moves=pow(2,n)-1;
	printf("%d\n",total_moves);      
	for(i=n;i>0;i--)
		source=g_slist_prepend (source,GINT_TO_POINTER(i));
	GSList *temp;
	temp=source;
	for(i=n;i>0;i--)
      {
      	if(temp==NULL)
      		break;
      	printf("%d\n",GPOINTER_TO_INT(temp->data));
      	temp=temp->next;

      }
	for(i=1;i<=total_moves;i++)
	{
		if(i%3==1)
			move(psource,pdest,'s','d');
        else if(i%3==2)
            move(psource,paux,'s','a');
        else if(i%3==0)
        	move(paux,pdest,'a','d');
	}
    
}
