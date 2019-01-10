/*
2805. 나무자르기
https://www.acmicpc.net/problem/2805
*/

#include<stdio.h>
using namespace std ;

int data[1000001] ;
int N , M ;

int max( int a , int b ) {

    return ( a > b ) ? a : b ;
}

long long int calc( int height ) {

    long long int sum = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {

        if( data[i] > height )
            sum += ( data[i] - height ) ;
    }

    return sum ;
}

int main() {

    scanf("%d %d" , &N , &M ) ;

    int mx = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {
        scanf("%d" , &data[i] ) ;
        mx = max( data[i] , mx ) ;
    }

    int l = 0 , r = mx ;
    int mid , result = 0 ;
    long long int tmp ;

    while( l < r ) {

        mid = ( l + r ) / 2 ;
        tmp = calc( mid ) ;

        if( tmp < M )
            r = mid ;
        else {
            result = mid ;
            l = mid + 1 ;
        }
    }

    printf("%d\n" , result ) ;

    return 0 ;
}













