/*
3314. 보충학습과 평균  D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBnA2jaxDsDFAWr&categoryId=AWBnA2jaxDsDFAWr&categoryType=CODE
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

        int result[5] = { 0 } ;
        int sum = 0 ;
        for( int i = 0 ; i < 5 ; i++ ) {
            scanf("%d" , &result[i] ) ;
            if( result[i] < 40 )
                result[i] = 40 ;

            sum += result[i] ;
        }

        printf("#%d %d\n" , T , sum / 5 ) ;
    }
    return 0 ;
}



















