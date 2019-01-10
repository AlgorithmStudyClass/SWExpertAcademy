/*
1717. 집합의 표현
https://www.acmicpc.net/problem/1717

union find
*/

#include<iostream>
using namespace std ;

int N , M ;
int arr[ 1000001 ] ;
int a , b , c ;

int findCaptain( int n1 ) {

    if( arr[n1] == n1 ) return n1 ;
    else return arr[n1] = findCaptain( arr[n1] ) ;

}

void unionArr( int n1 , int n2 ) {

    arr[findCaptain( n2 )] = findCaptain( n1 ) ;
}

int main() {

    scanf("%d %d" , &N , & M ) ;

    for( int i = 0 ; i < N + 1 ; i++ )
        arr[i] = i  ;

    for( int i = 0 ; i < M ; i++ ) {

        scanf("%d %d %d" , &a , &b , &c ) ;

        if( a == 0 ) {

            if( b != c )
                unionArr( b , c ) ;

        } else if( a == 1 ) {

            if( findCaptain(arr[b]) == findCaptain(arr[c]) )
                printf("YES\n" ) ;
            else
                printf("NO\n" ) ;
        }
    }

    
    return 0 ;
}




