#include<iostream>
using namespace std;

int num[9][9];
bool sign = false;

void input();
void output();
bool check(int n, int key);
void dfs(int n);

int main() {
	cout << "input:" << endl;
	input();
	dfs(0);
	cout << "output:" << endl;
	output();
	return 0;
}

void input() {
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			cin >> num[i][j];
}

void output() {
	int i, j;
	for (i = 0; i < 9; i++) {
		if (i % 3 == 0)cout << endl;
		for (j = 0; j < 9; j++) {
			if (j % 3 == 0)cout << " ";
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(int n, int key) {
	int i, j;
	int x = n / 9 / 3 * 3;//row
	int y = n % 9 / 3 * 3;//column
	for (j = 0; j < 8; j++)
		if (num[n / 9][j] == key)return false;//row
	for (i = 0; i < 8; i++)
		if (num[i][n % 9] == key)return false;//column
	for (i = x; i < x + 3; i++)
		for (j = y; j < y + 3; j++)
			if (num[i][j] == key)return false;//cell
	return true;
}

void dfs(int n) {
	if (n > 80) { sign = true; return; }

	int i;
	int x = n / 9;
	int y = n % 9;

	if (num[x][y] != 0)dfs(n + 1);

	for (i = 1; i < 10; i++) {
		if (check(n, i)) {
			num[x][y] = i;
			dfs(n + 1);
			if (sign == true) return;
			num[x][y] = 0;
		}
	}
}
