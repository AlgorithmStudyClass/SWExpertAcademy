/*
3809. 화섭이의 정수 나열 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHz7xD6A20DFAVB&categoryId=AWHz7xD6A20DFAVB&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N = 0 ;
        scanf("%d" , &N ) ;

        int arr[1000] = { 0 } , temp[1000] = { 0 } ;

        for( int i = 0 ; i < N ; i++ ) {

            scanf("%d" , &temp[i] ) ;
            arr[ temp[i] ]++ ;

            if( i > 0 )
                arr[ temp[ i - 1 ] * 10 + temp[ i ] ]++ ;

            if( i > 1 )
                arr[ temp[ i - 2 ] * 100 + temp[ i - 1 ] * 10 + temp[ i ] ]++ ;
        }

        int result = 0 ;
        for( int i = 0 ; i < 1000 ; i++ ) {

            if( arr[i] == 0 ) {
                result = i ;
                break ;
            }
        }

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}











