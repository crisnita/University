/*#include <iostream>
#include <fstream>

using namespace std;

ifstream in("file2.txt");

int main() {
	// construim matricea de adiacenta
	int matr[250][250], inchidere[250][250], i, j, n, a, b;
	in >> n;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			matr[i][j] = 0;
			inchidere[i][j] = 0;
		}
	
	while (in >> a >> b) 
		matr[a][b] = 1;
	
	// incepem parcurgerea
	for (int v = 1; v <= n; v++) {

		int q[250], marcat[250], p1 = 1, p2 = 1;
		for (i = 1; i <= n; i++)
		{
			marcat[i] = 0;
			q[i] = 0;
		}
		q[1] = v;
		// marcat[v] = 1;
		while (p1 <= p2) {
			for (i = 1; i <= n; i++) {
				if (matr[q[p1]][i] == 1 && marcat[i] == 0) {
					marcat[i] = 1;
					inchidere[v][i] = 1;
					q[++p2] = i;
				}
			}
			p1++;
		}
	}

	// afisam matricea
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << inchidere[i][j] << " ";
		cout << '\n';
	}
	
	

	cout << '\n';
	system("pause");
	return 0;
}*/