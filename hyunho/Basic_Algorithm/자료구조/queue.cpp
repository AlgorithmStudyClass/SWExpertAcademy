/*
10845. 큐
https://www.acmicpc.net/problem/10845
*/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std ;

int N ;
char text[6] ;

int main() {

    queue<int> que ;

    scanf("%d" , &N ) ;

    for( int i = 0 , num ; i < N ; i++ ) {

        scanf("%s" , text ) ;

        if( !strcmp( text , "push" ) ) {

            scanf("%d" , &num ) ; 
            que.push( num ) ;
        } else if( !strcmp( text , "front" ) ) {
            if( !que.empty() )
                printf("%d\n" , que.front() ) ;
            else
                printf("-1\n" ) ;
        }
        else if( !strcmp( text , "back" ) ) {
            if( !que.empty() )
                printf("%d\n" , que.back() ) ;
            else
                printf("-1\n" ) ;
        }
        else if( !strcmp( text , "empty" ) )
            printf("%d\n" , que.empty() ) ;
        else if( !strcmp( text , "size" ) )
            printf("%lu\n" , que.size() ) ;
        else if( !strcmp( text , "pop" ) ) {

            if( !que.empty() ) {
                printf("%d\n" , que.front() ) ;
                que.pop() ;
            } else
                printf("-1\n" ) ;
        }
    }
    return 0 ;
}



