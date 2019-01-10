/*
2504. 괄호의 값
https://www.acmicpc.net/problem/2504
*/

#include<iostream>
#include<stack>
using namespace std ;

char str[31] ;
char tmp[31] ;

int main() {

    stack<char> stack ;
    int result = 0 ;

    scanf("%s" , str ) ;

    int tmp = 0 ;
    int flag = 0 ;
    for( int i = 0 ; i < strlen( str ) ; i++ ) {

        if( str[i] == '(' || str[i] =='[' ) {
            stack.push( str[i] ) ;
            flag = 0 ;
            result += tmp ;
            tmp = 0 ;
        }
        else {

            if( stack.top() == '(' ) {

                if( flag == 1 )
                    tmp *= 2 ;
                else {
                    tmp = 2 ;
                    flag = 1 ;
                }
            } else if( stack.top() == '[' ) {

                if( flag == 1 )
                    tmp *= 3 ;
                else {
                    tmp = 3 ;
                    flag = 1 ;
                }
            } 

            stack.pop() ;
        }
    }

    result += tmp ;

    printf("%d\n" , result ) ;

    return 0 ;
}



#include <stdio.h>
char str[100];
int stack[100];
long long int sum[100];
int top;
int main()
{
    scanf("%s",str);
    long long int ans = 0;
    top = 0;
    for(int i=0;str[i] != NULL;i++) sum[i]=0;
    for(int i=0;str[i] != NULL;i++) 
    {
        if(str[i]=='(')
        {
            stack[top++] = 2;
        }
        else if(str[i]=='[')
        {
            stack[top++] = 3;
        }
        else if(str[i]==')')
        {
            if(top == 0 || stack[top-1] != 2)
            {
                sum[0] = 0;
                break;
            }
            else
            {
                if(str[i-1]=='(') 
                    sum[top-1] += 2;
                else 
                    sum[top-1] += sum[top]*2;
                
                sum[top--] = 0;
            }
        }
        else if(str[i]==']')
        {
            if(top == 0 || stack[top-1] != 3)
            {
                sum[0] = 0;
                break;
            }
            else
            {
                if(str[i-1]=='[') 
                    sum[top-1] += 3;
                else 
                    sum[top-1] += sum[top]*3;

                sum[top--] = 0;
            }
        }
    }
    if(top>0) 
        sum[0]=0 ;
    printf("%lld",sum[0]);

}



