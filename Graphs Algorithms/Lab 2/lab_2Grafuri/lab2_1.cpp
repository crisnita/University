/*#include <iostream>
#include <fstream>

using namespace std;

ifstream in("file1.txt");

int main() {
	int matr[250][250], i, j, n, a, b;

	// citim matricea
	in >> n; 
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			matr[i][j] = 0;

	while (in >> a >> b) {
		matr[a][b] = 1;
	}

	// citim nodul de la care pornim
	cout << "Dati nodul de start: ";
	int start, final;
	cin >> start;
	cout << "Dati nodul final: ";
	cin >> final;

	// initializam cu 0 toate listele
	int p[250], q[250], l[250], p1 = 1, p2 = 1;
	for (i = 1; i <= n; i++) { 
		p[i] = 0;
		q[i] = 0;
		l[i] = 0;
	}

	// initializam lungimea din fiecare varf
	l[start] = 0; 
	for (i = 1; i <= n; i++)
		if (i != start)
			l[i] = -1;

	// incepem parcurgerea
	q[1] = start;
	while (p1 <= p2) {
		int x = q[p1++]; // x este nodul curent din coada
		// cautam toti vecinii lui x
		for (i = 1; i <= n; i++) // i este vecinul curent al lui x
			if (matr[x][i] == 1 && l[i] == -1) {
				l[i] = l[x] + 1;
				p[i] = x;
				q[++p2] = i;
			}
	}

	
	cout << "Cel mai scurt lant de la nodul " << final << " la nodul " << start << " este: " << final;
	int v = final, k, u;
	k = l[v];
	u = v;

	while (k) {
		u = p[u];
		cout << " " << u;
		k--;
	}


	cout << "\n";
	system("pause");
	return 0;
}
*/