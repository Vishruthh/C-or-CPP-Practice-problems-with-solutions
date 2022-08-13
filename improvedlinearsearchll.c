//Improved Linear search - Singly Linked list | Vishruth codes
//This search not only searches the element and outputs its address
//but also moves the position to the key element to 'Head' as it can be
//easily found in future
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*root=NULL;

//Function to insert elements into the list
void append(int ar[], int n)
{
    struct node *last,*p;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=ar[0];
    root->next=NULL;
    last=root;
    for(int i=1;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=ar[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
}

//Function to display elements into the list
void display()
{
    struct node *p;
    p=root;
    while(p)
    {
        printf("%d -> ",p->data);
        p=p->next;
    }
}

//Function to search the key element and reutrn its address
int * lsearch(int k)
{
struct node *p,*q;
q=root;
p=root->next;
while(p) //=>p!=NULL
{
if(p->data==k)
{
q->next=p->next;
p->next=root;
root=p;
return (&p->data);
}
q=q->next;
p=p->next;
}
return 0;
}

int main()
{
    int len=5,key,*addr;
    int ar[]={1,3,5,7,9};
    append(ar,len);
    printf("\nThe array into SLL: ");
    display();
    printf("\nEnter the key element: ");
    scanf("%d",&key);
    addr=lsearch(key);
    if(addr==0)
    {
        printf("\nThe element is not present in the list.");
    }
    else
    {
        printf("\nThe element is present in the list at address %d", addr);
    }
    printf("\nThe SLL modified ");
    display();
    return 0;
}