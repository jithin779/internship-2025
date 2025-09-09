#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char s[50],E[100],item;
int n,i,top=-1;
	
	void infix();
	void evalPostfix();
	void push(char item);
	char pop();
	int Priority(char sym);
		
		int main()
		{
		int ch;
		while(1){
		printf("\n----MENU----\n");
		printf("1.infix to postfix conversion\n");
		printf("2.evaluate postfix expression\n");
		printf("3.Exit\n");
		printf("enter the choice:");
			scanf("%d",&ch);
			switch(ch){
			case 1:
			top=-1;
			printf("enter size of expression");
			scanf("%d",&n);
				printf("enter the infix expression:");
				scanf("%s",E);
				printf("postfix expression:");
				infix();
				printf("\n");
				break;
				case 2:
				evalPostfix();
				break;
				case 3:
				exit(0);
				default:
				printf("invalid choice\n");
				}
				}
				return 0;	
					}
					void push(char item)
					{
					if(top==n-1)
					printf("stack full\n");
					else
					s[++top]=item;
					}
					char pop()
					{
					if (top==-1){
					printf("stack empty\n");
					return '\0';
					}else{
					return s[top--];
					}
					}
					int Priority(char sym)
					{
					switch(sym){
					case'^':return 3;
					case'*':
					case'/':return 2;
					case'+':
					case'-':return 0;
					}
					}
						void infix()
						{
						push('(');
						strcat(E,")");
						for(i=0;E[i]!='\0';i++){
						item=E[i];
						if(item=='('){
						push(item);
						}else if (isalnum(item))
		{
		printf("%c",item);
		}
		else if (item=='^'|| item=='*'||item=='/'||item=='+'||item=='-'){
		while(top!=-1&&((Priority(s[top])>Priority(item))||(Priority(s[top])==Priority(item)&&item!='^'))&&
		s[top]!='('){
		printf("%c",pop());
		}
		push(item);
		} else if (item==')'){
		while(top!=-1&&s[top]!='('){
		printf("%c",pop());
		}
		pop();
		}
		else
		{
		printf("invalid expression\n");
		break;
		}
		}
		}
		void evalPostfix()
		{
		char expr[100];
		int stack[50],evalTop=-1;
		char ch;
		int val,a,b,result;
		printf("enter postfix epression(a+b*c):");
		scanf("%s",expr);
		for(i=0; expr[i]!='\0';i++){
		ch=expr[i];
		if(isalpha(ch)){
		printf("enter the value for %c:",ch);
scanf("%d",&val);
stack[++evalTop]=val;
}
else if (isdigit(ch))
{
stack[++evalTop]=ch- '0';
}
else
{
if (evalTop<1){
printf("Error:not enough operands\n");
return;
}
b=stack[evalTop--];
a=stack[evalTop--];
switch (ch) {
case'+':result=a+b;
break;
case'-':result=a-b;
break;
case'*':result=a*b;
break;
case'/':
if(b==0){
printf("error:division by zero\n");
return;
}
result=a/b;
break;
//case'^':result=pow(a,b);
break;
default:
printf("invalid operator %c\n",ch);
return;
}
stack[++evalTop]=result;
}
}
if(evalTop!=0){
printf("error:invalid postfix expression\n");
return;
}
printf("result=%d\n",stack[evalTop]);
}				

output
----MENU----
1.infix to postfix conversion
2.evaluate postfix expression
3.Exit
enter the choice:1
enter size of expression7
enter the infix expression:(7*3)+2
postfix expression:73*2+

----MENU----
1.infix to postfix conversion
2.evaluate postfix expression
3.Exit
enter the choice:2
enter postfix epression(a+b*c):73*2+
result=23

----MENU----
1.infix to postfix conversion
2.evaluate postfix expression
3.Exit
enter the choice:3









