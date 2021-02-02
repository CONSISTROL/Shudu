#include<iostream>
#include<ctime>
using namespace std;

int num[9][9];
bool sign = false;
int program_time;

void input();
void output();
bool check(int n, int key);
void dfs(int n);

int main() {
	input();
	program_time = clock();
	dfs(0);
	output();
	cout << "The run time is: " << double(clock() - program_time) / 1000 << "s" << endl;
	return 0;
}

void input() {
	cout << "input:" << endl;
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			cin >> num[i][j];
}

void output() {
	cout << "output:" << endl;
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

void bar(int n) {//进度条
	static int cnt = 0;
	static int bar_time = clock();
	if (clock() - bar_time > 1000 && clock() - program_time > 5000) {//长时间未响应，给出提示
		bar_time = clock();
		//cnt = 0;//会回弹
		printf(" waiting time:%2.0fs", float(bar_time - program_time) / 1000);
		for (int i = 0; i < 17; i++)
			printf("\b");
	}
	if (n > cnt) {//防回弹减速
		printf("\r");//与system("\r")相比，防频闪，速度更快
		int j;
		for (j = 1; j <= n; j++) {
			cout << "█";
		}
		for (; j <= 80; j++) {
			cout << " ";
		}
		cout << "  " << n << "/81";
		cnt++;
		if (n == 81)cout << endl;
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
	bar(n);
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
