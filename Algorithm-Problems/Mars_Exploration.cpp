#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    string s1 = "SOS";
    int n = s.length();
    int cnt = 0;
    int k = 0;
    for(int i = 0;i<n;i++){
        if(s[i]!=s1[k])
            cnt++;
        k = (k+1)%3;
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
