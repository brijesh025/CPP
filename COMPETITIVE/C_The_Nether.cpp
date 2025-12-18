#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask_pair(int x, int y){
    cout << "? " << x << " 2 " << x << " " << y << endl;
    cout.flush();
    int ans; 
    if(!(cin >> ans)) exit(0);
    if(ans == -1) exit(0);
    return ans;
}

int ask_set(int x, const vector<int>& S){
    cout << "? " << x << " " << (int)S.size();
    for(int v: S) cout << " " << v;
    cout << endl;
    cout.flush();
    int ans;
    if(!(cin >> ans)) exit(0);
    if(ans == -1) exit(0);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        int cur = 1;
        for(int v = 2; v <= n; ++v){
            int res = ask_pair(cur, v); 
            if(res == 2){
            } else {

                cur = v;
            }
        }
        vector<int> path;
        path.push_back(cur);
        vector<int> rem;
        for(int i = 1; i <= n; ++i) if(i != cur) rem.push_back(i);

        while(true){

            vector<int> bigS;
            bigS.push_back(cur);
            for(int v: rem) bigS.push_back(v);
            int longest = ask_set(cur, bigS);
            if(longest <= 1) break;
            int chosen = -1;
            for(size_t i = 0; i < rem.size(); ++i){
                int v = rem[i];
                int res = ask_pair(cur, v);
                if(res == 2){
                    chosen = v;

                    rem[i] = rem.back();
                    rem.pop_back();
                    break;
                }
            }
            if(chosen == -1)break;
            path.push_back(chosen);
            cur = chosen;
        }
        cout << "! " << path.size();
        for(int v: path) cout << " " << v;
        cout << endl;
        cout.flush();

    }
    return 0;
}
