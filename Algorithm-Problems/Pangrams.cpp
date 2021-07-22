#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    set<char> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(isalpha(s[i]))
            st.insert(tolower(s[i]));
    }
    if(st.size()==26)
        return "pangram";
    else
        return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
