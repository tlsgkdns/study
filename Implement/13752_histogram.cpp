#include <iostream>

using namespace std;
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> K;
		for (int i = 0; i < K; i++) cout << "=";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/13752