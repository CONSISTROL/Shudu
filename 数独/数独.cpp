﻿#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

int num[9][9];
bool sign;
int program_time;
int bar_time;
int cnt;

int input(int);
void output(int);
bool check(int n, int key);
void dfs(int n);

int main() {
	int m;
	do {
		cout << "控制台输入请按1,文件输入请按2" << endl;
		int n; cin >> n;
		if (input(n)) return 0;
		sign = false;
		program_time = clock();//从这开始记录时间
		bar_time = clock();
		cnt = 0;
		dfs(0);
		output(1);
		cout << "continue..?\n1.yes   2.no\n";
		cin >> m;
	} while (m==1);
	return 0;
}

int input(int n) {
	switch (n) {
	case 1: {
		cout << "input:" << endl;
		int i, j;
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				cin >> num[i][j];
		break;
	}
	case 2: {
		ifstream in("in.txt");
		if (!in.is_open()) {
			ofstream out("in.txt");
			out.close();
		}
		system("in.txt");
		int t1;
		cout << "读取数组" << endl;
		int*p = &num[0][0];
		for (int i = 0; i < 81;i++) {
			in >> t1;
			*p = t1;
			p++;
		}
		output(0);
		in.close();
		break;
	}
	}
	return 0;
}

void output(int n) {
	if(n) cout << "output:" << endl;
	int i, j;
	for (i = 0; i < 9; i++) {
		if (i % 3 == 0)cout << endl;
		for (j = 0; j < 9; j++) {
			if (j % 3 == 0)cout << " ";
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	if(n) cout << "The run time is: " << double(clock() - program_time) / 1000 << "s" << endl;
}

void bar(int n) {//进度条
	if (n > cnt) {//防回弹减速
		printf("\r");//与system("cls")相比，防频闪，速度更快
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
	if (clock() - bar_time > 1000 && clock() - program_time > 4000) {//长时间未响应，给出提示
		bar_time = clock();
		//cnt = 0;//会回弹
		printf(" waiting time:%2.0fs", float(bar_time - program_time) / 1000);
		for (int i = 0; i < 17; i++)
			printf("\b");
	}
}

bool check(int n, int key) {
	int i, j;
	int x = n / 9 / 3 * 3;//row
	int y = n % 9 / 3 * 3;//column
	for (j = 0; j < 9; j++)
		if (num[n / 9][j] == key)return false;//row
	for (i = 0; i < 9; i++)
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
	else {
		for (i = 1; i < 10; i++) {
			if (check(n, i)) {
				num[x][y] = i;
				dfs(n + 1);
				if (sign == true) return;
				num[x][y] = 0;
			}
		}
	}
}
