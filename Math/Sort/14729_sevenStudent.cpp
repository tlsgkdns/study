#include <iostream>
#include <algorithm>

using namespace std;
double S[10000000];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	sort(S, S + N);
	cout << fixed; cout.precision(3);
	for (int i = 0; i < 7; i++)
		cout << S[i] << '\n';
}

// https://www.acmicpc.net/problem/14729