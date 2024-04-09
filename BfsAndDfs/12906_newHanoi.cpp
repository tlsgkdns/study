#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
int N;
string S;
queue <tuple<string, string, string>> q;
vector<string> input;
unordered_map<string, int> um;
string getStr(string& s1, string& s2, string& s3)
{
	return s1 + "D" + s2 + "D" + s3;
}
void checkEmpty(string& n1, string& n2, string& n3, int now)
{
	if (um.find(getStr(n1, n2, n3)) == um.end())
	{
		um[getStr(n1, n2, n3)] = now + 1;
		q.push(make_tuple(n1, n2, n3));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++)
	{
		cin >> N;
		if (N > 0)
		{
			cin >> S;
			input.push_back(S);
		}
		else
			input.push_back("");
	}
	q.push(make_tuple(input[0], input[1], input[2]));
	um.insert({ getStr(input[0], input[1], input[2]), 0 });
	while (!q.empty())
	{
		string s1 = get<0>(q.front());
		string s2 = get<1>(q.front());
		string s3 = get<2>(q.front());
		q.pop();
		int now = um[getStr(s1, s2, s3)];
		if (s1 == string(s1.size(), 'A') && s2 == string(s2.size(), 'B') && s3 == string(s3.size(), 'C'))
		{
			cout << now << '\n';
			break;
		}
		if (!s1.empty())
		{
			string n1 = s1;
			n1.pop_back();
			string n2 = s2;
			string n3 = s3;
			n2.push_back(s1.back());
			checkEmpty(n1, n2, n3, now);
			n2.pop_back();
			n3.push_back(s1.back());
			checkEmpty(n1, n2, n3, now);
		}
		if (!s2.empty())
		{
			string n1 = s1;
			string n2 = s2;
			n2.pop_back();
			string n3 = s3;
			n1.push_back(s2.back());
			checkEmpty(n1, n2, n3, now);
			n1.pop_back();
			n3.push_back(s2.back());
			checkEmpty(n1, n2, n3, now);
		}
		if (!s3.empty())
		{
			string n1 = s1;
			string n2 = s2;
			string n3 = s3;
			n3.pop_back();
			n1.push_back(s3.back());
			checkEmpty(n1, n2, n3, now);
			n1.pop_back();
			n2.push_back(s3.back());
			checkEmpty(n1, n2, n3, now);
		}
	}
}

// https://www.acmicpc.net/problem/12906