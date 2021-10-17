#include <iostream>

using namespace std;

int N, K;
string str;

struct Trie
{
	Trie* alp[26] = { NULL };
	int leng, lv;
	Trie()
	{
		leng = -1; lv = -1;
		for (int i = 0; i < 26; i++) alp[i] = NULL;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
			if (alp[i]) delete alp[i];
	}
	void insert(const char* s, int l, int lev)
	{
		if (!*s)
		{
			leng = l;
			lv = lev;
			return;
		}
		int here = *s - 'A';
		if (!alp[here]) alp[here] = new Trie();
		alp[here]->insert(s + 1, l, lev);
	}
	void tour(string s)
	{
		if (this->leng >= 0)
		{
			for (int l = 0; l < this->lv; l++)
				cout << "--";
			string tmpS(s.end() - leng, s.end());
			cout << tmpS << '\n';
		}
		for (int i = 0; i < 26; i++)
		{
			if (!alp[i]) continue;
			string tmp = s;
			tmp.push_back(i + 'A');
			alp[i]->tour(tmp);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Trie* tr = new Trie();
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		string s = "";
		for (int k = 0; k < K; k++)
		{
			cin >> str;
			s += str;
			tr->insert(s.c_str(), str.size(), k);
		}
	}
	tr->tour("");
}
// https://www.acmicpc.net/problem/14725