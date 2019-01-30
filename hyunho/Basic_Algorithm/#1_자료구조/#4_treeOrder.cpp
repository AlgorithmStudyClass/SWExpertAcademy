/*
1991. 트리 순회
https://www.acmicpc.net/problem/1991
*/


#include<iostream>
using namespace std ;

struct Node {
    int parent , val , left , right ;

    Node() {
        parent = -1 ;
        val = -1 ;
        left = -1 ;
        right = -1 ;
    }
} ;

int N ;
Node list[27] ;
char str[10] ;

void preOrder( int node ) {

    printf("%c" , list[node].val ) ;
    if( list[node].left != -1 )
        preOrder( list[node].left ) ;

    if( list[node].right != -1 )
        preOrder( list[node].right ) ;
}

int main() {

    scanf("%d " , &N ) ;

    for( int i = 0 ; i < N ; i++ ) {

        char p , l , r ;
        fgets( str , sizeof( str ) , stdin ) ;
        p = str[0] ;
        l = str[2] ;
        r = str[4] ;

        list[p-'A'].val = p ;

        if( l != '.' ) {
            list[p-'A'].left = l-'A' ;
            list[l-'A'].parent = p-'A' ;
        }

        if( r != '.' ) {
            list[p-'A'].right = r-'A' ;
            list[r-'A'].parent = p-'A' ;
        }

    }

    preOrder( 0 ) ;
    printf("\n") ;


    return 0 ;
}
