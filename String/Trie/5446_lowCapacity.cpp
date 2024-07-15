#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int ALP = 65;
int N1, N2, T;
string F[1001], W;
class Tri
{
private:
	Tri* child[ALP];
public:
	bool terminal = false;
	bool cleaned = false;
	bool allClean = false;
	Tri()
	{
		terminal = false;
		cleaned = false;
		allClean = false;
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
		if (c == '.') return 0;
		if (isalpha(c))
		{
			if (isupper(c)) return c - 'A' + 1;
			else return c - 'a' + 27;
		}
		if (c == '-') return 64;
		return c - '0' + 53;
	}
	void insert(string& w, int idx)
	{
		if (w.size() == idx)
		{
			terminal = true;
			return;
		}
		int next = toNum(w[idx]);

		if (child[next] == NULL)
		{
			child[next] = new Tri();
		}
		child[next]->insert(w, idx + 1);
	}

	bool solve(string& w, int idx)
	{
		if (allClean) return false;
		if (w.size() == idx)
		{
			if (terminal || cleaned) return false;
			cleaned = true;
			return true;
		}
		int next = toNum(w[idx]);
		if (child[next] == NULL)
		{
			child[next] = new Tri();
			child[next]->allClean = true;
			return true;
		}
		return child[next]->solve(w, idx + 1);
	}

};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		Tri* t = new Tri();
		int ans = 0;
		cin >> N1;
		for (int i = 0; i < N1; i++)
		{
			cin >> F[i];
			F[i] = '-' + F[i];
		}
		cin >> N2;
		for (int i = 0; i < N2; i++)
		{
			cin >> W;
			W = "-" + W;
			t->insert(W, 0);
		}
		for (int i = 0; i < N1; i++)
			ans += t->solve(F[i], 0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5446