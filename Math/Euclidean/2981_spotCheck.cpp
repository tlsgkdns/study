#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, S[101];
vector<int> C;
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (b > 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int i = 0; i < N - 1; i++) C.push_back(abs(S[i] - S[i + 1]));
	int g = C[0];
	for (int i = 1; i < C.size(); i++) g = gcd(g, C[i]);
	for (int i = 2; i <= g / 2; i++)
		if (g % i == 0)
			cout << i << " ";
	cout << g << '\n';
}

// https://www.acmicpc.net/problem/2981