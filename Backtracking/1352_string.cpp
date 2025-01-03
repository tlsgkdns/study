#include <iostream>
#include <vector>

using namespace std;


int N, alp[26];
string tmp = "", ans = "";
bool f = false;
void solve(int cnt, int ch)
{
	if (f || cnt + tmp.size() > N) return;
	if (cnt + tmp.size() == N)
	{
		f = true; cnt;
		for (int i = 0; i < 26; i++)
			while (alp[i] > 0)
			{
				tmp.push_back(i + 'A');
				alp[i]--;
			}
		ans = tmp;
		return;
	}
	for (int i = 0; i < 26; i++)
		if (alp[i] > 0)
		{
			tmp.push_back(i + 'A');
			alp[i]--;
			solve(cnt - 1, ch);
			alp[i]++;
			tmp.pop_back();
			break;
		}
	int nxt = tmp.size();
	alp[ch] += nxt;
	tmp.push_back(ch + 'A');
	solve(cnt + nxt, ch + 1);
	alp[ch] -= nxt;
	tmp.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve(0, 0);
	if (!f) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1352