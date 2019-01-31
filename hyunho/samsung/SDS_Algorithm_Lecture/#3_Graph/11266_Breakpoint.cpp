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
int vOrder[100001] ;    //  방문순서 저장
int tOrder ;
int isCutVertex[100001] ;
int answer[100001] ;


int min( int a , int b ) {

    return ( a > b ) ? b : a ;
}

int dfs( int num , int p ) {

    if( vOrder[num] != 0 )  //  이미 간거라면 방문순서 리턴
        return vOrder[num] ;

    vOrder[num] = ++tOrder ;    //  방문순서 저장
    int minNum = vOrder[num] ;  //  지금 들어온 현재 방문 순서

    int childCnt = 0 ;  //  자식 수

    for( int i = 0 ; i < edge[num].size() ; i++ ) {

        int node = edge[num][i] ;
        if( node == p ) //  부모노드일 경우에는 계산 x
            continue ;

        if( vOrder[ node ] == 0 ) {

            childCnt++ ;   //  자식 수 갱신
            int low = dfs( node , num ) ;  //  dfs 탐색

            if( p != -1 && low >= vOrder[ num ] ) {
                cout << "low : " << low << " , " << "num : " << num << " , " << "vOrder : " << vOrder[num] << endl ;
                isCutVertex[ num ] = 1 ;
            }

            minNum = min( minNum , low ) ;
        }
        else
            minNum = min( minNum , vOrder[ node ] ) ;
    }

    if( p == -1 && childCnt >= 2 )
        isCutVertex[num] = 1 ;

    return minNum ;
}

int main() {

    scanf("%d %d", &V , &E ) ;

    for( int i = 0 ; i <= V ; i++ ) {
        vOrder[i] = 0 ;
        isCutVertex[i] = 0 ;
    }

    for( int i = 0 ; i < E ; i++ ) {

        scanf("%d %d" , &from , &to ) ;
        edge[from].push_back( to ) ;
        edge[to].push_back( from ) ;
    }

    tOrder = 0 ;
    for( int i = 1 ; i <= V ; i++ ) {

        if( vOrder[i] != 0 )
            continue ;

        dfs( i , -1 ) ;
    }

    int index = 0 ;
    for( int i = 1 ; i <= V ; i++ ) {

        if( isCutVertex[i] )
            answer[index++] = i ;
    }

    printf("%d\n" , index ) ;
    for( int i = 0 ; i < index ; i++ )
        printf("%d " , answer[i] ) ;
    printf("\n");

    return 0 ;
}













