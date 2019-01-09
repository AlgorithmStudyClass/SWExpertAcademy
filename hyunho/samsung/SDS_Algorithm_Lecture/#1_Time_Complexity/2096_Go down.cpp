/*
2096. 내려가기
https://www.acmicpc.net/problem/2096
*/

#include<stdio.h>
using namespace std ;



int main() {


}









#include <stdio.h>
int N;
int DMIN[2][3], DMAX[2][3], A[3];
//  DMIN : 최소값 , DMAX : 최대값 , A : 현재 넣을 데이터

int max(int a,int b){return (a>b?a:b);}
int min(int a,int b){return (a<b?a:b);}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<2;i++) 
        for(int j=0;j<3;j++) 
            DMIN[i][j]=DMAX[i][j]=0;    //  배열 초기화

    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&A[0],&A[1],&A[2]);
        DMIN[i%2][0] = min(DMIN[(i+1)%2][0],DMIN[(i+1)%2][1])+A[0];
        DMIN[i%2][1] = min(DMIN[(i+1)%2][2],min(DMIN[(i+1)%2][0],DMIN[(i+1)%2][1]))+A[1];   //  3개 min max 처리 하는방법은 안에 하나의 더 min max 를 사용하면 된다.
        DMIN[i%2][2] = min(DMIN[(i+1)%2][2],DMIN[(i+1)%2][1])+A[2];

        DMAX[i%2][0] = max(DMAX[(i+1)%2][0],DMAX[(i+1)%2][1])+A[0];
        DMAX[i%2][1] = max(DMAX[(i+1)%2][2],max(DMAX[(i+1)%2][0],DMAX[(i+1)%2][1]))+A[1];
        DMAX[i%2][2] = max(DMAX[(i+1)%2][2],DMAX[(i+1)%2][1])+A[2];
    }

    int maxValue = max( DMAX[ ( N-1 ) % 2 ][0] , max( DMAX[ ( N-1 ) % 2 ][1] , DMAX[ ( N-1 ) % 2 ][1] ) ) ;
    int minValue = min( DMIN[ ( N-1 ) % 2 ][0] , min( DMIN[ ( N-1 ) % 2 ][1] , DMIN[ ( N-1 ) % 2 ][2] ) ) ;

    printf("%d %d", maxValue , minValue );

    return 0 ;
}












