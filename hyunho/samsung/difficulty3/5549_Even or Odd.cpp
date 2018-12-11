/*
5549. 홀수일까 짝수일까 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxpEDaAVoDFAW4&categoryId=AWWxpEDaAVoDFAW4&categoryType=CODE
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

        char input[101] = "" ;
        scanf("%s" , input ) ;

        int size = strlen( input ) ;
        int num = int( input[ size - 1 ] ) ;

        if( num % 2 == 0 )
            printf("#%d %s\n" , T , "Even" ) ;
        else
            printf("#%d %s\n" , T , "Odd" ) ;
    }
    return 0 ;
}





