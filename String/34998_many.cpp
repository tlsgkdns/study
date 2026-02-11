#include <iostream>
#include <string>

using namespace std;

string S;
int N, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--)
    {
        cin >> X;
        getline(cin, S);
        getline(cin, S);
        bool m = false;
        int s = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '+' || S[i] == ' ') continue;
            if (S[i] == '!')
            {
                m = true;
                break;
            }
            s += (S[i] - '0');
        }
        if (m || s >= 10) cout << "!\n";
        else cout << s << '\n';
    }
}

// https://www.acmicpc.net/problem/34998