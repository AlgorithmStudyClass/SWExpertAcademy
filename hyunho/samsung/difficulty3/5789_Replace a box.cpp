/*
5789. 현주의 상자 바꾸기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWYygN36Qn8DFAVm&categoryId=AWYygN36Qn8DFAVm&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

void change( int *arr , int index , int L , int R ) {

    for( int i = L -1 ; i <= R - 1 ; i++ )
        arr[i] = index ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N = 0 , Q = 0 ;
        scanf("%d %d" , &N , &Q ) ;

        int *arr = new int[ N ] ;
        for( int i = 0 ; i < N ; i++ )
            arr[i] = 0 ;

        for( int i = 1 ; i <= Q ; i++ ) {

            int L = 0 , R = 0 ;
            scanf("%d %d" , &L , &R ) ;

            change( arr , i , L , R ) ;
        }

        printf("#%d " , T ) ;
        for( int i = 0 ; i < N ; i++ )
            printf("%d " , arr[i] ) ;
        printf("\n") ;
    }
    return 0 ;
}









