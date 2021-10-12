#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int ALP = 26;
int n;
vector<double> ans;
class Tri
{
private:
	Tri* child[ALP];
public:
	int cnt = 0;
	bool terminal = false;
	Tri()
	{
		cnt = 0;
		terminal = false;
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
		return tolower(c) - 'a';
	}
	void insert(const char* words)
	{
		if (*words == '\0')
		{
			terminal = true;
			return;
		}
		int next = toNum(*words);

		if (child[next] == NULL)
		{
			child[next] = new Tri();
			cnt++;
		}
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
	int type(const char* key)
	{
		if (*key == 0) return 0;
		int next = toNum(*key);

		if (!terminal && cnt == 1)
			return child[next]->type(key + 1);

		return 1 + child[next]->type(key + 1);
	}
	int getCnt()
	{
		return cnt;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (!cin.eof())
	{
		Tri tri;
		vector<string> dic;
		string s;
		int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s; dic.push_back(s);
			tri.insert(s.c_str());
		}
		for (string str : dic)
		{
			int t = tri.type(str.c_str());
			if (!tri.terminal && tri.cnt == 1) t++;
			sum += t;
		}

		double avg = (double)sum / (double)n;
		ans.push_back(avg);
	}
	ans.pop_back();
	for (double a : ans)
		cout << fixed << setprecision(2) << a << '\n';
}

// https://www.acmicpc.net/problem/5670