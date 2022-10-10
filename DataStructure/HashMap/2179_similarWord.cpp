#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<pair<string, int>> words;
unordered_map<string, int> um;
int N, l = 0, sidx = 0, cnt = 0;
string w, head, key;
string word[20001];
vector<int> arr[20001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
		words.push_back({ word[i], i });
	}
	sort(words.begin(), words.end());
	for (int i = 0; i < N - 1; i++)
	{
		int idx = 0, s = min(words[i].first.size(), words[i + 1].first.size());
		while (idx < s && words[i].first[idx] == words[i + 1].first[idx])
			idx++;
		string tmp = string(words[i].first.begin(), words[i].first.begin() + idx);
		if (um.count(tmp) == 0)
			um[tmp] = cnt++;
		if ((int)key.size() < idx || (idx == (int)key.size() && sidx > min(words[i].second, words[i + 1].second)))
		{
			key = tmp;
			sidx = min(words[i].second, words[i + 1].second);
		}
		arr[um[tmp]].push_back(words[i].second);
		arr[um[tmp]].push_back(words[i + 1].second);
	}
	sort(arr[um[key]].begin(), arr[um[key]].end());
	unique(arr[um[key]].begin(), arr[um[key]].end());
	cout << word[arr[um[key]][0]] << '\n' << word[arr[um[key]][1]] << '\n';
}

// https://www.acmicpc.net/problem/2179