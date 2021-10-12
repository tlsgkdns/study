#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int ALP = 10;
int t;
class Tri
{
private:
	Tri* child[ALP];
public:
	Tri()
	{
		for (int i = 0; i < ALP; i++)
			child[i] = NULL;
	}
	~Tri()
	{
		for (int i = 0; i < ALP; i++)
			if (child[i] != NULL)
				delete child[i];
	}
	int toNum(char c)
	{
		return tolower(c) - '0';
	}
	void insert(const char* words)
	{
		if (*words == '\0') return;

		int next = toNum(*words);

		if (child[next] == NULL)
			child[next] = new Tri();

		child[next]->insert(words + 1);
	}

	bool find(const char* words)
	{
		int next = toNum(*words);

		if (*words == '\0')
			return true;

		if (child[next] == NULL)
			return false;

		return child[next]->find(words + 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<bool> ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<pair<int, string>> inp;
		string s; int n; bool a = true;
		cin >> n;
		Tri tr;
		for (int j = 0; j < n; j++)
		{
			cin >> s; int l = s.length();
			inp.push_back(make_pair(-l, s));
		}
		sort(inp.begin(), inp.end());
		for (pair<int, string> st : inp)
		{
			if (!tr.find(st.second.c_str()))
				tr.insert(st.second.c_str());
			else
			{
				a = false;
				break;
			}
		}
		ans.push_back(a);
	}
	for (bool a : ans)
	{
		string res = (a) ? "YES\n" : "NO\n";
		cout << res;
	}
}

// https://www.acmicpc.net/problem/5052