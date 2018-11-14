/*
2805. 농작물 수확하기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB&categoryId=AV7GLXqKAWYDFAXB&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int size = 0 ;
        scanf("%d" , &size ) ;

        char **inputArr = new char*[ size ] ;           //  입력받는 수 2차원 char 배열
        for( int i = 0 ; i < size ; i++ )
            inputArr[i] = new char[ size ] ;

        for( int i = 0 ; i < size ; i++ ) {
            for( int j = 0 ; j < size ; j++ ) {
                cin >> inputArr[i][j] ;
            }
        }

        int sum = 0 ;
        int index = size - 2 ;
        for( int i = 0 ; i < size ; i++ ) {
            if( i <= size/2 ) {
                for( int j = size/2 - i ; j <= size/2 + i ; j++ )
                    sum += inputArr[i][j] - '0' ;
            } else {
                for( int j = ( i - size/2 ) ; j <= index ; j++ )
                    sum += inputArr[i][j] - '0' ;
                index-- ;
            }
        }

        printf("#%d %d\n" , T , sum ) ;
    }
    return 0 ;
}


