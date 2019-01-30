/*
1717. 집합의 표현
https://www.acmicpc.net/problem/1717

union find
( = disjoint set )
*/

#include<iostream>
using namespace std ;

int N , M ;
int list[10000001] ;

int func_find( int n1 ) {

    if( list[n1] == n1 ) return n1 ;
    else return list[n1] = func_find( list[n1] ) ;
}

void func_union( int n1 , int n2 ) {
    list[ func_find( n2 ) ] = func_find( n1 ) ;
}

int main() {

    scanf("%d %d" , &N , &M ) ;

    for( int i = 0 ; i <= N ; i++ )
        list[i] = i ;

    for( int i = 0 , a , b , c ; i < M ; i++ ) {

        scanf("%d" , &a ) ;

        if( a == 0 ) {   //  union
            
            scanf("%d %d" , &b , &c ) ;
            func_union( b , c ) ;
        } else if( a == 1 ) {    //  확인

            scanf("%d %d" , &b , &c ) ;

            if( func_find( b ) == func_find( c ) )
                printf("YES\n" ) ;
            else
                printf("NO\n" ) ;
        }
    }
    return 0 ;
}






























