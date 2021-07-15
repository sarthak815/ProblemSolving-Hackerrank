#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic) {
    int max = 0;
    int res = 0;
    int sum = 0;
    vector<int> v;
    for(auto it1=topic.begin();it1!=topic.end()-1;it1++){
        string s = *it1;
        int n = s.length();
       vector<int> arr(n);
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                arr[i]++;
        }
        for(auto it = it1+1;it!=topic.end();it++){
            vector<int> arr1(n);
            arr1 = arr;
            string s1 = *it;
            for(int i=0;i<n;i++){
                if(s1[i]=='1'&&arr[i]==0)
                    arr1[i]++;
            }
            sum = accumulate(arr1.begin(),arr1.end(),sum);
            if(sum==max)
                res++;
            if(sum>max){
                max = sum;
                res = 1;
            }
            
            sum = 0;
            
        }
    }
    v.push_back(max);
    v.push_back(res);
    return v;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
