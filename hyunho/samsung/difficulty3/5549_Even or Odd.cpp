/*
2806. N-Queen D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB&categoryId=AV7GKs06AU0DFAXB&categoryType=CODE
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





