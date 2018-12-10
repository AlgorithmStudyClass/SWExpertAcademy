/*
5549. 홀수일까 짝수일까 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxpEDaAVoDFAW4&categoryId=AWWxpEDaAVoDFAW4&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        unsigned long long int num = 0 ;
        scanf("%lld" , &num ) ;

        if( num % 2 == 0 )
            printf("#%d %s\n" , T , "Even" ) ;
        else
            printf("#%d %s\n" , T , "Odd" ) ;
    }
    return 0 ;
}





