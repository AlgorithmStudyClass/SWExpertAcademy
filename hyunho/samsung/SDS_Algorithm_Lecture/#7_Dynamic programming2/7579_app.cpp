/*
7579. 앱
https://www.acmicpc.net/problem/7579
*/

#include<iostream>
using namespace std ;

int N , M ;
int D[101][10001] ;
int memoryList[101] ;
int costList[101] ;

int max( int a , int b ) {
    return (a > b)? a : b ;
}

int min( int a , int b ) {
    return (a > b)? b : a ;
}

int main() {

    scanf("%d %d" , &N , &M ) ;

    for( int i = 1 ; i <= N ; i++ )
        scanf("%d" , &memoryList[i] ) ;

    int costSum = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {
        scanf("%d" , &costList[i] ) ;
        costSum += costList[i] ;
    }

    int ans = N * 100 ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int c = 0 ; c <= costSum ; c++ ) {

            if( c < costList[i] )
                D[i][c] = D[i-1][c] ;
            else
                D[i][c] = max( D[i-1][ c-costList[i] ] + memoryList[i] , D[i-1][c] ) ;
            

            if( D[i][c] >= M )
                ans = min( c , ans ) ;
        }
    }

    printf("%d\n" , ans ) ;
    return 0 ;
}


