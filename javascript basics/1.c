#include<stdio.h>
int front=-1,rear=-1,choice,size,item,q[10],i;
void Enqueue();
void Dequeue();
void Display();
int main()
{

printf("enter the size of the queue");
scanf("%d",&size);
do{
printf("enter the your choice:\n");
printf("\n1.ENQUEUE\t2.DEQUEUE\t 3.DISPLAY\t 4.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
case 1:Enqueue();
break;
case 2:Dequeue();
break;
case 3:Display();
break;
case 4:printf("Exit");
return 0;
default:printf("Invalid Choice\n");
}
}while(choice!=4);
}

void Enqueue()
{
if(rear==size-1){
printf("queue is full\n");
}
else if(front==-1&&rear==-1){
front=rear=0;
printf("ENTER THE ELEMENT : ");
scanf("%d",&item);
q[rear]=item;
}
else{
printf("ENTER THE ELEMENT : ");
scanf("%d",&item);
rear=rear+1;
q[rear]=item;
}printf("\n");
}

void Dequeue()
{
if(front==-1&&rear==-1){
printf("queue is empty");
}
else if(front=rear){
printf("deleted item is :%d\t",q[front]);
}
else{
printf("deleted item is :%d\t",q[front]);
front=front+1;
}printf("\n\n");
}

void Display()
{
if(front==-1&&rear==-1){
printf("queue is empty");
}
else{
for(i=front;i<=rear;i++){
printf("%d\t",q[i]);
}
}printf("\n\n");
}











