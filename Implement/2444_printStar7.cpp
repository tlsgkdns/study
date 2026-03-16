#include <iostream>
#include <algorithm>

using namespace std;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) cout << "*";
		cout << '\n';
	}
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < N - i - 1; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) cout << "*";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2444