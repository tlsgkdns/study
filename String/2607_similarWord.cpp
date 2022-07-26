#include <iostream>
#include <cmath>
using namespace std;

string target, word;
int N, ans = 0;
int alp[26][101];

bool solve(int idx)
{
	int add = 0, sub = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alp[i][idx] == alp[i][0]) continue;
		if (alp[i][idx] > alp[i][0]) add += (alp[i][idx] - alp[i][0]);
		if (alp[i][idx] < alp[i][0]) sub += (alp[i][0] - alp[i][idx]);
	}
	return (add < 2 && sub < 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> target;
	for (int i = 0; i < target.size(); i++) alp[target[i] - 'A'][0]++;
	for (int i = 1; i < N; i++)
	{
		cin >> word;
		if (abs((int)word.size() - (int)target.size()) > 1) continue;
		for (int j = 0; j < word.size(); j++) alp[word[j] - 'A'][i]++;
		ans += solve(i);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2607