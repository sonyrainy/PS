#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int x)
{
    // 방문한 경우, visited 배열의 항을 true로 변환
    visited[x] = true;

    // 인접한 노드의 사이즈만큼 탐색
    // 하지만 dfs의 원래 구조인 stack의 특징(LIFO)을
    // 생각하여 graph[x]의 뒤에서부터 탐색해보았다.
    for (int i = graph[x].size()-1; i >=0; i--) 
    {
        int y = graph[x][i];

        // 방문하지 않았던 경우라면, 아래 코드 실행
        if (!visited[y]) 
            dfs(y);
    }
}

int main(void)
{
    int u, v, N, M;
    int count = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            count++;
            dfs(i);
        }
    }
    cout << count << "\n";

}