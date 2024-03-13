#include <iostream>
#include <algorithm>
using namespace std;

string W, ans = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W;
	for (int i = 0; i < W.size(); i++) ans.push_back('z');
	for (int i = 1; i < W.size() - 1; i++)
		for (int j = i + 1; j < W.size(); j++)
		{
			string s1(W.begin(), W.begin() + i), s2(W.begin() + i, W.begin() + j), s3(W.begin() + j, W.end());
			reverse(s1.begin(), s1.end()); reverse(s2.begin(), s2.end()); reverse(s3.begin(), s3.end());
			string tmp = "";
			tmp += s1; tmp += s2; tmp += s3;
			if (ans > tmp) ans = tmp;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2993