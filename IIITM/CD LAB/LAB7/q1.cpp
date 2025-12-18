#include <bits/stdc++.h>
using namespace std;

struct Production {
    string lhs;
    vector<string> rhs;
};

struct Item {
    string lhs;
    vector<string> rhs;
    int dot;
    bool operator<(const Item&o)const{
        if(lhs!=o.lhs)return lhs<o.lhs;
        if(rhs!=o.rhs)return rhs<o.rhs;
        return dot<o.dot;
    }
    bool operator==(const Item&o)const{
        return lhs==o.lhs&&rhs==o.rhs&&dot==o.dot;
    }
};

vector<Production> prods = {
    {"S'",{"S"}},
    {"S",{"L","=","R"}},
    {"S",{"R"}},
    {"L",{"*","R"}},
    {"L",{"id"}},
    {"R",{"L"}}
};

set<string> nonTerminals = {"S'","S","L","R"};
set<string> terminals = {"id","*","=","$"};

set<Item> closure(set<Item> I){
    bool changed=true;
    while(changed){
        changed=false;
        set<Item> add;
        for(auto &it:I){
            if(it.dot<it.rhs.size()){
                string sym=it.rhs[it.dot];
                if(nonTerminals.count(sym)){
                    for(auto &p:prods){
                        if(p.lhs==sym){
                            Item ni={p.lhs,p.rhs,0};
                            if(!I.count(ni))add.insert(ni);
                        }
                    }
                }
            }
        }
        for(auto &x:add){
            if(!I.count(x)){
                I.insert(x);
                changed=true;
            }
        }
    }
    return I;
}

set<Item> goTo(set<Item>I,string X){
    set<Item>J;
    for(auto &it:I){
        if(it.dot<it.rhs.size() && it.rhs[it.dot]==X){
            Item n=it;
            n.dot++;
            J.insert(n);
        }
    }
    return closure(J);
}

vector<set<Item>> C;
map<pair<int,string>,int> transitions;

void buildLR0(){
    set<Item> I0=closure({{"S'",{"S"},0}});
    C.push_back(I0);
    bool added=true;
    while(added){
        added=false;
        vector<pair<int,string>> moves;
        for(int i=0;i<C.size();i++){
            set<string> symbols;
            for(auto &it:C[i]){
                if(it.dot<it.rhs.size())symbols.insert(it.rhs[it.dot]);
            }
            for(auto &X:symbols){
                set<Item>J=goTo(C[i],X);
                if(J.empty())continue;
                bool found=false;
                for(int k=0;k<C.size();k++){
                    if(C[k]==J){transitions[{i,X}]=k;found=true;break;}
                }
                if(!found){
                    transitions[{i,X}]=C.size();
                    C.push_back(J);
                    added=true;
                }
            }
        }
    }
}

map<string,set<string>> FIRST, FOLLOW;

set<string> first(const vector<string>&alpha){
    set<string>ans;
    if(alpha.empty()){ans.insert("ε");return ans;}
    string X=alpha[0];
    if(terminals.count(X))ans.insert(X);
    else{
        for(auto &f:FIRST[X])ans.insert(f);
    }
    return ans;
}

void computeFirstFollow(){
    for(auto &nt:nonTerminals)FIRST[nt];
    for(auto &t:terminals)FIRST[t].insert(t);
    bool changed=true;
    while(changed){
        changed=false;
        for(auto &p:prods){
            set<string>fs=first(p.rhs);
            for(auto &x:fs){
                if(!FIRST[p.lhs].count(x)){
                    FIRST[p.lhs].insert(x);
                    changed=true;
                }
            }
        }
    }
    FOLLOW["S'"].insert("$");
    changed=true;
    while(changed){
        changed=false;
        for(auto &p:prods){
            for(int i=0;i<p.rhs.size();i++){
                string B=p.rhs[i];
                if(nonTerminals.count(B)){
                    vector<string>beta;
                    for(int j=i+1;j<p.rhs.size();j++)beta.push_back(p.rhs[j]);
                    set<string>fb=first(beta);
                    bool eps=false;
                    for(auto &x:fb){
                        if(x!="ε"&&!FOLLOW[B].count(x)){
                            FOLLOW[B].insert(x);
                            changed=true;
                        }
                        if(x=="ε")eps=true;
                    }
                    if(beta.empty()||eps){
                        for(auto &x:FOLLOW[p.lhs]){
                            if(!FOLLOW[B].count(x)){
                                FOLLOW[B].insert(x);
                                changed=true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void buildTables(){
    buildLR0();
    computeFirstFollow();
    cout<<"Total LR(0) States: "<<C.size()<<"\n\n";
    for (int i = 0; i < C.size(); i++)
    {
        cout << "I" << i << ":\n";
        for (auto &it : C[i])
        {
            cout << "  " << it.lhs << " -> ";
            for (int j = 0; j < it.rhs.size(); j++)
            {
                if (j == it.dot)
                    cout << ".";
                cout << it.rhs[j];
            }
            if (it.dot == it.rhs.size())
                cout << ".";
            cout << "\n";
        }

        cout<<"\n";
    }

    cout<<"LR(0) Parsing Table (Simplified View):\n";
    cout<<"State\tAction(id,*,=,$)\tGOTO(S,L,R)\n";
    map<int,string>conf;
    for(int i=0;i<C.size();i++){
        string act="",gt="";
        map<string,string>A;
        for(auto &t:terminals){
            if(transitions.count({i,t}))A[t]="s"+to_string(transitions[{i,t}]);
        }
        for(auto &it:C[i]){
            if(it.dot==it.rhs.size()){
                int pno=-1;
                for(int j=0;j<prods.size();j++)
                    if(prods[j].lhs==it.lhs&&prods[j].rhs==it.rhs)pno=j;
                if(it.lhs=="S'")A["$"]="acc";
                else for(auto &t:terminals)A[t]+="r"+to_string(pno);
            }
        }
        for(auto &t:terminals)act+=A[t]+"\t";
        for(auto &nt:nonTerminals){
            if(nt=="S'")continue;
            if(transitions.count({i,nt}))gt+=to_string(transitions[{i,nt}])+"\t";
            else gt+="\t";
        }
        cout<<i<<"\t"<<act<<"\t"<<gt<<"\n";
        for(auto &t:terminals)if(A[t].size()>2)conf[i]="Conflict!";
    }

    cout<<"\nConflicted LR(0) States: ";
    for(auto &x:conf)cout<<x.first<<" ";
    if(conf.empty())cout<<"None";
    cout<<"\n\nSLR(1) Conflict Resolution Check:\n";
    for(auto &x:conf){
        cout<<"State "<<x.first<<" conflicts due to overlapping shift/reduce.\n";
        cout<<"FOLLOW sets used for restriction (SLR(1)):\n";
        for(auto &p:FOLLOW){
            cout<<"FOLLOW("<<p.first<<")={";
            for(auto &s:p.second)cout<<s<<",";
            cout<<"}\n";
        }
        cout<<"Even after SLR(1), '='∈FOLLOW(R) hence conflict remains.\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    buildTables();
    cout<<"2023IMT-025 BRIJESH SINGH";
    return 0;
}
