/*
1208. [S/W 문제해결 기본] 1일차 - Flatten   D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV139KOaABgCFAYh&categoryId=AV139KOaABgCFAYh&categoryType=CODE
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 10 ;
    int T = 0 ;
    while( T++ < testSize ) {

        int dmp = 0 ;
        scanf("%d" , &dmp ) ;

        int arr[100] = { 0 } ;
        for( int i = 0 ; i < 100 ; i++ )
            scanf("%d" , &arr[i] ) ;

        int result = 0 ;
        for( int i = 0 ; i < dmp ; i++ ) {

            int max = arr[0] , min = arr[0] ;
            int maxIndex = 0 , minIndex = 0 ;
            for( int i = 0 ; i < 100 ; i++ ) {

                if( max < arr[i] ) {
                    max = arr[i] ;
                    maxIndex = i ;
                }

                if( min > arr[i] ) {
                    min = arr[i] ;
                    minIndex = i ;
                }
            }

            arr[maxIndex]-- ;
            arr[minIndex]++ ;

            max = arr[0] ;
            min = arr[0] ;
            maxIndex = 0 ;
            minIndex = 0 ;
            for( int i = 0 ; i < 100 ; i++ ) {

                if( max < arr[i] ) {
                    max = arr[i] ;
                    maxIndex = i ;
                }

                if( min > arr[i] ) {
                    min = arr[i] ;
                    minIndex = i ;
                }
            }

            result = arr[maxIndex] - arr[minIndex] ;
        }
        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}



















