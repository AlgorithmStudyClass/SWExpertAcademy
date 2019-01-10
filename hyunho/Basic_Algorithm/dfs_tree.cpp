/*
11266. 단절점
https://www.acmicpc.net/problem/11266

DFS 이용한 단절점
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

int V , E ;
vector<int> edge[100001] ;
int from , to ;
int visit[100001] ;

void dfs( int num ) {

    visit[num] = 1 ;

    cout << num << " " ;

    for( int i = 0 ; i < edge[num].size() ; i++ ) {

        if( visit[ edge[num][i] ] == 0 )
            dfs( edge[num][i] ) ;
    }
}


int main() {

    scanf("%d %d", &V , &E ) ;

    for( int i = 0 ; i <= V ; i++ )
        visit[i] = 0 ;

    for( int i = 0 ; i < E ; i++ ) {

        scanf("%d %d" , &from , &to ) ;
        edge[from].push_back( to ) ;
        edge[to].push_back( from ) ;
    }

    dfs( 1 ) ;
    cout << endl ;

    return 0 ;


}













