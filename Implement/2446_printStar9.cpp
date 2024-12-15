#include <iostream>
using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++) cout << " ";
		for (int j = 0; j < 2 * N - 2 * i - 1; j++)
			cout << "*";
		cout << '\n';
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) cout << "*";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2446