/*
5639. 이진 검색 트리
https://www.acmicpc.net/problem/5639
*/

#include<iostream>
using namespace std ;

struct Node {

	int val , left , right ;

	void setNode( int val , int left , int right ) {
		this->val = val ;
		this->left = left ;
		this->right = right ;
	}
} ;

Node list[10001] ;

void dfs( int node ) {

	if( list[node].left != -1 )
		dfs( list[node].left ) ;

	if( list[node].right != -1 )
		dfs( list[node].right ) ;

	printf("%d\n" , list[node].val ) ;
}

int main() {

	int num ;
	int nodeIdx = 0 ;
	while( scanf("%d" , &num ) != EOF ) {

		list[nodeIdx].setNode( num , -1 , -1 ) ;

		if( nodeIdx > 0 ) {

			int curIdx = 0 ;
			while( true ) {

				if( list[nodeIdx].val < list[curIdx].val ) {	//	왼쪽으로

					if( list[curIdx].left == -1 ) {	//	왼쪽 비었음
						list[curIdx].left = nodeIdx ; break ;
					} else
						curIdx = list[curIdx].left ;
				} else if( list[curIdx].val < list[nodeIdx].val ) {	//	오른쪽으로

					if( list[curIdx].right == -1 ) {	//	오른쪽 비었으
						list[curIdx].right = nodeIdx ; break ;
					} else
						curIdx = list[curIdx].right ;
				}
			}
		}
		nodeIdx++ ;
	}

	dfs(0) ;
	return 0 ;
}














