/*
1922. 네트워크 연결
https://www.acmicpc.net/problem/1922

Minimum Spanning Tree
최소 신장 트리( MST ) - 크루스칼
간선리스트로 표현
*/

#include<iostream>
#include<algorithm>
using namespace std ;

struct Edge {

    int from , to , cost ;
} ;

int N , M ;
Edge info[100001] ;
int list[1001] ;
int cnt ;
int ans ;

bool comp( const Edge &ref1 , const Edge &ref2 ) {
    return ref1.cost < ref2.cost ;
}

int func_find( int n1 ) {

    if( list[n1] == n1 ) return n1 ;
    else return list[n1] = func_find( list[n1] ) ;
}

void func_union( int n1 , int n2 ) {
    list[ func_find(n2) ] = func_find( n1 ) ;
}

int main() {

    scanf("%d" , &N ) ;

    for( int i = 1 ; i <= N ; i++ )
        list[i] = i ;

    scanf("%d" , &M ) ;
    for( int i = 0 ; i < M ; i++ )
        scanf("%d %d %d" , &info[i].from , &info[i].to , &info[i].cost ) ;

    sort( info , info + M , comp ) ;

    for( int i = 0 ; i < M ; i++ ) {

        if( func_find( info[i].from ) != func_find( info[i].to ) ) {
            func_union( info[i].from , info[i].to ) ;
            ans += info[i].cost ;
            cnt++ ;
        }

        if( cnt == N - 1 )
            break ;
    }

    printf("%d\n" , ans ) ;
    return 0 ;
}









