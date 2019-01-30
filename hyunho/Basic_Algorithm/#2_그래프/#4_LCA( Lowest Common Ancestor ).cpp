/*
11438. LCA2
https://www.acmicpc.net/problem/11438

최소 공통 조상( LCA )
인접리스트를 이용하여 BFS 형태로 트리 생성
*/

#include<iostream>
#include<queue>
#define KMAX 17 // 2^17 = 131072
using namespace std ;

int N , M ;
vector<int> edge[100001] ;
int from , to ;
int depth[100001] ; //  visit 으로 사용 가능
int par[KMAX+1][100001]; 

int main() {

    scanf("%d" , &N ) ;

    for( int i = 0 ; i <= N ; i++ ) {
        depth[i] = -1 ;
        for( int k = 0 ; k < KMAX + 1 ; k++ ) 
            par[k][i]=0;
    }

    int x , y = 0 ;
    for( int i = 0 ; i < N - 1 ; i++ ) {
        scanf("%d %d" , &from , &to ) ;

        edge[from].push_back(to) ;
        edge[to].push_back(from) ;
    }

    //  bfs 이용한 트리 생성 및 depth( 깊이 ) , par( 부모정보 )
    queue<int> que ;
    que.push( 1 ) ;
    depth[1] = 0 ;
    par[0][1] = 1 ; //  1의 1번째 위 조상은 1이다 초기화

    int tmp = 0 ;
    while( !que.empty() ) {

        tmp = que.front() ; que.pop() ;

        for( int i = 0 ; i < edge[tmp].size() ; i++ ) {
            if( depth[edge[tmp][i]] == -1 ) {
                que.push( edge[tmp][i] ) ;
                depth[edge[tmp][i]] = depth[tmp] + 1 ;
                par[0][ edge[tmp][i] ] = tmp ;      //  2 - 4 일때 edge[2][4] = 2 ;
            }
        }
    }

    //  dp 형식으로 점화식 채움 부모의 정보 가지고 있음
    for( int k = 1 ; k < KMAX + 1 ; k++ ) {
        for( int n = 1 ; n <= N ; n++ )
            par[k][n] = par[ k - 1 ][ par[ k - 1 ][n] ] ;
    }


    scanf("%d" , &M ) ;

    
    for( int i = 0 , a , b ; i < M ; i++ ) {

        scanf("%d %d" , &a , &b ) ;

        //  depth 맞추기
        if( depth[a] > depth[b] ) { //  a가 더 아래에 있어서 a를 b까지 올려줘야함

            for( int k = KMAX ; k >= 0 ; k-- ) {

                if( a!= b && depth[ par[k][a] ] >= depth[b] )   //  a == b 일때는 x // depth 최대 부터 올리면서 depth[b] 보다 더 작으면 좀 낮춰 올리고 반복해서 내려오다가 같거나 클때 a 변경
                    a = par[k][a] ;
            }
        } else if( depth[a] < depth[b] ) {  //  b가 더 아래에 있어서 a 와 depth 맞춰줘야함

            for( int k = KMAX ; k >= 0 ; k-- ) {

                if( a!= b && depth[ par[k][b] ] >= depth[a] )
                    b = par[k][b] ;
            }
        }

        int ans = 0 ;

        for( int k = KMAX ; k >= 0 ; k-- ) {

            if( a != b && par[k][a] != par[k][b] ) {
                a = par[k][a] ;
                b = par[k][b] ;
            }
        }

        if( a == b )    //  a는 b의 조상 or b는 a의 조상
            ans = a ;
        else            //  a or b 의 조상을 답으로 하면 된다.
            ans = par[0][a] ;

        printf("%d\n" , ans ) ;
    }
    return 0 ;
}






