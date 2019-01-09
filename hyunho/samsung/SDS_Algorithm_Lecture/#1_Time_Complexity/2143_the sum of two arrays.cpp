/*
2143. 두 배열의 합
https://www.acmicpc.net/problem/2143
*/

// #include<stdio.h>
// using namespace std ;



// int main() {


// }



/*

부분배열을 sort 오름차순으로 2개를 만든다
A = 1 3 5 7 9 10 11
B = 2 4 5 8 9

일일이 더해서 T 가 되는걸 확인한다면 n2 이므로 너무 오래걸린다.
그래서 A 에서 가장 작은 1 + B에서 가장 큰 9 를 했을 때
T < 합 이라면 더 가보고
T > 합 이라면 만들 수 없으므로 다음으로 넘어간다.

*/



#include <stdio.h>
#include<iostream>
#include <algorithm> 
using namespace std;
int T,n,m;
int N[1000],M[1000];    
int A[1000000],B[1000000],acnt,bcnt;
int ACNT[1000000],BCNT[1000000];

int main()
{
    acnt=bcnt=0;
    scanf("%d",&T);     //  만들값
    scanf("%d",&n);         //  첫번째 개수      N 배열에 저장
    for(int i=0,sum;i<n;i++)
    {
        scanf("%d",N+i);
        A[acnt++] = sum = N[i];
        for(int j=i-1;j>=0;j--) 
            A[acnt++] = sum += N[j];
    }


    scanf("%d",&m);             //  두번째 개수      M 배열에 저장
    for(int i=0,sum;i<m;i++)
    {
        scanf("%d",M+i);
        B[bcnt++] = sum = M[i];
        for(int j=i-1;j>=0;j--) B[bcnt++] = sum += M[j];
    }
    sort(A,A+acnt);
    sort(B,B+bcnt);

    for( int i = 0 ; i < acnt ; i++ )
        cout << A[i] << " " ;
    cout << endl ;

    for( int i = 0 ; i < bcnt ; i++ )
        cout << B[i] << " " ;
    cout << endl ;


    ACNT[0]=1;
    int e=acnt;
    acnt=0;
    for(int i=1;i<e;i++)
    {
        if(A[acnt] == A[i]) ACNT[acnt]++;
        else 
        {
            A[++acnt] = A[i];
            ACNT[acnt] = 1;
        }
    }
    BCNT[0]=1;
    e=bcnt;
    bcnt=0;
    for(int i=1;i<e;i++)
    {
        if(B[bcnt] == B[i]) BCNT[bcnt]++;
        else 
        {
            B[++bcnt] = B[i];
            BCNT[bcnt] = 1;
        }
    }

    cout << endl << "here" << endl ;
    for( int i = 0 ; i < acnt + 1 ; i++ )
        cout << A[i] << " " ;
    cout << endl ;

    cout << "a" << endl ;
    for( int i = 0 ; i < acnt + 1 ; i++ )
        cout << ACNT[i] << " " ;
    cout << endl << endl ;

    for( int i = 0 ; i < bcnt + 1 ; i++ )
        cout << B[i] << " " ;
    cout << endl ;

    cout << "b" << endl ;
    for( int i = 0 ; i < bcnt + 1 ; i++ )
        cout << BCNT[i] << " " ;
    cout << endl ;

    long long ans=0;
    int bidx = bcnt;
    for(int aidx=0;aidx<=acnt && bidx >= 0;aidx++)
    {
        int num = A[aidx]+B[bidx];
        if(num<T) continue;
        if(num > T)
        {
            while(bidx>0 && num > T) num = A[aidx]+B[--bidx];
        }
        if(num == T) ans += (long long)ACNT[aidx]*BCNT[bidx];
    }
    printf("%lld",ans);
}






