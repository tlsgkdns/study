#include <iostream>
#include <string>

using namespace std;

string t1, t2;
int s1 = 0, s2 = 0;
int calc(string& s, int idx)
{
	return (s[idx] - '0') * 10 + (s[idx + 1] - '0');
}
int getTime(string& s)
{
	return 3600 * calc(s, 0) + 60 * calc(s, 3) + calc(s, 6);
}
string getInput(int n)
{
	if (n / 10 > 0) return to_string(n);
	return '0' + to_string(n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t1;
	cin >> t2;
	int s1 = getTime(t1);
	int s2 = getTime(t2);
	s2 = (s2 < s1) ? s2 + (3600 * 24) : s2;
	int sub = s2 - s1;
	cout << getInput((sub / 3600) % 24) << ":" << getInput(((sub % 3600) / 60) % 60) << ":" << getInput(sub % 60) << '\n';
}

// https://www.acmicpc.net/problem/1408