#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int num = 0;
    int lower = 0;
    int upper = 0;
    int spec = 0;
    for(int i=0;i<n;i++){
        if(password[i]>='0'&&password[i]<='9')
            num = 1;
        else if(password[i]>='A'&&password[i]<='Z')
            upper = 1;
        else if(password[i]>='a'&&password[i]<='z')
            lower = 1;
        else
            spec = 1;
    }
    int sum = num+upper+lower+spec;
    if(n>=6)
        return 4-sum;
    else{
        int k = 6-n;
        if((4-sum)<=k)
            return k;
        else
            return 4-sum;
    }
    return 4-sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
