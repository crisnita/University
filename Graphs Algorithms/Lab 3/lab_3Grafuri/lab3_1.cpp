// BELLMAN FORD


#include <iostream>
#include <fstream>

using namespace std;

ifstream in("fisier1.txt");

int main() {
	int n, m, i, j, m1, m2, c, s, noduri[30000];
	static int matr[3000][3000];
	

	cout << "Dati nodul de start: ";
	cin >> s;
	in >> n >> m;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			matr[i][j] = 0;
	for (i = 1; i <= m; i++) { // citim matricea
		in >> m1 >> m2 >> c;
		matr[m1][m2] = c;
	}

	// initializam toate nudurile cu infinit (30000), in afara de s
	for (i = 0; i < n; i++)
		noduri[i] = 30000;
	noduri[s] = 0;

	for (int iteratie = 1; iteratie < n; iteratie++) { // facem n-1 iteratii
		for (int nod = 0; nod < n; nod++) { // luam fiecare nod care nu este infinit
			if (noduri[nod] != 30000) {
				for (int vecin = 0; vecin < n; vecin++) { // luam toti vecinii
					if (vecin != nod && matr[nod][vecin] != 0) {
						if (matr[nod][vecin] + noduri[nod] < noduri[vecin]) { // conditia ca sa facem update la nod
							noduri[vecin] = matr[nod][vecin] + noduri[nod];
						}
					}
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (noduri[i] == 30000) cout << i << ": x\n";
		else cout << i << ": " << noduri[i] << '\n';
	}

	cout << '\n';
	system("pause");
	return 0;
}