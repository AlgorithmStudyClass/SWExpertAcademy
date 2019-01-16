/*
5568. 카드 내려놓기
https://www.acmicpc.net/problem/5568

백트래킹
*/

#include<iostream>
#include<set>
using namespace std ;

int N , K ;
string card[11] ;
int visit[11] ;
set<string> ans ;


void back( int cnt , string str ) {

	if( cnt == K )
		ans.insert( str ) ;
	else {

		for( int i = 0 ; i < N ; i++ ) {

			if( visit[i] == 0 ) {
				visit[i] = 1 ;
				back( cnt + 1 , str + card[i] ) ;
				visit[i] = 0 ;
			}
		}
	}
}

int main() {

	scanf("%d %d" , &N , &K ) ;

	for( int i = 0 ; i < N ; i++ ) {
		cin >> card[i] ;
		visit[i] = 0 ;
	}

	back( 0 , "" ) ;

	printf("%lu\n" , ans.size() ) ;
	ans.clear() ;
	return 0 ;
}









