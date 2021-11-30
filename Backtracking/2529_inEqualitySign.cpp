#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

vector<char> br;
int K;
ll mn = 10000000000, mx = -1;
string mnStr, mxStr;

bool isSatisfy(string& str)
{
	if (str.size() <= 1) return true;
	int bIdx = str.size() - 1;
	if (str[bIdx - 1] < str[bIdx] && br[bIdx - 1] == '<')
		return true;
	if (str[bIdx - 1] > str[bIdx] && br[bIdx - 1] == '>')
		return true;
	return false;
}
void solve(vector<bool> used, string& str)
{
	if (str.size() == K + 1)
	{
		if (mn > stoll(str))
		{
			mn = stoll(str);
			mnStr = str;
		}
		else if (mx < stoll(str))
		{
			mx = stoll(str);
			mxStr = str;
		}
		return;
	}
	for (int n = 0; n < used.size(); n++)
	{
		if (used[n]) continue;
		str.push_back(n + '0');
		used[n] = true;
		if (isSatisfy(str)) solve(used, str);
		used[n] = false;
		str.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	br.resize(K);
	for (int i = 0; i < K; i++)	cin >> br[i];
	vector<bool> use(10, false);
	string str = "";
	solve(use, str);
	cout << mxStr << '\n';
	cout << mnStr << '\n';
}

// https://www.acmicpc.net/problem/2529