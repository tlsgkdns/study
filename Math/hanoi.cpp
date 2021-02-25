#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
vector<pair<int, int>> mv;
long long ans = 0, N;
void hanoi(int n, int from, int tmp, int to)
{
	if (n == 1)
	{
		mv.push_back(make_pair(from, to));
		ans++;
		return;
	}
	hanoi(n - 1, from, to, tmp);
	hanoi(1, from, tmp, to);
	hanoi(n - 1, tmp, from, to);
}

string bigNumPow(int x, int y)
{
	y--;
	string ret = "2";
	while (y != 0)
	{
		string s = "";
		int carry = 0;
		for (int i = ret.size() - 1; i >= 0; i--)
		{
			int tmp = ret[i] - '0';
			tmp *= x; tmp += carry;
			carry = tmp / 10;
			tmp %= 10;
			s = to_string(tmp) + s;
		}
		if (carry == 0) ret = s;
		else ret = to_string(carry) + s;
		y--;
	}
	ret.back() = ret.back() - 1;
	return ret;
}
int main()
{
	cin >> N;
	if (N <= 20)
	{
		hanoi(N, 1, 2, 3);
		cout << ans << '\n';
		for (auto m : mv) cout << m.first << " " << m.second << '\n';
	}
	else
		cout << bigNumPow(2, N) << '\n';

}

// https://www.acmicpc.net/problem/1914

/*
Start to review hanoi.
Learned how to handle bigInteger by string.
Felt void that there's int128 in c++
*/