/*
1753. 최단경로
https://www.acmicpc.net/problem/1753

다익스트라 알고리즘( 최단경로 )
priority queue( heap )
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
#define INF 200000

struct Edge {

    int node , cost ;

    Edge( int node , int cost ) {

        this->node = node ;
        this->cost = cost ;
    }

    //  c 에서의 priority queue ( heap ) 은 max heap 으로 작동 되기 때문에 overide 해서 minHeap으로 변환
    bool operator<( const Edge &ref) const {
        return cost > ref.cost ;
    }


} ;

int V , E ;
int startNode ;
vector<Edge> path[20001] ;
int dist[20001] ;
int a , b , c ;

int main() {

    scanf( "%d %d" , &V , &E ) ;
    scanf( "%d" , &startNode ) ;

    for( int i = 0 ; i <= V ; i++ ) {
        path[i].clear() ;
        dist[i] = INF ;
    }

    for( int i = 0 ; i < E ; i++ ) {

        scanf( "%d %d %d" , &a , &b , &c ) ;
        path[a].push_back( Edge( b , c ) ) ;
    }

    priority_queue<Edge> pq ;
    pq.push( Edge( startNode , 0 ) ) ;
    dist[startNode] = 0 ;

    while( !pq.empty() ) {

        Edge info = pq.top() ; pq.pop() ;

        int node = info.node ;
        int cost = info.cost ;

        if( dist[node] != cost )
            continue ;

        for( Edge next : path[node] ) {

            if( dist[ next.node ] > dist[ node ] + next.cost ) {

                dist[ next.node ] = dist[ node ] + next.cost ;
                pq.push( Edge( next.node , dist[ next.node ] ) ) ;
            }
        }
    }

    for( int i = 1 ; i <= V ; i++ ) {

        if( dist[i] != INF )
            printf("%d\n" , dist[i] ) ;
        else
            printf("INF\n" ) ;
    }
    return 0 ;
}









