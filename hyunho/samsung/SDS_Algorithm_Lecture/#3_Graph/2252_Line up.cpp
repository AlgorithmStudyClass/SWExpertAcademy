/*
2252. 줄 세우기
https://www.acmicpc.net/problem/2252

위상정렬
인접 리스트로 표현
*/

#include<iostream>
#include<queue>
#include <vector>
using namespace std ;

int N , M ;
vector< int > arr[ 32001 ] ;        //  vector< pair<int , int > > 로 안하는 이유는 indegree 만 필요해서
int degree[ 32001 ] ;
queue<int> que ;
int a , b ;

int main() {

    scanf( "%d %d" , &N , &M ) ;

    for( int i = 0 ; i < M ; i++ ) {

        scanf( "%d %d" , &a , &b ) ;

        arr[a].push_back(b);     //  인접 리스트 생성
        degree[b]++;            //  in degree ++ 
    }

    for( int i = 1 ; i <= N ; i++ ) {

        if( degree[i] == 0 )
            que.push( i ) ;
    }

    int result = 0 ;

    while( !que.empty() ) {

        result = que.front() ;
        printf( "%d " , result ) ; que.pop() ;

        for( int i = 0 ; i < arr[result].size() ; i++ ) {

            int p = arr[result][i] ;
            degree[p]-- ;

            if( degree[p] == 0 )
                que.push(p) ;
        }
    }

    return 0 ;
}

