#include <iostream>
#include <vector>

using namespace std;
using Graph =std::vector<std::vector<int>>;
std::vector<bool> seen;
std::vector<bool> finished;

bool is_ok = true;

int dfs(const Graph &G, int v, int p) {
	seen[v] = true;
	if (2 < G[v].size()) {
		is_ok = false;
		return 0;
	}
    for (auto next_v : G[v]) { 
		if (next_v == p) {
			continue;
		}
		if (seen[next_v]) {
			if (!finished[next_v]) {
				is_ok = false;
			}
			continue;
		}
		dfs(G, next_v, v);
	}
	finished[v] = true;
	return 0;
}

int main() {
    int N, M; 
	cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
		--a;
		--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

	seen.assign(N, false);
	finished.assign(N, false);
	for (int i = 0; i < N; ++i) {
		if (seen[i]) continue;
		dfs(G, i, -1);
		if (!is_ok) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;
}