#include<iostream>
#include<queue>
using namespace std ;

int main() {

	priority_queue< int, vector<int>, less<int> > pq;	//	maxHeap
	priority_queue< int, vector<int>, greater<int> > pq;	//	minHeap

	for( int i = 1 ; i <= 100 ; i++ )
		pq.push( i ) ;

	cout << "pq.top() : " << pq.top() << endl ;

	pq.push( 200 ) ;
	cout << "pq.top() : " << pq.top() << endl ;
	pq.pop() ;

	cout << "pq.size() : " << pq.size() << endl ;
	cout << "pq.empty() : " << pq.empty() << endl ;
	return 0 ;
}