/*
1753. 최단경로
https://www.acmicpc.net/problem/1753

다익스트라 알고리즘( 최단경로 )
priority queue( heap )
*/

#include<iostream>
#include<vector>
#include<queue>
#define INF 200000
using namespace std ;

struct Edge {

    int to , cost ;

    Edge( int to , int cost ) {
        this->to = to ;
        this->cost = cost ;
    }

    //  c 에서의 priority queue ( heap ) 은 max heap 으로 작동 되기 때문에 overide 해서 minHeap으로 변환
    bool operator < ( const Edge &ref ) const {
        return cost > ref.cost ;
    }

} ;

int V , E , K ;
vector<Edge> info[20001] ;
int dist[20001] ;
int ans ;

int main() {

    scanf("%d %d %d" , &V , &E , &K ) ;

    for( int i = 1 ; i <= V ; i++ )
        dist[i] = INF ;

    for( int i = 0 , u , v , w ; i < E ; i++ ) {
        scanf("%d %d %d" , &u , &v , &w ) ;
        info[u].push_back( Edge( v , w ) ) ;
    }

    priority_queue<Edge> pq ;
    pq.push( Edge( K , 0 ) ) ;
    dist[K] = 0 ;

    while( !pq.empty() ) {

        Edge tmp = pq.top() ; pq.pop() ;

        int to = tmp.to ;
        int cost = tmp.cost ;

        ans += cost ;

        if( dist[to] != cost )  //  왜 있는거지
            continue ;

        for( int i = 0 ; i < info[to].size() ; i++ ) {

            Edge next = info[to][i] ;

            if( dist[ next.to ] > dist[ to ] + next.cost ) {
                dist[ next.to ] = dist[ to ] + next.cost ;
                pq.push( Edge( next.to , dist[ next.to ]  ) ) ;
            }
        }
    }

    for( int i = 1 ; i <= V ; i++ ) {

        if( dist[i] != INF )
            printf("%d\n" , dist[i] ) ;
        else
            printf("INF\n" ) ;
    }

    cout << "cost : " << ans << endl ;
    return 0 ;
}























