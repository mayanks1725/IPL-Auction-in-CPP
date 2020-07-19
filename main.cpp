#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
struct node{
	char player[20];
	int team;
	struct node *next;
};
struct node *head;
struct node *head1;
void insertunsold(char x[],int y)
{
	int i;
	struct node *temp4;
	temp4=(struct  node*)malloc(sizeof(struct node));
	for(i=0;i<20;i++)
	{
	    temp4->player[i]=x[i];
    }
        temp4->team=y;
		temp4->next=head;
	    head=temp4;
	}



void insert(char x[],int y)
{
	int i;
	struct node *temp1;
	temp1=(struct  node*)malloc(sizeof(struct node));
	if(y!=0)
	{
	for(i=0;i<20;i++)
	{
	    temp1->player[i]=x[i];
    }
        temp1->team=y;
		temp1->next=head;
	    head=temp1;
	}
}
void print()
{
	struct node *temp2=head;
	printf("The list of sold players:::::::::::\n");
	while(temp2!=NULL)
	{
		printf(" %s ",temp2->player);
		printf("\n");
		if(temp2->team==1)
		{
			printf("Players team is ::::: CHENNAI SUPER KINGS::::::::::\n");
		}
		else if(temp2->team==2)
		{
			printf("Players team is ::::: MUMBAI INDIANS ::::::::::\n");
		}
		else if(temp2->team==3)
		{
			printf("Players team is ::::: DELHI DAREDEVIL::::::::::\n");
		}
		else if(temp2->team==4)
		{
			printf("Players team is ::::: RAJASTHAN ROYALS::::::::::\n");
		}
		else if(temp2->team==5)
		{
			printf("Players team is ::::: KOLKATA KNIGHT RIDERS::::::::::\n");
		}
		temp2=temp2->next;
	}
	printf("\n");
}
void printunsold()
{
	struct node *temp5=head1;
	printf("The list of sold players:::::::::::\n");
	while(temp5!=NULL)
	{
		printf(" %s ",temp5->player);
		printf("\n");
	}
}
int main()
{
	FILE *fp,*MI,*DD,*KKR,*CSK,*RR;
	head=NULL;
	int l,baseprize=50;
	char a[20];
	int ch,i,j=1,count=0;
	int k;
	char temp[100],team[20];
	fp=fopen("ted.txt","r");
	while(!feof(fp))
	{
		for(i=0;i<5;i++)
		{
		fscanf(fp,"%s",temp);
		if(i==0)
		{
        for(l=0;l<20;l++)
        {
        	a[l]=temp[l];
		}
	    }
		printf("# %s \n ",temp);
       }
	   printf("\nTHE BIDDINGS STARTS FOR THIS PLAYER:::::::::::::\n\n\n");
	   while(1)
	   {
	   	printf("\nIF YOU WANT TO PLACE BID--- \n 1.Yes\n 2. No\n\n");
	   	scanf("%d",&ch);
	   	if(ch==1)
	   	{
	   		printf("\n#Enter the team::\n 1-CHENNAI \n 2-MUMBAI \n 3-DELHI \n 4-RAJASTHAN\n 5-KOLKATA\n\n->>");
	   		scanf("%d",&k);
	   		if(k==1)
	   		{
	   		    printf("++CHENNAI placed the bid of %d lakhs++ \n",baseprize);
	   		    baseprize=baseprize + 10;
	   		    count=1;
			}
			else if(k==2)
	   		{
	   		    printf("++MUMBAI placed the bid of %d lakhs++ \n",baseprize);
	   		    baseprize=baseprize + 10;
	   		    count=2;
			}
			else if(k==3)
	   		{
	   		    printf("++DELHI placed the bid of %d lakhs++ \n",baseprize);
	   		    baseprize=baseprize + 10;
	   		    count=3;
			}
			else if(k==4)
	   		{
	   		    printf("++RAJASTHAN placed the bid of %d lakhs++ \n",baseprize);
	   		    baseprize=baseprize + 10;
	   		    count=4;
			}
			else if(k==5)
	   		{
	   		    printf("++KOLKATA  placed the bid of %d lakhs++ \n",baseprize);
	   		    baseprize=baseprize + 10;
	   		    count=5;
			}
		   }
		   else if(ch==2)
		   {
		   	if(count==1)
		   	{
		   		printf("The player is sold CHENNAI SUPER KINGS at %d lakhs\n\n",baseprize);
		   		printf("**************************************************************\n\n");
				insert(a,count);
			   }
		   	else if(count==2)
		   	{
		   		printf("The player is sold MUMBAI INDIANS at %d lakhs\n\n",baseprize);
		   		printf("**************************************************************\n\n");
				insert(a,count);
			   }
			else if(count==3)
		   	{
		   		printf("The player is sold to DELHI DAREDEVILS at %d lakhs\n\n",baseprize);
			    printf("**************************************************************\n\n");
				insert(a,count);
				}
			else if(count==4)
		   	{
		   		printf("The player is sold RAJASTHAN ROYALS at %d lakhs\n \n",baseprize);
			   printf("**************************************************************\n\n");
			   insert(a,count);
			   }
			else if(count==5)
		   	{
		   		printf("The player is sold KOLKATA KNIGHT RIDERS at %d lakhs\n \n",baseprize);
		   		printf("**************************************************************\n\n");
			   insert(a,count);
			   }
			else if(count==0){
				printf("The player remained unsold\n \n");
				printf("**************************************************************\n\n");
				 insertunsold(a,count);
			}
		   	break;
		   }
	   }
       	}
		print();
		printunsold();
	fclose(fp);
	return 0;

}
