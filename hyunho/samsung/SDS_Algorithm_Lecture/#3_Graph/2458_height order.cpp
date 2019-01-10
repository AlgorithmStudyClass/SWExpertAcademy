/*
2458. 키 순서
https://www.acmicpc.net/problem/2458

위상정렬
인접 리스트로 표현
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

int N , M ;
vector<int> edge[ 501 ] ;   //  학생 1부터 시작
int degree[ 501 ] ;
queue<int> que ;
int a , b ;

int main() {

    scanf( "%d %d" , &N , &M ) ;

    for( int i = 0 ; i < M ; i++ ) {

        scanf("%d %d" , &a , &b ) ;

        edge[b].push_back( a ) ;
        degree[a]++ ;
    }

    int ans = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {

        if( degree[i] == 0 ) {
            que.push( i ) ;
            ans++ ;
        }
    }

    int root = 0 ;
    while( !que.empty() ) {


    }




}










