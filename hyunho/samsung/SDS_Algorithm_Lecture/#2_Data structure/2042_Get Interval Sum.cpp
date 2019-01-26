/*
2042. 구간의 합 구하기
https://www.acmicpc.net/problem/2042

index tree
*/

#include<iostream>
using namespace std ;

int N , M , K ;
long long int indexTree[1000000*4] ;

int main() {

    scanf("%d %d %d" , &N , &M , &K ) ;

    int idx = 1 ;
    while( idx < N )
        idx *= 2 ;

    for( int i = idx ; i < idx + N ; i++ )
        scanf("%lld" , &indexTree[i] ) ;

    for( int i = idx-1 ; i >= 1 ; i-- )
        indexTree[i] = indexTree[i*2] + indexTree[i*2 + 1] ;


    for( int i = 0 ; i < M + K ; i++ ) {

        int a , b , c ;
        scanf("%d %d %d" , &a , &b , &c ) ;

        if( a == 1 ) {

            int cur = b + idx -1 ;
            long long int data = (long long int)( c - indexTree[cur]) ;
            while( cur > 0 ) {
                indexTree[cur] += data ;
                cur /= 2 ;
            }
        } else {

            int s = b + idx - 1 ;
            int e = c + idx - 1 ;
            long long int ans = 0 ;

            while( s <= e ) {

                if( s % 2 == 1 )
                    ans += indexTree[s] ;

                if( e % 2 == 0 )
                    ans += indexTree[e] ;

                s = ( s + 1 ) / 2 ;
                e = ( e - 1 ) / 2 ;
            }
            printf("%lld\n" , ans ) ;
        }
    }

    return 0 ;
}















