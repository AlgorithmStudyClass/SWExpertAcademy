#include <iostream>
#include <vector>
#include <queue>

#define INF 1001
#define MAX_V 1001
#define MAX_E 3001

using namespace std;

typedef struct node {
	int end;
	int val;
}node;

vector<node> edge_arr[MAX_E];
int dist[MAX_V];
int V, E;

void dijkstra(int S) {
	priority_queue< pair<int, int> > pq;
	pq.push({ 0, S });

	while (!pq.empty()) {
		int cost = -1 * pq.top().first;
		int now_node = pq.top().second;
		pq.pop();

		for (int k = 0; k < edge_arr[now_node].size(); k++) {
			node now_to_k = edge_arr[now_node][k];
			int before_val = dist[now_to_k.end];
			int new_val = dist[now_node] + 1;
		
			if (new_val < before_val) {
				dist[now_to_k.end] = new_val;
				pq.push({ -1 * new_val, now_to_k.end });
			}
		}
	}
}

void dist_init(int V) {
	for (int l = 1; l <= V; l++)
		dist[l] = INF;
}
int main() {
	int t, line = 1,K,S,min;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d %d %d %d", &V, &E, &K, &S);

		int b[12],from,to;
		b[0] = S;
		b[K + 1] = S;

		for (int i = 1; i <= K; i++)
			scanf("%d", &b[i]);
		
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &from, &to);
			edge_arr[from].push_back({ to, 1 });
			edge_arr[to].push_back({ from, 1 });
		}

		min = 0;

		int qq[12][12];

		for (int i = 1; i <= V; i++)
			dist[i] = INF;
		dist[S] = 0;
		dijkstra(S);

		for (int i = 1; i <= V; i++) {
			qq[1][i] = dist[i];
			qq[i][0] = qq[i][V + 1] = 0;
		}

		for (int i = 2; i <=K; i++) {
			for (int j = 1; j <= K; j++) {
				int c[12],go_min=INF;
				memcpy(c, dist, 12 * 4);
				dist_init(V);
				dist[b[j]] = 0;
				dijkstra(b[j]);
				for (int a = 1; a <= V; a++){
					if (b[a] != b[j]) {
						int temp = dist[b[a]] + qq[i-1][b[j]];
						if (temp < go_min)
							go_min = temp;
					}
				}
				qq[i][b[j]] = go_min;
			}
		}
		

		//계산
		//for (int i = 0; i < K + 1; i++) {
		//	for (int j = 1; j <= V; j++) 
		//		dist[j] = INF;
		//	dist[b[i]] = 0;

		//	dijkstra(b[i]);
		//	cnt += dist[b[i + 1]];
		//	
		//	//// 값을 출력한다. 
		//	printf("%d->%d //", b[i],b[i+1]);
		//	for (int i = 1; i <= V; i++) 
		//		printf("%d ", dist[i]);
		//	
		//	printf("min : %d", min);
		//	printf("\n");
		//}


		//출력
		printf("#%d %d\n", line++,min);
		for (int i = 0; i < E; i++) {
			edge_arr[i].clear();
		}
		edge_arr->clear();
		t--;
	}
	return 0;
}

// 1-1 Math problem
// 1-2 Math problem
// 2-1 DP : multiple knapsack
// 2-2 Graph : some vertices shortest path
// 2-3 Math problem
// 2-4 tetris