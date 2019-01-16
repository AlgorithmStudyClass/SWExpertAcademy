/*
1722. 순열의 순서
https://www.acmicpc.net/problem/1722

dp
*/

#include<iostream>
#include<vector>
using namespace std ;

int N , K , quizNum ;
int arr[21] ;
int visit[21] ;
vector<string> ans ;
int result[21] ;

int resultCnt ;

void back( int cnt ) {

	if( cnt == N - 1 ) {
		resultCnt += 1 ;

		if( resultCnt == K ) {

			for( int i = 0 ; i < N ; i++ )
				cout << result[i] << " " ;
			cout << endl ;
		}
	}
	else {

		for( int i = 0 ; i < N ; i++ ) {

			if( visit[i] == 0 ) {
				visit[i] = 1 ;
				result[i] = arr[i] ;
				back( cnt + 1  ) ;
				visit[i] = 0 ;
			}
		}
	}
}

void back( int i , int cnt ) {

	if( cnt)
}

int main() {

	scanf("%d" , &N ) ;
	scanf("%d" , &quizNum ) ;

	if( quizNum == 1 ) {

		scanf("%d" , &K ) ;
		for( int i = 0 ; i < N ; i++ ) {
			arr[i] = i + 1 ;
			visit[i] = 0 ;
		}

		back( 0 ) ;

	} else {

		for( int i = 0 ; i < N ; i++ ) {
			scanf("%d" , &arr[i] ) ;
			visit[i] = 0 ;
		}



	}

	return 0 ;
}







