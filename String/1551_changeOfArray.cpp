#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int N, M;
string S, token;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> S;
    stringstream ss(S);
    while (getline(ss, token, ','))
    {
        arr.push_back(stoi(token));
    }
    while (M--)
    {
        vector<int> tmp;
        for (int i = 1; i < arr.size(); i++)
            tmp.push_back(arr[i] - arr[i - 1]);
        arr = tmp;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ',';
    }
    cout << '\n';
}

// https://www.acmicpc.net/problem/1551