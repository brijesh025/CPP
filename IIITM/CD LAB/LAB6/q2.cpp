#include <bits/stdc++.h>
using namespace std;

struct Prod{char lhs; string rhs;};
struct Item
{
    int p, d;
    Item(int P = 0, int D = 0) : p(P), d(D) {}
    bool operator<(Item const &o) const
    {
        if (p != o.p)
            return p < o.p;
        return d < o.d;
    }
    bool operator==(Item const &o) const { return p == o.p && d == o.d; }
};

vector<Prod> grammar;
set<char> terminals,nonterminals;
map<char,set<char>> firsts, follows;
map<char,bool> nullable;

set<Item> closure(set<Item> I){
    bool changed=true;
    while(changed){
        changed=false;
        vector<Item> toadd;
        for(auto it:I){
            int p=it.p, d=it.d;
            if(d<grammar[p].rhs.size()){
                char B=grammar[p].rhs[d];
                if(isupper(B)){
                    for(int i=0;i<grammar.size();++i) if(grammar[i].lhs==B){
                        Item newIt(i,0);
                        if(!I.count(newIt)) { toadd.push_back(newIt); changed=true; }
                    }
                }
            }
        }
        for(auto &x:toadd) I.insert(x);
    }
    return I;
}

set<Item> GOTO(set<Item> I,char X){
    set<Item> J;
    for(auto it:I){
        int p=it.p, d=it.d;
        if(d<grammar[p].rhs.size() && grammar[p].rhs[d]==X) J.insert(Item(p,d+1));
    }
    return closure(J);
}

int indexOf(vector<set<Item>> &C,set<Item> const&J){
    for(int i=0;i<C.size();++i) if(C[i]==J) return i;
    return -1;
}

void computeNullableFirst(){
    for(auto &p:grammar) if(p.rhs.empty()) nullable[p.lhs]=true;
    bool changed=true;
    while(changed){
        changed=false;
        for(auto &p:grammar){
            bool all=true;
            for(char c:p.rhs){
                if(!isupper(c) || !nullable[c]){ all=false; break;}
            }
            if(all && !nullable[p.lhs]){ nullable[p.lhs]=true; changed=true; }
        }
    }
    bool ch=true;
    while(ch){
        ch=false;
        for(auto &nt:nonterminals){
            for(auto &p:grammar) if(p.lhs==nt){
                for(char c:p.rhs){
                    if(!isupper(c)){ firsts[nt].insert(c); break; }
                    for(char f:firsts[c]) firsts[nt].insert(f);
                    if(!nullable[c]) break;
                }
            }
        }
    }
    bool changed2=true;
    while(changed2){
        changed2=false;
        for(auto &p:grammar){
            auto &A=p.lhs;
            for(int i=0;i<p.rhs.size();++i){
                char B=p.rhs[i];
                if(!isupper(B)){ if(!firsts[A].count(B)){ firsts[A].insert(B); changed2=true;} break; }
                for(char f:firsts[B]) if(!firsts[A].count(f)){ firsts[A].insert(f); changed2=true; }
                if(!nullable[B]) break;
            }
        }
    }
}

void computeFollow(){
    char start=grammar[0].lhs;
    follows[start].insert('$');
    bool changed=true;
    while(changed){
        changed=false;
        for(auto &p:grammar){
            for(int i=0;i<p.rhs.size();++i){
                char B=p.rhs[i];
                if(!isupper(B)) continue;
                bool allNullable=true;
                for(int j=i+1;j<p.rhs.size();++j){
                    char X=p.rhs[j];
                    if(!isupper(X)){ if(!follows[B].count(X)){ follows[B].insert(X); changed=true;} allNullable=false; break;}
                    for(char f:firsts[X]) if(!follows[B].count(f)){ follows[B].insert(f); changed=true;}
                    if(!nullable[X]) { allNullable=false; break;}
                }
                if(allNullable){
                    for(char f:follows[p.lhs]) if(!follows[B].count(f)){ follows[B].insert(f); changed=true; }
                }
            }
        }
    }
}

int main(){
    grammar.clear();
    grammar.push_back({'Z',"S"});
    grammar.push_back({'S',"AA"});
    grammar.push_back({'A',"aA"});
    grammar.push_back({'A',"b"});

    terminals.clear(); nonterminals.clear();
    for(auto &p:grammar) nonterminals.insert(p.lhs);
    for(auto &p:grammar) for(char c:p.rhs) if(!isupper(c)) terminals.insert(c);
    terminals.insert('$');

    for(char nt:nonterminals){ firsts[nt]; follows[nt]; nullable[nt]=false; }

    computeNullableFirst();
    computeFollow();

    vector<set<Item>> C;
    set<Item> start; start.insert(Item(0,0));
    C.push_back(closure(start));
    map<pair<int,char>,int> trans;
    bool changed=true;
    while(changed){
        changed=false;
        for(int i=0;i<C.size();++i){
            set<char> symbols;
            for(auto it:C[i]){
                int p=it.p,d=it.d;
                if(d<grammar[p].rhs.size()) symbols.insert(grammar[p].rhs[d]);
            }
            for(char X:symbols){
                set<Item> J=GOTO(C[i],X);
                if(J.empty()) continue;
                int idx=indexOf(C,J);
                if(idx==-1){ C.push_back(J); idx=C.size()-1; changed=true; }
                trans[{i,X}]=idx;
            }
        }
    }

    struct Act{string t; int v; int prod;};
    map<pair<int,char>,Act> action;
    map<pair<int,char>,int> gotoTable;

    for(int i=0;i<C.size();++i){
        for(auto it:C[i]){
            int p=it.p,d=it.d;
            if(d<grammar[p].rhs.size()){
                char a=grammar[p].rhs[d];
                if(!isupper(a)){
                    int j=trans[{i,a}];
                    action[{i,a}]={"s",j,-1};
                } else {
                    int j=trans[{i,a}];
                    gotoTable[{i,a}]=j;
                }
            } else {
                if(grammar[p].lhs=='Z'){
                    action[{i,'$'}]={"acc",0,-1};
                } else {
                    for(char a: follows[grammar[p].lhs]){
                        if(action.find({i,a})==action.end()) action[{i,a}]={"r",0,p};
                    }
                }
            }
        }
    }

    auto parse=[&](string s){
        s.push_back('$');
        vector<int> st; st.push_back(0);
        int ip=0;
        while(true){
            int state=st.back();
            char a=s[ip];
            if(action.find({state,a})==action.end()){ cout<<"Error at symbol "<<a<<"\n"; return; }
            Act A=action[{state,a}];
            if(A.t=="s"){ st.push_back(A.v); ip++; }
            else if(A.t=="r"){
                Prod pr=grammar[A.prod];
                int popn=pr.rhs.size();
                while(popn--) st.pop_back();
                int t=st.back();
                int g=gotoTable[{t,pr.lhs}];
                st.push_back(g);
                cout<<"Reduce by "<<pr.lhs<<" -> "<<pr.rhs<<"\n";
            } else if(A.t=="acc"){ cout<<"String accepted!\n"; return; }
        }
    };

    cout<<"Productions:\n";
    for(int i=0;i<grammar.size();++i) cout<<i<<": "<<grammar[i].lhs<<" -> "<<grammar[i].rhs<<"\n";

    cout<<"\nParsing string: aab\n"; parse("aab");
    cout<<"\nParsing string: ab\n"; parse("ab");
    cout<<"\nParsing string: b\n"; parse("b");
    cout<<"\nParsing string: bb\n"; parse("bb");
    cout<<"2023IMT-025 BRIJESH SINGH";
    
    return 0;
}
