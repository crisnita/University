// DIJKSTRA
/*
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("fisier1.txt");

int main() {
	int n, m, i, j, s, n1, n2, c;
	static int matr[3000][3000], Q[30000], S[30000], dist[30000];
	cout << "Dati nodul sursa: ";
	cin >> s;
	in >> n >> m;

	// initializam matricea cu costurile si vectorul cu distantele
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			matr[i][j] = 0;
	for (i = 0; i <= n; i++)
		dist[i] = 30000;
	dist[s] = 0;

	// citim muchiile
	for (i = 1; i <= m; i++) {
		in >> n1 >> n2 >> c;
		matr[n1][n2] = c;
	}

	// initializam S si Q
	for (i = 0; i < n; i++) {
		S[i] = -1;
		Q[i] = i;
	}
	int len_q = n, poz_s = -1;

	// incepem algoritmul
	while (len_q >= 0) {
		int u = -1, min = 30000;

		// extragem varful
		for (i = 0; i < n; i++) { 
			if (dist[i] < min && Q[i] != -1) {
				min = dist[i];
				u = i;
			}
		}
		if (u == -1) break;
		Q[u] = -1;
		len_q--;

		// bagam varful in S
		S[++poz_s] = u;

		// luam fiecare varf adiacent
		for (i = 0; i < n; i++) {
			if (i != u && matr[u][i] != 0) {
				if (dist[u] + matr[u][i] < dist[i])
					dist[i] = dist[u] + matr[u][i];
			}
		}

	}

	// afisare
	for (i = 0; i < n; i++) {
		if (dist[i] == 30000) cout << i << ": x\n";
		else cout << i << ": " << dist[i] << '\n';
	}

	cout << '\n';
	system("pause");
	return 0;
}*/