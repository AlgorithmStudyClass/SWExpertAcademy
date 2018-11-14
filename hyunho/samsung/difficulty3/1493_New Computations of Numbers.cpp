/*
1493. 수의 새로운 연산 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b-QGqADMBBASw&categoryId=AV2b-QGqADMBBASw&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int arr[401][401] ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int start = 0 ;
    for( int i = 1 ; i <= 400 ; i++ ) {
        int d = i ;
        for( int j = 1 ; j <= 400 ; j++ ) {

            if( j == 1 ) {
                start += i ;
                arr[i][j] = start ;
            } else {
                // if( j > 350 - i + 1 )
                //     arr[i][j] = arr[i][j-1] + --d ;
                // else
                //     arr[i][j] = arr[i][j-1] + d++ ;
                arr[i][j] = arr[i][j-1] + d++ ;
            }
        }
    }

    int T = 0 ;
    while( T++ < testSize ) {

        int p = 0 , q = 0 ;
        scanf("%d %d" , &p , &q ) ;

        int X = 0 , Y = 0 ;
        int X2 = 0 , Y2 = 0 ;

        int cnt = 0 ;
        for( int i = 1 ; i <= 400 ; i++ ) {
            for( int j = 1 ; j <= 400 ; j++ ) {

                if( cnt == 2 )
                    break ;

                if( arr[i][j] == p ) {
                    X = i ; Y = j ;
                    cnt++ ;
                }

                if( arr[i][j] == q ) {
                    X2 = i ; Y2 = j ;
                    cnt++ ;
                }
            }
        }
        printf("#%d %d\n" , T , arr[X + X2][Y + Y2] ) ;
    }
    return 0 ;
}



















