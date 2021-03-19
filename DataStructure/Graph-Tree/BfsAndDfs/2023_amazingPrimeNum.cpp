#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int n;
bool isPrime(int num)
{
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	return true;
}
void dfs(int num, int d)
{
	if (d == n)
	{
		cout << num << '\n';
		return;
	}
	for (int i = 1; i <= 9; i += 2)
	{
		int nxt = (num * 10) + i;
		if (isPrime(nxt)) dfs(nxt, d + 1);
	}
}
int main()
{
	cin >> n;
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}

// https://www.acmicpc.net/problem/2023

/*
First I tried eratostenes, but when I finished the code.
I guess its time is long and memory is large.
So I tried dfs and it solved easily.
*/