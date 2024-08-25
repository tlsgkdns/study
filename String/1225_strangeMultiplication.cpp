#include <iostream>

using namespace std;

string A, B;
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			ans += (A[i] - '0') * (B[j] - '0');
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1225