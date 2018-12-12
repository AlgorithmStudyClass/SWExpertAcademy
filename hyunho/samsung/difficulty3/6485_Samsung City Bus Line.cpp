/*
6485. 삼성시의 버스 노선 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWczm7QaACgDFAWn&categoryId=AWczm7QaACgDFAWn&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

void countBus( int busStop[] , int A , int B ) {

    for( int i = A ; i <= B ; i++ )
        busStop[i]++ ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int busStop[5000] = { 0 } ;

        int N = 0 ;
        scanf("%d" , &N ) ;

        for( int i = 0 ; i < N ; i++ ) {

            int A = 0 , B = 0 ;
            scanf("%d %d" , &A , &B ) ;

            countBus( busStop , A , B ) ;
        }

        int P = 0 ;
        scanf("%d" , &P ) ;

        int *result = new int[ P ] ;
        for( int i = 0 ; i < P ; i++ )
            scanf("%d" , &result[i] ) ;

        printf("#%d " , T ) ;
        for( int i = 0 ; i < P ; i++ ) {
            printf("%d " , busStop[ result[i] ] ) ;
        }
        printf("\n") ;
    }
    return 0 ;
}





