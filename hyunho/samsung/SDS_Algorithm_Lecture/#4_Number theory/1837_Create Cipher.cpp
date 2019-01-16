/*
1837. 암호 생성
https://www.acmicpc.net/problem/1837

에라토스테네스의 체를 이용한 문제
*/

#include<iostream>
#include<cstring>
using namespace std ;

char P[101] ;
int K ;
int isPrime[10000001] ;
int prime[10000001] ;

int div(int num)
{
    int d = 0, len = strlen(P);
    for(int i = 0 ; i < len ; i++) 
    {
        d = d*10+P[i]-'0'; // 큰 수에서 한자리씩 가져오기 
        if(d >= num)
        {
            d %= num;
        }
    }
    return d==0;
}

int main() {

	scanf("%s" , P ) ;
	scanf("%d" , &K ) ;

	for( int i = 2 ; i <= K ; i++ )
		isPrime[i] = 1 ;

	int index = 0 ;
	for( int i = 2 ; i < K ; i++ ) {			//	소수를 적어서 가지고 있으려면 N 번 다 돌려야함

		if( isPrime[i] ) {
			prime[index++] = i ;
			for( int j = i ; j < K / i ; j++ )
				isPrime[i*j] = 0 ;
		}
	}

	int ans = 0 ;
	for( int i = 0 ; i < index ; i++ ) {

		if( div( prime[i] ) ) {
			ans = prime[i] ; break ;
		}
	}

	if( ans > 0 )
		printf("BAD %d\n" , ans ) ;
	else
		printf("GOOD\n" ) ;

	return 0 ;
}







