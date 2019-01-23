/*
2805. 나무자르기
https://www.acmicpc.net/problem/2805

이분 탐색
*/

// #include<stdio.h>
// using namespace std ;

// int data[1000001] ;
// int N , M ;

// int max( int a , int b ) {

//     return ( a > b ) ? a : b ;
// }

// long long int calc( int height ) {

//     long long int sum = 0 ;
//     for( int i = 1 ; i <= N ; i++ ) {

//         if( data[i] > height )
//             sum += ( data[i] - height ) ;
//     }

//     return sum ;
// }

// int main() {

//     scanf("%d %d" , &N , &M ) ;

//     int mx = 0 ;
//     for( int i = 1 ; i <= N ; i++ ) {
//         scanf("%d" , &data[i] ) ;
//         mx = max( data[i] , mx ) ;
//     }

//     int l = 0 , r = mx ;
//     int mid , result = 0 ;
//     long long int tmp ;

//     while( l < r ) {

//         mid = ( l + r ) / 2 ;
//         tmp = calc( mid ) ;

//         if( tmp < M )
//             r = mid ;
//         else {
//             result = mid ;
//             l = mid + 1 ;
//         }
//     }

//     printf("%d\n" , result ) ;

//     return 0 ;
// }


#include<iostream>
using namespace std ;

int N , M ;
int list[1000001] ;
int ans ;

int max_func( int a , int b ) {
    return ( a > b )? a : b ;
}

long long int calc( int mid ) {

    long long int ret = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {

        if( list[i] > mid )
            ret += ( list[i] - mid ) ;
    }

    return ret ;
}

int main() {

    scanf("%d %d" , &N , &M ) ;

    int maxNum = -1 ;
    for( int i = 1 ; i <= N ; i++ ) {
        scanf("%d" , &list[i] ) ;
        maxNum = max_func( maxNum , list[i] ) ;
    }

    int l = 0 ;
    int r = maxNum ;
    int mid ;
    long long int tmp ;

    while( l < r ) {

        mid = ( l + r ) / 2 ;
        tmp = calc( mid ) ;

        if( tmp < M )
            r = mid ;
        else {
            ans = mid ;
            l = mid + 1 ;
        }
    }

    printf("%d\n" , ans ) ;
    return 0 ;
}


















