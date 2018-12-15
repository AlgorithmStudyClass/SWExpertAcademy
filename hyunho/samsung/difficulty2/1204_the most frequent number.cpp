/*
1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기 D2
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh&categoryId=AV13zo1KAAACFAYh&categoryType=CODE
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

        scanf("%d" , &T ) ;

        int testScoreArr[1000] = { 0 } ;
        int testScoreCntArr[101] = { 0 } ;

        for( int i = 0 ; i < 1000 ; i++ ) {

            scanf("%d" , &testScoreArr[i] ) ;

            testScoreCntArr[ testScoreArr[i] ]++ ;
        }

        int *tmpArr = testScoreCntArr ;
        sort( tmpArr , tmpArr + 1000 , greater<int>() ) ;

        int equalNum[10] = { 0 } ;
        int size = 0 ;
        for( int i = 0 ; i < 101 ; i++ ) {

            if( tmpArr[0] == tmpArr[i] ) {
                equalNum[i] = tmpArr[i] ;
                size++ ;
            }
        }

        int result = 0 ;
        for( int i = 0 ; i < size ; i++ ) {
            for( int j = 0 ; j < 101 ; j++ ) {

                if( testScoreArr[j] == equalNum[i] ) {

                    if( result < testScoreArr[j] )
                        result = testScoreArr[j] ;
                }
            }
        }

        cout << "aa" << result << endl ;
    }
    return 0 ;
}








