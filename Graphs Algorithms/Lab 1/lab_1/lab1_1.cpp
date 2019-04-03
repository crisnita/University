/*#include <fstream>
#include <iostream>

using namespace std;

ifstream in("fisier.txt");

int main()
{
	int n, muchie = 0, i, j, a, b, matrAd[250][250], matrIn[250][250];
	in >> n;

	// initializam matricele cu 0
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			matrAd[i][j] = 0;
			matrIn[i][j] = 0;
		}
	}

	// construim matrAd si matrIn, in timp ce citim muchiile
	while (in >> a >> b) {
		muchie++;
		matrIn[a][muchie] = 1;
		matrIn[b][muchie] = 1;

		matrAd[a][b] = 1;
		matrAd[b][a] = 1;
	}


	// afiseaza matrAd
	cout << "Matricea de adiacenta este:\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << matrAd[i][j] << " ";
		}
		cout << '\n';
	}


	// afiseaza matrIn
	cout << "Matricea de incidenta este:\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= muchie; j++) {
			cout << matrIn[i][j] << " ";
		}
		cout << '\n';
	}


	int poz = 0;

	// facem trecerea din matricea de adiacenta in cea de incidenta. Intai o facem pe cea de incidenta 0

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			matrIn[i][j] = 0;
		}
	}



	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (matrAd[i][j] == 1) {
				poz++;
				matrIn[i][poz] = 1;
				matrIn[j][poz] = 1;
			}
		}
	}

	cout << "Matricea de incidenta dupa transformare este:\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= poz; j++) {
			cout << matrIn[i][j] << " ";
		}
		cout << '\n';
	}


	// facem trecerea din matricea de incidenta in cea de adiacenta

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			matrAd[i][j] = 0;
		}
	}

	for (j = 1; j <= poz; j++) {
		a = 0;
		b = 0;
		for (i = 1; i <= n; i++) {
			if (matrIn[i][j] == 1) {
				if (a == 0) a = i;
				else b = i;
			}
		}
		matrAd[a][b] = 1;
		matrAd[b][a] = 1;
	}

	// afiseaza matrAd
	cout << "Matricea de adiacenta dupa transformare este:\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << matrAd[i][j] << " ";
		}
		cout << '\n';
	}

	system("pause");
	return 0;
}
*/