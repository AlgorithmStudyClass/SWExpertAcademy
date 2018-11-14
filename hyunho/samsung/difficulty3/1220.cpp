/*
1220. [S/W 문제해결 기본] 5일차 - Magnetic 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14hwZqABsCFAYD&categoryId=AV14hwZqABsCFAYD&categoryType=CODE 
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
    while( T < testSize ) {

        int num = 0 ;
        scanf( "%d" , &num ) ;

        int arr[num][num] ;

        for( int i = 0 ; i < num ; i++ ) {
            for( int j = 0 ; j < num ; j++ )
                scanf("%d" , &arr[i][j] ) ;
        }

        int cnt = 0 ;
        int flag = 0 ;
        for( int i = 0 ; i < num ; i++ ) {
            for( int j = 0 ; j < num ; j++ ) {

                if( flag == 1 ) {
                    if( arr[j][i] == 2 ) {
                        cnt++ ;
                        flag = 0 ;
                    }
                }
                else {
                    if( arr[j][i] == 1 )
                        flag = 1 ;
                }
            }
            flag = 0 ;
        }

        printf("#%d %d\n" , ( T + 1 ) , cnt ) ;

        T++ ;
    }

    return 0 ;
}
























