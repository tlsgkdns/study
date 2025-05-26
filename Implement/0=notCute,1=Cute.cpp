#include <iostream>

using namespace std;
int N, S[2], A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		S[A]++;
	}
	if (S[0] < S[1]) cout << "Junhee is cute!\n";
	else cout << "Junhee is not cute!\n";
}

// https://www.acmicpc.net/problem/10886