#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */
string unique(string s)
{
    string str;
    int len = s.length();
 
   
    for(int i = 0; i < len; i++)
    {     
 
        char c = s[i];

        auto found = str.find(c);
        if (found == std::string::npos)
        {
             
            str += c;
        }
    }
    return str;
}
int gemstones(vector<string> arr) {
    sort(arr.begin(), arr.end(), []
    (string& first, string& second){
        return first.size() < second.size();
    });
    int cnt = 0;
    string s1 = arr[0];
    string s = unique(s1);
    int n = arr.size();
    int n1 = s.length();
    int cnt1=0;
    for(int i=0;i<n1;i++){
        char ch = s[i];
        cnt1=0;
        for(int j=1;j<arr.size();j++){
            string str = arr[j];
            int l = str.length();
            for(int k=0;k<l;k++){
                if(str[k]==ch){
                    cnt1++;
                    break;
                }
            }
        }
        if(cnt1 == n-1)
            cnt++;
        
        
    }
    return cnt;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

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
