#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int ALP = 26;
int c, n, Q, CH = 0, CM = 2001, NH = 0, NM = 2001, v[2001];
struct Trie
{
public:
	bool terminal;
	map<char, Trie*> next;
	void insert(string& str, int idx)
	{
		if (idx == str.size())
			terminal = true;
		else
		{
			char curr = str[idx];
			if (next.count(curr) == 0)
				next[curr] = new Trie();
			next[curr]->insert(str, idx + 1);
		}
	}
	void find(string& str, int idx, bool isClr)
	{
		if (terminal) (isClr) ? ++v[idx] : ++v[idx + 1];
		if (next.count(str[idx]) == 0) return;
		return next[str[idx]]->find(str, (isClr) ? idx + 1 : idx - 1, isClr);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> c >> n;
	string color, team, name;
	Trie* clr = new Trie(), * nick = new Trie();
	for (int i = 0; i < c; i++)
	{
		cin >> color;
		CH = max((int)color.size(), CH);
		CM = min((int)color.size(), CM);
		clr->insert(color, 0);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> team;
		NH = max((int)team.size(), NH);
		NM = min((int)team.size(), NM);
		reverse(team.begin(), team.end());
		nick->insert(team, 0);
	}
	cin >> Q;
	while (Q--)
	{
		memset(v, 0, sizeof(v));
		bool br = false;
		cin >> name;
		if (CM + NM <= (int)name.size())
		{
			clr->find(name, 0, true);
			nick->find(name, name.size() - 1, false);
			for (int i = 0; i < name.size(); i++)
			{
				if (v[i] == 2)
				{
					br = true;
					break;
				}
			}
		}
		if (br) cout << "Yes\n";
		else cout << "No\n";
	}
}

// https://www.acmicpc.net/problem/19585