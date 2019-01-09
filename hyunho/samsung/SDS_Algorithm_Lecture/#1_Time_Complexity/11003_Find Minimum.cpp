/*
1806. 부분합
https://www.acmicpc.net/problem/1806
*/

#include<stdio.h>
#include<deque>

using namespace std ;

int N , L ;

struct info {
    int num , idx ;

    info( int n1 , int n2 ) {
        num = n1 ;
        idx = n2 ;
    }
} ;

char ans[12*5000000+1];
int ans_len;


int main() {

    scanf("%d %d" , &N , &L ) ;

    deque<info> que ;
    ans_len = 0 ;

    for( int i = 0 ; i < N ; i++ ) {

        int a = 0 ;
        scanf("%d" , &a ) ;

        while( !que.empty() && que.back().num > a )
            que.pop_back() ;

        // que.push_back( {( a , i )} ) ;   컴파일러
        que.push_back( info( a , i ) ) ;

        if( i - L + 1 >= 0 && que.front().idx < i - L + 1 )
            que.pop_front() ;

        ans_len += sprintf( &ans[ans_len] , "%d " , que.front().num ) ;
    }

    printf("%s\n" , ans ) ;

    return 0 ;
}








