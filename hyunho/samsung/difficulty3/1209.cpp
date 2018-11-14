/*
1209. [S/W 문제해결 기본] 2일차 - Sum
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13_BWKACUCFAYh&categoryId=AV13_BWKACUCFAYh&categoryType=CODE
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

        scanf("%d" , &T ) ;

        int arr[100][100] = { 0 } ;
        for( int i = 0 ; i < 100 ; i++ ) {
            for( int j = 0 ; j < 100 ; j++ )
                scanf("%d" , &arr[i][j] ) ;
        }

        vector<int> result ;
        int sum3 = 0 ;
        int sum4 = 0 ;

        for( int i = 0 ; i < 100 ; i++ ) {
            int sum = 0 ;
            int sum2 = 0 ;
            for( int j = 0 ; j < 100 ; j++ ) {
                sum += arr[i][j] ;
                sum2 += arr[j][i] ;

                if( i == j )
                    sum3 += arr[i][j] ;

                if( 100 - ( i + j ) == 1 )
                    sum4 += arr[i][j] ;
            }
            result.push_back( sum ) ;
            result.push_back( sum2 ) ;
        }
        result.push_back( sum3 ) ;
        result.push_back( sum4 ) ;

        int maxResult = *max_element( result.begin() , result.end() ) ;

        printf("#%d %d\n" , T , maxResult ) ;
    }
    return 0 ;
}





















