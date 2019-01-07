/*
1806. 부분합
https://www.acmicpc.net/problem/1806
*/

#include<stdio.h>
using namespace std ;

int N , S ;
int data[100001] ;

int main() {

    scanf("%d %d" , &N , &S ) ;

    int sum = 0 ;
    int ans = N + 1 ;
    for( int i = 1 , start = 0 ; i <= N ; i++ ) {

        scanf("%d" , &data[i] ) ;
        sum += data[i] ;

        if( sum >= S ) {

            while( start < i && sum - data[start] >= S )
                sum -= data[start++] ;

            if( ans > i - start + 1 )
                ans = i - start + 1 ;
        }
    }

    if( ans == N + 1 )
        ans = 0 ;

    printf("%d\n" , ans ) ;

    return 0 ;
}

