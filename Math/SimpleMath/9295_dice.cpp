#include <iostream>
using namespace std;
int N, A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int t = 1; t <= N; t++)
	{
		cin >> A >> B;
		cout << "Case " << t << ": " << A + B << '\n';
	}
}

// https://www.acmicpc.net/problem/9295