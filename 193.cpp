#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>

int G[101][101];
int V, E;
enum Color {black=true, white=false};
bool os[101];

bool can_color_black(const bool * const S, int v) {	
/*	for (int i=1; i<=V; i++) {
		if (i==v)
			std::cout << ((S[i] == black) ? "[b]" : "[w]") << ' ';
		else
			std::cout << ((S[i] == black) ? "b" : "w") << ' ';
	}
	std::cout << std::endl;*/

	for (int u=1; u<=G[v][0]; u++)
		if (S[G[v][u]] == black)
			return false;

	return true;
}

void color(bool *S, int vertex, int black_nodes, int *max_blacks) {
	// std::cout << "Checking vertex " << vertex << std::endl;
	if (vertex > V) {
		if (black_nodes > *max_blacks) {
			*max_blacks = black_nodes;
			// std::cout << "Found solution " << black_nodes << std::endl;
			std::memcpy(os, S, 101*sizeof(bool));
		}
		
		return;
	}
	
	// Prune the search if we know remaining nodes are not enough to exceed already found maximum
	if (V-vertex+black_nodes+1 < *max_blacks) {
		// std::cout << "Pruning: " << vertex << " : " << V-vertex+1+black_nodes << ", " << *max_blacks << std::endl;
		// std::fflush(stdout);
		return;
	}

	if (can_color_black(S, vertex)) {
		S[vertex] = black;
		color(S, vertex+1, black_nodes+1, max_blacks);
		S[vertex] = white;
	}
		
	color(S, vertex+1, black_nodes, max_blacks);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("193.in", "r", stdin);
    freopen("res.out", "w", stdout);
	#endif

    int T;

    std::cin >> T;
    
	while(T--) {
		std::cin >> V >> E;
		
		std::memset(G, 0, sizeof(G));			
		for (int i=1, u, v; i<=E; i++) {
			std::cin >> u >> v;
			G[u][++G[u][0]] = v;
			G[v][++G[v][0]] = u;
		}

		bool S[101] = {};
		int max_blacks=0;
		color(S, 1, 0, &max_blacks);

		if (max_blacks==0) {
			std::cout << "1" << std::endl << "1" << std::endl;	
		} else {
			std::cout << max_blacks << std::endl;
			for (int i=1, j=0; i<=V; i++) {
				if (os[i]) {
					std::cout << i;
					if (++j < max_blacks)
						std::cout << ' ';
				}
			}
			std::cout << std::endl;
		}	
	}

	return 0;
}