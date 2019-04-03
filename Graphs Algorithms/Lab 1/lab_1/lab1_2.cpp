#include <iostream>
#include <fstream>

using namespace std;

ifstream in("fisier.txt");

int main() {
	int matr[250][250], i, j, grad, n, a, b, vectGrad[250];

	in >> n;


	// initializam matricea cu 0
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			matr[i][j] = 0;
	}

	// citim muchiile si le trecem in matricea de adiacenta
	while (in >> a >> b) {
		matr[a][b] = 1;
		matr[b][a] = 1;
	}

	int gasit = 0;

	for (i = 1; i <= n; i++) {
		grad = 0;
		for (j = 1; j <= n; j++) {
			if (matr[i][j] == 1) {
				grad++;
			}
		}

		if (grad == 0) {
			if (gasit == 0) {
				gasit = 1;
				cout << "Nodurile izolate: ";
			}
			cout << i << " ";

		}
	}
	if (gasit == 0) cout << "Nu avem noduri izolate!";

	cout << '\n';


	// acum verificam daca graful este regular
	int regular = 1;

	for (i = 1; i <= n; i++) {
		grad = 0;
		for (j = 1; j <= n; j++) {
			if (matr[i][j] == 1) { grad++; }
		}
		vectGrad[i] = grad;
	}
	for (i = 2; i <= n; i++) {
		if (vectGrad[i] != vectGrad[i - 1]) regular = 0;
	}

	if (regular == 1) cout << "Graful este regular";
	else cout << "Graful nu este regular\n";
	

	// facem matricea distantelor

	int matr_aux[250][250];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) matr_aux[i][j] = 0;
	cout << "Matricea distantelor este:\n";
	
	for (int start = 1; start <= n; start++) {
		int marcat[250], q[250][2];
		for (i = 1; i <= n; i++) {
			marcat[i] = 0;
			q[i][1] = 0;
			q[i][2] = 0;
		}
		q[1][1] = start;
		q[1][2] = 0;
		int p1 = 1, p2 = 1;
		marcat[start] = 1;

		while (p2 <=n && p1 <= p2) { // parcurgem coada
			int nod_tata = q[p1][1], nivel_tata = q[p2][2];
			for (i = 1; i <= n; i++) {
				if (matr[nod_tata][i] == 1 && marcat[i] == 0) {
					marcat[i] = 1;
					p2++;
					q[p2][1] = i;
					q[p2][2] = nivel_tata + 1;
				}
			}
			p1++;
		}
		for (i = 1; i <= n; i++) {
			matr_aux[start][q[i][1]] = q[i][2];
		}
		for (i = 1; i <= n; i++) cout << matr_aux[start][i] << " ";
		cout << "\n";
	}
	cout << "\n";

	// graf conex

	int marcat[250], q[250][2];
	for (i = 1; i <= n; i++) {
		marcat[i] = 0;
	}
	q[1][1] = 1;
	q[1][2] = 0;
	int p1 = 1, p2 = 1;
	marcat[1] = 1;

	while (p2 <= n && p1 <= p2) { // parcurgem coada
		int nod_tata = q[p1][1], nivel_tata = q[p2][2];
		for (i = 1; i <= n; i++) {
			if (matr[nod_tata][i] == 1 && marcat[i] == 0) {
				marcat[i] = 1;
				p2++;
				q[p2][1] = i;
				q[p2][2] = nivel_tata + 1;
			}
		}
		p1++;
	}
	int ok = 1;
	for (i = 1; i <=n; i++){
		if (marcat[i] == 0) ok = 0;
	}
	if (ok == 1) cout << "Graful este conex!";
	else cout << "Graful nu este conex!";

	cout << "\n";
	system("pause");
	return 0;
}