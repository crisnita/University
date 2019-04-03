#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ifstream in("file3.txt");

int main() {
	// marcam matricea
	int matr[150][150], i, j, q[10000][2];
	char final[150][150];
	for (i = 0; i <= 100; i++)
		for (j = 0; j <= 100; j++) {
			matr[i][j] = 0;
		}

	// incepem citirea
	char c;
	int lin = 0, col = 0, start_x = 0, start_y = 0, fin_x = 0, fin_y = 0;
	
	string str;
	while (getline(in, str)) {
		lin++;
		col = 0;
		for (i = 0; i <= str.size(); i++) {
			if (str[i] == '1') {
				matr[lin][++col] = -1;
			}
			else if (str[i] == ' ') {
				matr[lin][++col] = 0;
			}
			else if (str[i] == 'S') {
				matr[lin][++col] = 1;
				start_x = lin;
				start_y = col;
			}
			else if (str[i] == 'F') {
				matr[lin][++col] = 0;
				fin_x = lin;
				fin_y = col;
			}
		}
	}

	for (i = 0; i <= lin + 1; i++) {
		matr[i][0] = -1;
		matr[i][col + 1] = -1;
	}

	for (i = 0; i <= col + 1; i++) {
		matr[0][i] = -1;
		matr[lin + 1][i] = -1;
	}

	q[1][1] = start_x;
	q[1][2] = start_y;
	int p1 = 1, p2 = 1;
	int gasit = 0;
	while (p1 <= p2) {
		int x, y;
		x = q[p1][1];
		y = q[p1][2];
		if (matr[x + 1][y] == 0) {
			matr[x + 1][y] = matr[x][y] + 1;
			q[++p2][1] = x + 1;
			q[p2][2] = y;
		}
		if (matr[x - 1][y] == 0) {
			matr[x - 1][y] = matr[x][y] + 1;
			q[++p2][1] = x - 1;
			q[p2][2] = y;
		}
		if (matr[x][y + 1] == 0) {
			matr[x][y + 1] = matr[x][y] + 1;
			q[++p2][1] = x;
			q[p2][2] = y + 1;
		}
		if (matr[x][y - 1] == 0) {
			matr[x][y - 1] = matr[x][y] + 1;
			q[++p2][1] = x;
			q[p2][2] = y - 1;
		}
		if (x == fin_x && y == fin_y) {
			gasit = 1;
			break;
		}
		if (gasit == 1) break;
		p1++;
	}

	for (i = 1; i <= lin; i++) {
		for (j = 1; j <= col; j++) {
			final[i][j] = ' ';
		}
	}

	int val_cur = matr[fin_x][fin_y];

	while (1) {
		final[fin_x][fin_y] = '0';
		if (matr[fin_x + 1][fin_y] == val_cur - 1) {
			fin_x++;
			val_cur--;
		}
		else if (matr[fin_x - 1][fin_y] == val_cur - 1) {
			fin_x--;
			val_cur--;
		}
		else if (matr[fin_x][fin_y + 1] == val_cur - 1) {
			fin_y++;
			val_cur--;
		}
		else if (matr[fin_x][fin_y - 1] == val_cur - 1) {
			fin_y--;
			val_cur--;
		}
		if (val_cur == 1) {
			matr[fin_x][fin_y] = 1;
			break;
		}
	}
	


	// afiseaza matricea
	for (i = 1; i <= lin; i++) {
		for (j = 1; j <= col; j++)
			cout << final[i][j] << " ";
		cout << "\n";
	}


	system("pause");
	return 0;
}