#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> waiter(vector<int> v, int q) {
    queue<int> prime;
 
    int i=3,c;
    if(q >= 1)
    {
        prime.push(2);
    }
    for(int count = 2; count <= q+1; i++)  
    {
        // iteration to check c is prime or not
        for(c = 2; c < i; c++)
        {
            if(i%c == 0)
                break;
        }

        if(c == i)  // c is prime
        {
            prime.push(i);
            count++;    // increment the count of prime numbers
        }

    }
    int k=0;
    vector<int> ans;
    stack<int> st2;
    stack<int> st;
    stack<int> st1;
    for(auto it=v.begin();it!=v.end();it++)
        st2.push(*it);
    while(k<q){
        int n=prime.front();
        prime.pop();
        k++;
        while(!st2.empty()){
            int p = st2.top();
            st2.pop();
            if(p%n==0)
                st.push(p);
            else
                st1.push(p);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        st2=st1;
        while(!st1.empty())
            st1.pop();
    }
    while(!st2.empty()){
        ans.push_back(st2.top());
        st2.pop();
        }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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
