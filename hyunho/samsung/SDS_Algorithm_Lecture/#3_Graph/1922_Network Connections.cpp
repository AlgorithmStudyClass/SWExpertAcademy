/*
1922. 네트워크 연결
https://www.acmicpc.net/problem/1922

최소 신장 트리( MST ) - 크루스칼
간선리스트로 표현
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

struct Edge {

    int from , to , cost ;
} ;

int N , M ;
Edge E[100000] ;
int unionArr[ 1001 ] ;

bool comp( const Edge &a , const Edge &b ) {
    return a.cost < b.cost ;    //  cost로 오름차순 정렬
}

int findCaptain( int n1 ) {

    if( unionArr[n1] == n1 ) return n1 ;
    else return unionArr[n1] = findCaptain( unionArr[n1] ) ;
}

void join( int n1 , int n2 ) {
    unionArr[ findCaptain(n2) ] = findCaptain( n1 ) ;
}

int main() {

    scanf("%d" , &N ) ;
    scanf("%d" , &M ) ;

    for( int i = 0 ; i < N + 1 ; i++ )
        unionArr[i] = i ;

    for( int i = 0 ; i < M ; i++ )
        scanf("%d %d %d" , &E[i].from , &E[i].to , &E[i].cost ) ;

    sort( E , E + M , comp ) ;  //  간선 cost 낮은것부터

    int cnt = 0 ;
    int ans = 0 ;
    for( int i = 0 ; i < M ; i++ ) {

        if( findCaptain( unionArr[ E[i].from ]) != findCaptain( unionArr[ E[i].to ] ) ) {   //  cycle 확인( union find )
            join( E[i].from , E[i].to ) ;
            ans += E[i].cost ;
            cnt++ ;

            if( cnt == N - 1 )  //  다 연결하면 간선은 정점 - 1 개 이다
                break ;
        }
    }

    printf("%d\n" , ans ) ;
    return 0 ;
}














