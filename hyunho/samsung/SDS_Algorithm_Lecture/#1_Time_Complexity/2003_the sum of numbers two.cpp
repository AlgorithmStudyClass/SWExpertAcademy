/*
2003. 수들의 합 2
https://www.acmicpc.net/problem/2003

math problem
window 법
*/

// #include<stdio.h>
// using namespace stqd ;

// int data[10001] ;
// int N , M ;

// int main() {

//     scanf("%d %d" , &N , &M ) ;

//     for( int i = 1 ; i <= N ; i++ )
//         scanf("%d" , &data[i] ) ;

//     int right = 0 ;
//     int sum = 0 ;
//     int cnt = 0 ;

//     for( int i = 1 ; i <= N ; i++ ) {

//         while( right < N && sum < M )
//             sum += data[ ++right ] ;

//         if( sum == M )  //data[i] ~ data[right]의 합이 m이면 cnt++
//             cnt++ ;

//         sum -= data[i] ;    //data[i] ~ data[right]의 합 --> data[i+1] ~ data[right]의 합
//     }

//     printf("%d\n" , cnt ) ;

//     return 0 ;
// }



#include<iostream>
using namespace std ;

int N , M ;
int list[10001] ;

int main() {

    scanf("%d %d" , &N , &M ) ;

    for( int i = 1 ; i <= N ; i++ )
        scanf("%d" , &list[i] ) ;

    int sum = 0 ;
    int idx = 0 ;
    int ans = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {

        while( sum < M && idx <= N )
            sum += list[++idx] ;

        if( sum == M )
            ans++ ;

        sum -= list[i] ;
    }

    printf("%d\n" , ans ) ;
    return 0 ;
}



















