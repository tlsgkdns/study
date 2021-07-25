#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<vector<bool>> adj;
	int N = 0, dst = -1, src = -1, minSize = 1002;
	bool canChange(string s1, string s2)
	{
		int l = s1.size();
		int ret = 0;
		for (int i = 0; i < l; i++)
			if (s1[i] != s2[i]) ret++;
		return (ret == 1);
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
	{
		vector<vector<string>> ret;
		for (int i = 0; i < wordList.size(); i++)
		{
			if (wordList[i] == endWord)
				dst = i;
			else if (wordList[i] == beginWord)
				src = i;
		}
		if (dst == -1) return ret;
		if (src == -1)
		{
			src = wordList.size();
			wordList.push_back(beginWord);
		}
		N = wordList.size();
		adj.resize(N, vector<bool>(N, false));
		vector<bool> v(N, false);
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
			{
				adj[i][j] = canChange(wordList[i], wordList[j]);
				adj[j][i] = adj[i][j];
			}
		queue<vector<int>> q;
		q.push({ src });
		v[src] = true;
		while (!q.empty())
		{
			vector<int> f = q.front();
			q.pop();
			if (f.size() >= minSize) continue;
			v[f.back()] = true;
			for (int i = 0; i < N; i++)
			{
				if (i == dst && adj[f.back()][i])
				{
					minSize = f.size() + 1;
					vector<string> ans;
					for (int i = 0; i < f.size(); i++)
						ans.push_back(wordList[f[i]]);
					ans.push_back(endWord);
					ret.push_back(ans);
					continue;
				}
				if (v[i] || !adj[f.back()][i]) continue;
				f.push_back(i);
				q.push(f);
				f.pop_back();
			}
		}
		return ret;
	}
};

int main()
{
	string src, dst;
	int N;
	cin >> N;
	cin >> src >> dst;
	vector<string> wordList(N);
	for (int i = 0; i < N; i++) cin >> wordList[i];
	Solution* s = new Solution();
	auto ans = s->findLadders(src, dst, wordList);
	for (vector<string> v : ans)
	{
		for (string str : v)
			cout << str << " ";
		cout << '\n';
	}
}

// https://leetcode.com/problems/word-ladder-ii/ 