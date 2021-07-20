#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

vector<string> bigSorting(vector<string> unsorted) {
    string min;
    int s = unsorted.size();
    for(int i=0;i<s-1;i++){
        int k = 0;
        min = unsorted[i];
        for(int j=i+1;j<s;j++){
            string s1 = unsorted[j];
            if(s1.length()<min.length()){
                k = j;
                min = s1;
            }
            else if(s1.length()==min.length()){
                for(int l=0;l<min.length();l++){
                    if(s1[l]<min[l]){
                        min = s1;
                        k = j;
                        break;
                    }
                    else if(s1[l]==min[l])
                        continue;
                    else
                        break;
                }
            }
            else
                continue;
        }
        if(k>0)
            swap(unsorted[i], unsorted[k]);
        
    }
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

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
