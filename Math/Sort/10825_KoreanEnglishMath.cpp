#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
public:
	string name;
	int korean, english, math;
	Student(string n, int k, int e, int m)
	{
		name = n;
		korean = k;
		english = e;
		math = m;
	}
};

vector<Student*> S;
string n;
int N, K, M, E;

bool cmp(Student* s1, Student* s2)
{
	if (s1->korean == s2->korean)
	{
		if (s1->english == s2->english)
		{
			if (s1->math == s2->math)
				return s1->name < s2->name;
			return s1->math > s2->math;
		}
		return s1->english < s2->english;
	}
	return s1->korean > s2->korean;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n >> K >> E >> M;
		S.push_back(new Student(n, K, E, M));
	}
	sort(S.begin(), S.end(), cmp);
	for (int i = 0; i < S.size(); i++) cout << S[i]->name << '\n';
}

// https://www.acmicpc.net/problem/10825