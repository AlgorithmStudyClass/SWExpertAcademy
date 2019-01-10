/*
2042. 구간의 합 구하기
https://www.acmicpc.net/problem/2042
*/

#include<iostream>
using namespace std ;

int N , M , K ;
int arr[1000000] ;
int a , b , c ;
int result ;


int main() {

    scanf("%d %d %d" , &N , &M , &K ) ;

    for( int i = 0; i < N ; i++ )
        scanf("%d" , &arr[i] ) ;

    int *indexTree = new int[ N * 4  + 1 ] ;

    for( int i = 0 ; i < N * 4 + 1 ; i++ )
        indexTree[i] = 0 ;

    for( int i = 8 ; i < 13 ; i++ ) {
        indexTree[i] = arr[i-8] ;

        if( i % 2 == 1 )
            indexTree[ i / 2 ] = indexTree[ i - 1 ] + indexTree[ i ] ;
    }



    for( int i = 0 ; i < M + K ; i++ ) {

        result = 0 ;
        
        scanf("%d %d %d" , &a , &b , &c ) ;

        if( a == 1 ) {

        } else {

            int s = b + 7 ; 
            int e = c + 7 ;

            while( s <= e ) {

                if( s % 2 == 1 )
                    result += indexTree[s] ;

                if( e % 2 == 0 )
                    result += indexTree[e] ;

                s = ( s + 1 ) / 2 ;
                e = ( e - 1 ) / 2 ;
            }

            printf("%d\n" , result ) ;
        }
    }
    return 0 ;
}




#include <cstdio>

typedef long long int lld;

int N,M,K;

//100만보다 큰 2의 제곱수 : 1048576 -> 최대 약 210만개의 배열이 필요, 대략 데이터의 4배정도면 충분
lld tree[1000000*4];

int init() // 트리 초기 
{
    for(int i = 0 ; i < 4*N ; i++) tree[i] = 0;
    // 처음으로 n보다 큰 2의 제곱수 구하기
    int ret = 1;
    while(ret < N ) ret *= 2;
    ret--;// 1 base 입력처리를 위해 1을 미리 빼주기
    return ret;
}

// 갱신 함수
void update(int node, lld delta)
{
    int cur = node;
    while(cur > 0)
    {
        tree[cur] += delta; // 트리의 데이터를 갱신
        cur /= 2; // 부모 노드로 이동
    }

}

// 구간 쿼리 함수
lld sum(int start, int end)
{
    lld ret = 0;
    while(start <= end)
    {
        if(start%2 == 1) ret += tree[start];
        if(end%2 == 0) ret += tree[end];
        start = (start+1)/2;
        end = (end-1)/2;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);

    // 트리 초기화 및 데이터의 첫 인덱스 구하기
    int Nidx = init();

    for(int i = 1 ; i <= N ; i++) 
    {
        // 인덱스 트리의 리프 노드에 데이터 입력
        scanf("%lld",&tree[Nidx+i]);
    }

    // 트리 구성 하기
    for(int i = Nidx ; i >= 0 ; i--) tree[i] = tree[i*2] + tree[i*2+1];
    for(int i = 0 ; i < M+K ; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1)
        {
            // 데이터 갱신 하기
            update(Nidx+b,(lld)c-tree[Nidx+b]);
        }
        else
        {
            // 구간의 합 구하기
            printf("%lld\n",sum(Nidx+b,Nidx+c));
        }
    }
}






