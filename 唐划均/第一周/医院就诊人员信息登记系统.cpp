# include <stdio.h>
# include <malloc.h>
# define N 100
struct _register
{
	char name[N];
	char phone_number[N];
	char day[N];
	char item[N];
	struct _register * next;
};
struct _register * creatlist()
{
	struct _register * head,*end;
	head=NULL;
	end=head;
	int acount=0;
	int index;
	printf("please input how many patients do you want to register:");
	scanf("%d",&index);
	while(acount<index)
	{
		struct _register *pnew=(struct _register *)malloc(sizeof(struct _register));
		printf("please input name,phone_number,day,item in turn(Format of time:xxxx-xx-xx):\n");
		scanf("%s",pnew->name);
		scanf("%s",pnew->phone_number);
		scanf("%s",pnew->day);
		scanf("%s",pnew->item);
		pnew->next=NULL;
		acount++;
		if (acount==1)
		{
			head=pnew;
			end=pnew;
		}
		else
		{
			end->next=pnew;
			end=pnew;		
		}
	}
	
	return head;	
}

insert (struct _register * a)
{
	printf("please input which point do you want to insert:");
	int val;
	scanf("%d",&val);
	struct _register * pre=a;
	struct _register * pnew=(struct _register *)malloc(sizeof(struct _register));
	scanf("%s",pnew->name);
	scanf("%s",pnew->phone_number);
	scanf("%s",pnew->day);
	scanf("%s",pnew->item);
	FILE * fp = fopen("Inserted_information","a");
	if(!fp)
	{
		printf("could not open file");
		return 0;
	}
	fprintf(fp,"%s\n",pnew->name);
	fprintf(fp,"%s\n",pnew->phone_number);
	fprintf(fp,"%s\n",pnew->day);
	fprintf(fp,"%s\n",pnew->item);
	fclose(fp);
	if (val==1)
	{
		pnew->next=pre;
		a=pnew;
	}
	else
	{
		for (int i=1;i<val-1;i++)
		pre=pre->next;
		pnew->next=pre->next;
		pre->next=pnew;	
	}
}
del(struct _register * m)
{
	struct _register *pre=m;
	struct _register *q; 
	printf("which point do you want to delete:");
	int val;
	scanf("%d",&val);
	if(val==1)
	{
		m=pre->next;
		free(pre);
	}
	else
	{
		for (int i=1;i<val-1;i++)
		{
			pre=pre->next;
		}	
		q=pre->next;
		pre->next=pre->next->next;
		free(q);	
	}
}
output(struct _register *m)
{
	struct _register *pre=m;
	while(pre!=NULL)
	{
		printf("%s\n",pre->name);
		printf("%s\n",pre->phone_number);
		printf("%s\n",pre->day);
		printf("%s\n",pre->item);
		printf("\n"); 
		pre=pre->next;
	}
}
search(struct _register *m)
{
	struct _register *pre=m;
	struct _register *q;
	printf("input the information you want to search:");
	char a[100];
	scanf("%s",&a[100]);
	do
	{
		if(a!=pre->name&&a!=pre->phone_number&&a!=pre->day&&a!=pre->item)
		{
			q=pre;
			pre=pre->next;
		}
		else if(pre==NULL)
		{
			printf("not found");
			break;
		}
		else
		{
			printf("%s",pre->name);
			printf("%s",pre->phone_number);
			printf("%s",pre->day);
			printf("%s",pre->item);
		}
	}while(a!=q->name&&a!=q->phone_number&&a!=q->day&&a!=q->item);
}
int main ()
{
	struct _register *m=creatlist();
	printf("now information:\n");
	output(m);
	printf("do you want to insert information,input 1 or 0:");
	int judge;
	scanf("%d",&judge);
	while (judge)
	{
		insert(m);
		printf("now information:\n");
		output(m);
		printf("contiune?input 1 or 0:");
		scanf("%d",&judge);
	}
	printf("do you want to delete some information,input 1 or 0:");
	scanf("%d",&judge);
	while (judge)
	{
		del(m);
		printf("now information:\n");
		output(m);
		printf("contiune?input 1 or 0:");
		scanf("%d",&judge);
	}
	printf("the end information:\n");
	output(m);
	search(m);
	
}

