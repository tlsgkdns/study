#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<int> alp[55];
string S, P;
int ans = 0;
int getIdx(char c)
{
	if (isdigit(c))
		return (c - '0');
	else if (islower(c))
		return (c - 'a' + 10);
	return c - 'A' + 36;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> P;
	int idx = 0;
	for (int i = 0; i < S.size(); i++)
		alp[getIdx(S[i])].push_back(i);
	while (idx < P.size())
	{
		int m = 0;
		for (int i = 0; i < alp[getIdx(P[idx])].size(); i++)
		{
			int s = alp[getIdx(P[idx])][i];
			int l = 0;
			while (idx + l < P.size() && s + l < S.size() && S[s + l] == P[idx + l])
				++l;
			m = max(m, l);
		}
		++ans;
		idx += m;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2195