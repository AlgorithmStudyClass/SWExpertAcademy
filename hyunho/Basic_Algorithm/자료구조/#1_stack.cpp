/*
10828. 스택
https://www.acmicpc.net/problem/10828
*/

#include<iostream>
#include<cstring>
#include<stack>
using namespace std ;

int N ;
char text[6] ;

int main() {

    stack<int> stack ;

    scanf("%d" , &N ) ;

    for( int i = 0 , num ; i < N ; i++ ) {

        scanf("%s" , text ) ;

        if( !strcmp( text , "push" ) ) {

            scanf("%d" , &num ) ; 
            stack.push( num ) ;
        } else if( !strcmp( text , "top" ) ) {
            if( !stack.empty() )
                printf("%d\n" , stack.top() ) ;
            else
                printf("-1\n" ) ;
        }
        else if( !strcmp( text , "size" ) )
            printf("%lu\n" , stack.size() ) ;
        else if( !strcmp( text , "empty" ) )
            printf("%d\n" , stack.empty() ) ;
        else if( !strcmp( text , "pop" ) ) {

            if( !stack.empty() ) {
                printf("%d\n" , stack.top() ) ;
                stack.pop() ;
            } else
                printf("-1\n" ) ;
        }
    }
    return 0 ;
}




