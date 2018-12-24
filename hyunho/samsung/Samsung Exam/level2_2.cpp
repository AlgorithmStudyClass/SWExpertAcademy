#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;
int V, E;

typedef struct NODE {
   int end;
   int val;
};

vector<NODE> EDGE_arr[MAX_E];
int dist[MAX_V] = { 0 };

void dijkstra(int S) {
   priority_queue< pair<int, int> > pq;
   pq.push({ 0, S });
   while (!pq.empty()) {
      int now_node = pq.top().second;
      int cost = -1 * pq.top().first;
      pq.pop();
      for (int k = 0; k < EDGE_arr[now_node].size(); k++) {
         int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
         int before_val = dist[EDGE_arr[now_node][k].end];
         if (new_val < before_val) {
            dist[EDGE_arr[now_node][k].end] = new_val;
            pq.push({ -1 * new_val, EDGE_arr[now_node][k].end });
         }
      }
   }
}

int main() {
   int t, K, line = 1, S, cnt;
   scanf("%d", &t);
   while (t > 0) {
      scanf("%d %d %d %d", &V, &E, &K, &S);
      int B[12];
      B[0] = S;
      B[K + 1] = S;
      for (int i = 1; i <= K; i++)
         scanf("%d", &B[i]);
      int from, to, val;
      // 간선 연결 
      for (int i = 0; i < E; i++) {
         scanf("%d %d", &from, &to);
         EDGE_arr[from].push_back(NODE{ to, 1 });
         EDGE_arr[to].push_back(NODE{ from, 1 });
      }

      cnt = 0;

      for (int j = 0; j < K + 1; j++) {
         for (int i = 1; i <= V; i++) {
            dist[i] = INF;
         }

         dist[B[j]] = 0;
         dijkstra(B[j]);
         cnt += dist[B[j + 1]];
      }
      printf("#%d %d\n", line++, cnt);
      for (int i = 0; i < E; i++) {
         EDGE_arr[i].clear();
      }
      EDGE_arr->clear();
      t--;
   }
   return 0;
}