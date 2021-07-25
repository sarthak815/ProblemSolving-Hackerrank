#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    int arr1[27]={0};
    int arr2[27]={0};
    for(int i=0;i<n1;i++){
        arr1[s1[i]-'a']++;
    }
    for(int i=0;i<n2;i++){
        arr2[s2[i]-'a']++;
    }
    int cnt = 0;
    for(int i=0;i<27;i++){
        int diff = abs(arr1[i]-arr2[i]);
        cnt = cnt+diff;
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
