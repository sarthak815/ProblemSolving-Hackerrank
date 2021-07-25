#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    int arr[26]={0};
    int n = s.length();
    for(int i=0;i<n;i++)
        arr[s[i]-'a']++;
    int cnt=0;
    for(int i=0;i<26;i++){
        if(arr[i]%2!=0&&cnt==1)
            return "NO";
        if(arr[i]%2!=0)
            cnt++;
    }
    return "YES";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
