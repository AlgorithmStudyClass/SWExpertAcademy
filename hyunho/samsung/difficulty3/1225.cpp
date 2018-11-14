/*
1225. [S/W 문제해결 기본] 7일차 - 암호생성기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14uWl6AF0CFAYD&categoryId=AV14uWl6AF0CFAYD&categoryType=CODE&&&
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

        scanf("%d" , &T ) ;

        vector<int> vecNum ;
        for( int i = 0 ; i < 8 ; i++ ) {
            int tmp = 0 ;
            scanf("%d" , &tmp ) ;
            vecNum.push_back( tmp ) ;
        }

        while( true ) {

            for( int i = 0 ; i < 5 ; i++ ) {

                if( vecNum[7] == 0 ) break ;

                int tmp = vecNum[0] - ( i + 1 ) ;
                if( tmp < 0 ) tmp = 0 ;
                vecNum.erase( vecNum.begin() ) ;
                vecNum.push_back( tmp ) ;
            }

            if( vecNum[7] == 0 ) break ;
        }

        printf("#%d " , T ) ;
        for( int i = 0 ; i < 8 ; i++ )
            printf("%d " , vecNum[i] ) ;
        printf( "\n" ) ;
    }

    return 0 ;
}
























