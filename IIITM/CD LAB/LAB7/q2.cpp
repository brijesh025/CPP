#include <bits/stdc++.h>
using namespace std;

struct Item {
    string lhs;
    vector<string> rhs;
    int dot;
    string lookahead;

    bool operator==(const Item &other) const {
        return lhs==other.lhs && rhs==other.rhs && dot==other.dot && lookahead==other.lookahead;
    }
};

struct ItemHasher {
    size_t operator()(const Item &it) const {
        size_t res = hash<string>()(it.lhs) ^ hash<int>()(it.dot);
        for(auto &s: it.rhs) res ^= hash<string>()(s);
        res ^= hash<string>()(it.lookahead);
        return res;
    }
};

vector<string> terminals = {"id","*","=","$"};
vector<string> nonTerminals = {"S","L","R"};

map<string, vector<vector<string>>> grammar = {
    {"S", {{"L","=","R"},{"R"}}},
    {"L", {{"*","R"},{"id"}}},
    {"R", {{"L"}}}
};

bool isTerminal(string s){ return find(terminals.begin(),terminals.end(),s)!=terminals.end(); }

map<string,set<string>> FIRST_sets;

set<string> computeFIRST(string X){
    if(isTerminal(X)) return {X};
    if(!FIRST_sets[X].empty()) return FIRST_sets[X];

    set<string> res;
    for(auto &prod: grammar[X]){
        if(prod[0]=="ε"){ res.insert("ε"); continue; }
        for(auto &sym: prod){
            auto f = computeFIRST(sym);
            res.insert(f.begin(),f.end());
            if(f.find("ε")==f.end()) break;
        }
    }
    FIRST_sets[X] = res;
    return res;
}

vector<Item> closure(vector<Item> items){
    set<Item, function<bool(const Item&, const Item&)>> closureSet(
        [](const Item &a, const Item &b){
            if(a.lhs!=b.lhs) return a.lhs<b.lhs;
            if(a.rhs!=b.rhs) return a.rhs<b.rhs;
            if(a.dot!=b.dot) return a.dot<b.dot;
            return a.lookahead<b.lookahead;
        });
    for(auto &it: items) closureSet.insert(it);

    bool added=true;
    while(added){
        added=false;
        vector<Item> current(closureSet.begin(),closureSet.end());
        for(auto &item: current){
            if(item.dot < item.rhs.size() && !isTerminal(item.rhs[item.dot])){
                string B = item.rhs[item.dot];
                vector<string> beta;
                for(int k=item.dot+1;k<item.rhs.size();k++) beta.push_back(item.rhs[k]);
                beta.push_back(item.lookahead);

                set<string> lookaheads;
                for(auto &b: beta){
                    auto f = isTerminal(b)? set<string>{b} : FIRST_sets[b];
                    lookaheads.insert(f.begin(),f.end());
                    if(f.find("ε")==f.end()) break;
                }

                for(auto &prod: grammar[B]){
                    for(auto &la: lookaheads){
                        Item newItem{B,prod,0,la};
                        if(closureSet.insert(newItem).second) added=true;
                    }
                }
            }
        }
    }
    return vector<Item>(closureSet.begin(),closureSet.end());
}

vector<Item> gotoItems(vector<Item> I, string X){
    vector<Item> moved;
    for(auto &it: I){
        if(it.dot<it.rhs.size() && it.rhs[it.dot]==X)
            moved.push_back({it.lhs,it.rhs,it.dot+1,it.lookahead});
    }
    return closure(moved);
}

void printItems(vector<Item> I){
    for(auto &it: I){
        cout<<"  "<<it.lhs<<" -> ";
        for(int k=0;k<it.rhs.size();k++){
            if(k==it.dot) cout<<".";
            cout<<it.rhs[k]<<" ";
        }
        if(it.dot==it.rhs.size()) cout<<".";
        cout<<endl;
    }
}

int main(){
    for(auto &nt: nonTerminals) computeFIRST(nt);

    Item start = {"S'", {"S"}, 0, "$"};
    vector<Item> C0 = closure({start});
    vector<vector<Item>> C={C0};

    queue<int> q;
    q.push(0);

    map<int,map<string,int>> GOTO;

    while(!q.empty()){
        int i=q.front(); q.pop();
        set<string> symbols;
        for(auto &it: C[i]){
            if(it.dot<it.rhs.size()) symbols.insert(it.rhs[it.dot]);
        }
        for(auto &X: symbols){
            vector<Item> g = gotoItems(C[i], X);
            if(g.empty()) continue;
            int j=-1;
            for(int k=0;k<C.size();k++){
                if(C[k].size()==g.size() && equal(C[k].begin(),C[k].end(), g.begin(), [](Item a, Item b){
                    return a.lhs==b.lhs && a.rhs==b.rhs && a.dot==b.dot && a.lookahead==b.lookahead;
                })){ j=k; break; }
            }
            if(j==-1){ C.push_back(g); j=C.size()-1; q.push(j); }
            GOTO[i][X]=j;
        }
    }

    for(int i=0;i<C.size();i++){
        cout<<"I"<<i<<":\n";
        printItems(C[i]);
        cout<<endl;
    }
}
