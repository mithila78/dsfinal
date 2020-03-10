#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node
{
    int data;
    node *next;
};
node *head;
void inser_last();
void inser_first();
void inser_in_position();
void delete_last();
void delete_first();
void delete_in_position(int pos);
void display();
void clear();


int main()
{
    int ch;
    while(1)
    {
        printf("\nSelect Linked List operation :\n\n");
        printf("1.Inser in last\n");
        printf("2.Inser in first\n");
        printf("3.Inser in n position\n");
        printf("4.delete in last\n");
        printf("5.delete in first\n");
        printf("6.delete in  n position\n");
        printf("7.Display list\n");
        printf("8.clear list\n");
        printf("9.End the operation\n\n");
       printf("\nEnter your choise:");
       scanf("%d",&ch);
       if (ch==1)
       {
           inser_last();

       }
       else if(ch==2)
       {
           inser_first();
       }
//      else  if(ch==3)
//       {
//           inser_in_position();
//       }
       else if(ch==4)
       {
           delete_last();
       }
        else  if(ch==5)
      {
           delete_first();
         }
       else if(ch==6)
       {
           int x;
           printf("\nEnter position for delete :");
           scanf("%d",&x);
           delete_in_position(x);

       }

       else if(ch==7)
       {
           display();

       }
       else if(ch==8)
       {
           //clear();
       }
      else  if(ch==9)
       {
           exit(0);
       }
       else
       {
           printf("Wrong Input.Try Again!!\n");
       }

    }

    return 0;
}
void display()
{
    printf("List is ");
    if(head==NULL)
    {
        printf("empty\n");
    }
    node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
}
void inser_first()
{
    node *temp;

        temp=(node *)malloc(sizeof( node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space\n");
                return;
        }
        printf("\nInsert in first : " );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}

void inser_last()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    printf("Enter node data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        node *list=head;
        while(list->next!=NULL)
        {
            list=list->next;
        }
        list->next=temp;
    }
}
void delete_first()
{
    if(head==NULL)
    {
        printf("Under Flow\n");
        return;
    }
    node *temp=head;
    head=head->next;
    free(temp);
}
void delete_last()
{
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void delete_in_position(int pos)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    node *temp=head,*prev;
    int i=0;
    if(pos==1)
    {
        head=head->next;
        free(temp);
        return;
    }
    i=1;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp =temp->next;
        i++;
        if(pos==i)
        {
            prev->next=temp->next;
            free(temp);
            return ;
        }
    }
    printf("Index out of range\n");
}
