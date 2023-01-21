#include <iostream>
#include <algorithm>
using namespace std;

int N;
int score = 0, cons = 0, S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		if (S) score += ++cons;
		else cons = 0;
	}
	cout << score << '\n';
}

// https://www.acmicpc.net/problem/2506