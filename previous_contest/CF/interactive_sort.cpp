#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,Q; cin >> N >> Q;
    string s = "";
    for(int i=0; i<N; i++) s += ('A' + i);

    vector<vector<int>> ord(26, vector<int>(26, -1));
    auto qry = [&](char c1, char c2){
        if (ord[c1 - 'A'][c2 - 'A'] != -1)
            return ord[c1 - 'A'][c2 - 'A'];
        if (ord[c2 - 'A'][c1 - 'A'] != -1)
            return (int)!ord[c2 - 'A'][c1 - 'A'];

        cout << "? " << c1 << " " << c2 << endl;
        fflush(stdout);

        char ans; cin >> ans;
        if (ans == '<') {
            ord[c1 - 'A'][c2 - 'A'] = 1;
            ord[c2 - 'A'][c1 - 'A'] = 0;
        }
        else{
            ord[c1 - 'A'][c2 - 'A'] = 0;
            ord[c2 - 'A'][c1 - 'A'] = 1;
        }
        return ord[c1 - 'A'][c2 - 'A'];
    };

    auto ins2 = [&](char c){
        if(qry(c, s[1])) {
            if(qry(c, s[2])) s[3] = c;
            else s[3] = s[2], s[2] = c;
        } else {
            if(qry(c, s[0])) {
                s[3] = s[2];
                s[2] = s[1];
                s[1] = c;
            } else {
                s[3] = s[2];
                s[2] = s[1];
                s[1] = s[0];
                s[0] = c;
            }
        }
    };

    if (N == 5){
        if(qry(s[0], s[1])) swap(s[0], s[1]);
        if(qry(s[2], s[3])) swap(s[2], s[3]);
        if(qry(s[1], s[3])) {
            swap(s[0], s[2]);
            swap(s[1], s[3]);
        }
        char x = s[2];
        if(qry(s[4], s[1])) {
            if(qry(s[4], s[3])) {
                s[2] = s[3];
                ins2(x);
            } else {
                s[2] = s[4];
                s[4] = s[3];
                ins2(x);
            }
        } else {
            if(qry(s[4], s[0])) {
                s[2] = s[1];
                s[1] = s[4];
                s[4] = s[3];
                ins2(x);
            } else {
                s[2] = s[1];
                s[1] = s[0];
                s[0] = s[4];
                s[4] = s[3];
                ins2(x);
            }
        }
        reverse(s.begin(),s.end());
        cout << "! " << s << endl;
        fflush(stdout);
    }
    else {
        string sorted_s = "";
        for (int i = 0; i < N; i++) {
            sorted_s.insert(lower_bound(sorted_s.begin(), sorted_s.end(), s[i], qry), s[i]);
        }

        cout << "! " << sorted_s << endl;
        fflush(stdout);
    }
    return 0;
}
