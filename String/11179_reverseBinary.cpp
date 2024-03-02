#include <iostream>
#include <cmath>

using namespace std;
string B = "";
int N = 0, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N > 1)
	{
		B.push_back((N % 2) + '0');
		N /= 2;
	}
	B.push_back((N % 2) + '0');
	for (int i = B.size() - 1; i >= 0; i--)
		if (B[i] == '1')
			ans += pow(2, B.size() - 1 - i);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11179