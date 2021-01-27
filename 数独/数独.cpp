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

}

void dfs(int n) {

}
