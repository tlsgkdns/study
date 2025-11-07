#include <iostream>

using namespace std;
int N, A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (true)
	{
		cin >> A;
		if (A == 0) break;
		cout << A << " is ";
		if (A % N > 0) cout << "NOT ";
		cout << "a multiple of " << N << ".\n";
	}
}

// https://www.acmicpc.net/problem/4504