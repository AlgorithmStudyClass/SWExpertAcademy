/*
X
2517. 달리기
https://www.acmicpc.net/problem/2517
*/
#include<stdio.h>
#include<iostream>
using namespace std ;

int N ;

struct info {
	int power , idx ;
} ;
info P[500001] , tmp[500001] ;
int A[500001] ;

void mergeSort(int left, int right)
{
    if(right==left)
        return;
    else if(right-left==1)
    {
        if(P[left].power < P[right].power)
        {
            A[P[right].idx]--;
            info p = P[right];
            P[right] = P[left];
            P[left] = p;
        }
    }
    else
    {
        int l = left;
        int mid = (left+right)/2;
        int r = mid+1;
        mergeSort(l,mid);
        mergeSort(r,right);

        for(int i=left;i<=right;i++)
        {
            if(l>mid) 
                tmp[i] = P[r++];
            else if(r>right) 
                tmp[i] = P[l++];
            else if(P[l].power > P[r].power) 
                tmp[i] = P[l++];
            else 
            {
                A[P[r].idx] -= (mid-l+1);
                tmp[i] = P[r++];
            }
        }

        for(int i=left;i<=right;i++) 
            P[i] = tmp[i];
    }
}

int main() {

	scanf("%d" , &N ) ;

	for( int i = 1 ; i <= N ; i++ ) {
		scanf("%d" , &P[i].power ) ;
		P[i].idx = A[i] = i ;
	}
	mergeSort( 1 , N ) ;

    for( int i = 1 ; i <= N ; i++ )
        printf("%d " , P[i].power ) ;
    cout << endl ;

    for( int i = 1 ; i <= N ; i++ )
        printf("%d " , P[i].idx ) ;
    cout << endl ;


	for( int i = 1 ; i <= N ; i++ )
		printf("%d\n" , A[i] ) ;

	return 0 ;
}



// #include<iostream>
// using namespace std ;

// struct Info {

//     int power ;
//     int idx ;
// }

// int N ;
// Info list[500001] ;


// int main() {

//     scanf("%d" , &N ) ;
//     for( int i = 1 ; i <= N ; i++ ) {
//         scanf("%d" , &list[i].power ) ;
//         list[i].idx = i ;
//     }
// }





















