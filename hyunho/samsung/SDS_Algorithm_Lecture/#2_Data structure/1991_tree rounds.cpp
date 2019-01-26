/*
1991. 트리 순회
https://www.acmicpc.net/problem/1991
*/

// #include<iostream>
// using namespace std ;

// struct Node // 노드 구조체 
// {
//     int val, parent, right, left;
// };

// int N;
// struct Node A[26];
// char str[10];

// void preOrder(int node)
// {   
//     printf("%c",A[node].val);
//     if(A[node].left > -1) preOrder(A[node].left);
//     if(A[node].right > -1) preOrder(A[node].right);
// }
// void inOrder(int node)
// {   
//     if(A[node].left > -1) inOrder(A[node].left);
//     printf("%c",A[node].val);
//     if(A[node].right > -1) inOrder(A[node].right);
// }
// void postOrder(int node)
// {   
//     if(A[node].left > -1) postOrder(A[node].left);
//     if(A[node].right > -1) postOrder(A[node].right);
//     printf("%c",A[node].val);
// }


// int main() {

//     scanf("%d ",&N);

//     for(int i=0;i<26;i++) {
//         A[i].val = i+'A';
//         A[i].parent = A[i].right = A[i].left = -1;
//     }

//     for(int i=0;i<N;i++) {

//         char n, l, r;
//         fgets(str,sizeof(str),stdin);
//         n=str[0];
//         l=str[2];
//         r=str[4];

//         if(l!='.') {
//             A[n-'A'].left = l-'A';
//             A[l-'A'].parent = n-'A';
//         }
//         if(r!='.') {
//             A[n-'A'].right = r-'A';
//             A[r-'A'].parent = n-'A';
//         }
//     }

//     preOrder(0);printf("\n");
//     inOrder(0);printf("\n");
//     postOrder(0);printf("\n");

//     return 0 ;
// }


#include<iostream>
using namespace std ;

struct Node {
    int parent , val , left , right ;

    Node() {
        parent = -1 ;
        val = -1 ;
        left = -1 ;
        right = -1 ;
    }
} ;

int N ;
Node list[27] ;
char str[10] ;

void preOrder( int node ) {

    printf("%c" , list[node].val ) ;
    if( list[node].left != -1 )
        preOrder( list[node].left ) ;

    if( list[node].right != -1 )
        preOrder( list[node].right ) ;
}

int main() {

    scanf("%d " , &N ) ;

    for( int i = 0 ; i < N ; i++ ) {

        char p , l , r ;
        fgets( str , sizeof( str ) , stdin ) ;
        p = str[0] ;
        l = str[2] ;
        r = str[4] ;

        list[p-'A'].val = p ;

        if( l != '.' ) {
            list[p-'A'].left = l-'A' ;
            list[l-'A'].parent = p-'A' ;
        }

        if( r != '.' ) {
            list[p-'A'].right = r-'A' ;
            list[r-'A'].parent = p-'A' ;
        }

    }

    preOrder( 0 ) ;
    printf("\n") ;


    return 0 ;
}
































