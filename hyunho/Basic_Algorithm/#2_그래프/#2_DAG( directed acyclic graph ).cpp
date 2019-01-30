/*
2252. 줄 세우기
https://www.acmicpc.net/problem/2252

위상정렬 DAG
인접 리스트로 표현
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

int N , M ;
vector<int> list[32001] ;
int indegree[32001] ;
queue<int> que ;

int main() {

    scanf("%d %d" , &N , &M ) ;

    for( int i = 0 , a , b ; i < M ; i++ ) {

        scanf("%d %d" , &a , &b ) ;
        list[a].push_back( b ) ;
        indegree[b]++ ;
    }

    for( int i = 1 ; i <= N ; i++ ) {
        if( indegree[i] == 0 )
            que.push( i ) ;
    }

    while( !que.empty() ) {

        int tmp = que.front() ; que.pop() ;
        printf("%d " , tmp ) ;

        for( int i = 0 ; i < list[tmp].size() ; i++ ) {

            int to = list[tmp][i] ;
            indegree[to]-- ;

            if( indegree[to] == 0 )
                que.push(to) ;
        }
    }
    printf("\n") ;
    return 0 ;
}

























