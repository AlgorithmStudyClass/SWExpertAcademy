/*
6057. 그래프의 삼각형 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbHcWd6AFcDFAV0&categoryId=AWbHcWd6AFcDFAV0&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int cnt ;

void check( int **arr , int N , int index1 , int index2 ) {

    for( int i = index2 + 1  ; i < N + 1 ; i++ ) {

        if( arr[ index2 ][ i ] && arr[ i ][ index1 ] ) {
            cnt++ ;
        }
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        cnt = 0 ;

        int N = 0 , M = 0 ;
        scanf("%d %d" , &N , &M ) ;

        int **arr = new int*[ N + 1 ] ;
        for( int i = 0 ; i < N + 1 ; i++ )
            arr[i] = new int[N + 1] ;

        for( int i = 0 ; i < N + 1  ; i++ )
            for( int j = 0 ; j < N + 1 ; j++ )
                arr[i][j] = 0 ;

        for( int i = 0 ; i < M ; i++ ) {

            int x = 0 , y = 0 ;
            scanf("%d %d" , &x , &y ) ;
            arr[x][y] = 1 ;
            arr[y][x] = 1 ;

        }

        for( int i = 1 ; i <= N ; i++ ) {
            for( int j = i + 1 ; j <= N ; j++ ) {

                if( arr[i][j] ) {
                    check( arr , N , i , j ) ;
                }
            }
        }
        
        printf("#%d %d\n" , T , cnt ) ;

        for( int i = 0 ; i < N + 1 ; i++ )
            delete []arr[i] ;
        delete []arr ;
    }
    return 0 ;
}



