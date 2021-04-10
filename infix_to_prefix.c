#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 50

void push(char symbol);
int pop();
void infix_to_prefix();
int priority(char symbol);
int isEmpty();
void reverse_string();
void again_reverse_string();
char infix[MAX], prefix[MAX];
char stack[MAX];
int top;

int main()
{
        int value;
        top=-1;
        printf("Enter infix : ");
        gets(infix);
        reverse_string();     /* first ham given qestion ka inverse karenge */
        infix_to_prefix();    /* than inverse ko prefix me change karenge */
        again_reverse_string();   /* than again prefix ka inverse karenge */
        printf("Prefix : %s\n",prefix);    /* and than vo hamara final answer hoga jise ham print kar lenge*/
        return 0;

}/*End of main()*/
  void reverse_string()
    {
        int i;
        for(i=0 ; i<strlen(infix) ;i++ )
        {
            push(infix[i]);
        }
        for(i=0 ; i<strlen(infix) ; i++)
        {
            infix[i] = pop();
        }
    }
void again_reverse_string()
  {
      int i;
        for(i=0 ; i<strlen(prefix) ;i++ )
        {
            push(prefix[i]);
        }
        for(i=0 ; i<strlen(prefix) ; i++)
        {
            prefix[i] = pop();
        }
  }    
  void push(char symbol)
{
        if(top>MAX)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        stack[++top]=symbol;
}/*End of push()*/

int pop()
{
        if( isEmpty() )
        {
                printf("Stack underflow\n");
                exit(1);
        }
        return (stack[top--]);
}/*End of pop()*/
int isEmpty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}/*End of isEmpty()*/
void infix_to_prefix()
    { 
         int i,p=0;
        char next;
        char symbol;
        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        prefix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                while( !isEmpty( ) &&  priority(stack[top])> priority(symbol) )
                                        prefix[p++]=pop();
                                push(symbol);
                                break;
                        default: /*if an operand comes*/
                             prefix[p++]=symbol;
                        }
               
        }
        while(!isEmpty( ))
                prefix[p++]=pop();
        prefix[p]='\0';/*End prefix with'\0' to make it a string*/
         
         
}/*End of infix_to_postfix()*/
int priority(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default :
                return 0;
        }
}/*End of priority()    KISHAN GUPTA , DATE 09/04/2021 */

