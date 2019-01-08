/*
2748. 피보나치 수 2
https://www.acmicpc.net/problem/2748
*/

#include<stdio.h>
using namespace std ;

int N = 0 ;
long long int fibo[91] ;

int main() {

    scanf("%d" , &N ) ;

    fibo[1] = 1 , fibo[2] = 1 ;
    for( int i = 3 ; i <= N ; i++ )
        fibo[i] = fibo[ i - 1 ] + fibo[ i - 2 ] ;

    printf("%lld\n" , fibo[N] ) ;

    return 0 ;
}










