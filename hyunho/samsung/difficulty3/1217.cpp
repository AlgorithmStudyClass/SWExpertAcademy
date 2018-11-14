/*
1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14dUIaAAUCFAYD&categoryId=AV14dUIaAAUCFAYD&categoryType=CODE
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
        int N = 0 , M = 0 ;
        scanf("%d" , &N ) ;
        scanf("%d" , &M ) ;

        int result = 1 ;
        for( int i = 0 ; i < M ; i++ )
            result *= N ;

        printf("#%d %d\n" , T , result ) ;
    }

    return 0 ;
}























