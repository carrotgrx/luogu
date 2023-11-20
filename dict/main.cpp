#include<bits/stdc++.h>
using namespace std;

bool compare(char a, char b) {
    return a > b;
}

string posi(string input) {
    sort(input.begin(), input.end());
    return input;
}

string nega(string input) {
    sort(input.begin(), input.end(), compare);
    return input;
}

int main() {
    ifstream fin("dict.in");
    ofstream fout("dict.out");

    int n, m;
    fin >> n >> m;

    vector<string> words(n);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        fin >> words[i];
    }

    for (int i = 0; i < words.size(); ++i) {
        int flag = 0;
        for (int j = 0; j < words.size(); ++j) {
            if (i != j) {
                if (posi(words[i]) >= nega(words[j])) {
                    result[i] = 0;
                    flag = 0;
                    j = words.size();
                }
                else if (posi(words[i]) <= nega(words[j])) {
                    flag = 1;
                }
            }
        }
        if (flag) {
            result[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        fout << result[i];
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
