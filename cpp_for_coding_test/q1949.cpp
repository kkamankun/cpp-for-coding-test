#include<iostream>
#include<vector>
#define MAXN 8
using namespace std;
int N, K;
int graph[MAXN][MAXN];
bool visited[MAXN][MAXN];

// 위, 아래, 왼쪽, 오른쪽
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int answer;

typedef struct info {
	int x, y;
	int height;
	int usedk;
	int len;
};

void dfs(info cur) {
	answer = answer < cur.len ? cur.len : answer;
	for (int i = 0; i < 4; i++) {
		info nxt = cur;
		nxt.x += dx[i];
		nxt.y += dy[i];
		nxt.height = graph[nxt.x][nxt.y];
		if (nxt.x < 0 || nxt.x >= N || nxt.y < 0 || nxt.y >= N) continue;
		if (visited[nxt.x][nxt.y]) continue;
		if (nxt.height < cur.height) {
			nxt.len += 1;
			visited[nxt.x][nxt.y] = true;
			dfs(nxt);
			visited[nxt.x][nxt.y] = false;
		}
		else if (nxt.height - K < cur.height && !cur.usedk) {
			nxt.height = cur.height - 1;
			nxt.len += 1;
			nxt.usedk = 1;
			visited[nxt.x][nxt.y] = true;
			dfs(nxt);
			visited[nxt.x][nxt.y] = false;
		}
		else;
	}
	return;
}


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 0;

		int max_value = 0;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &graph[i][j]);
				if (max_value < graph[i][j]) max_value = graph[i][j];
			}
		}
	
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (max_value == graph[i][j]) {
					info cur = { i, j, graph[i][j], 0, 1 };
					visited[i][j] = true;
					dfs(cur);
					visited[i][j] = false;
				}
			}
			

		printf("#%d %d", test_case, answer);
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}