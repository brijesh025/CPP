#include <bits/stdc++.h>
using namespace std;

map<char,vector<string>> prod;
map<char,set<char>> firsts,follows;
set<char> visitedFirst,visitedFollow;
char startSymbol;

void findFirst(char c){
    if(visitedFirst.count(c))return;
    visitedFirst.insert(c);
    for(auto &rule:prod[c]){
        if(rule[0]=='$')firsts[c].insert('$');
        else{
            for(int i=0;i<rule.size();i++){
                char ch=rule[i];
                if(!isupper(ch)){
                    firsts[c].insert(ch);
                    break;
                }
                findFirst(ch);
                bool epsilonPresent=false;
                for(auto x:firsts[ch]){
                    if(x!='$')firsts[c].insert(x);
                    else epsilonPresent=true;
                }
                if(!epsilonPresent)break;
                if(i==rule.size()-1)firsts[c].insert('$');
            }
        }
    }
}

void findFollow(char c){
    if(visitedFollow.count(c))return;
    visitedFollow.insert(c);
    if(c==startSymbol)follows[c].insert('$');
    for(auto &p:prod){
        char lhs=p.first;
        for(auto &rule:p.second){
            for(int i=0;i<rule.size();i++){
                if(rule[i]==c){
                    if(i+1<rule.size()){
                        char next=rule[i+1];
                        if(!isupper(next))follows[c].insert(next);
                        else{
                            for(auto x:firsts[next])
                                if(x!='$')follows[c].insert(x);
                            bool epsilonPresent=firsts[next].count('$');
                            if(epsilonPresent && lhs!=c){
                                findFollow(lhs);
                                for(auto x:follows[lhs])follows[c].insert(x);
                            }
                        }
                    }else if(lhs!=c){
                        findFollow(lhs);
                        for(auto x:follows[lhs])follows[c].insert(x);
                    }
                }
            }
        }
    }
}

int main(){
    ifstream in("input_file.txt");
    ofstream out("output_file.txt");
    string line;
    bool firstLine=true;
    while(getline(in,line)){
        if(line.empty())continue;
        char lhs=line[0];
        if(firstLine){
            startSymbol=lhs;
            firstLine=false;
        }
        string rhs=line.substr(2);
        stringstream ss(rhs);
        string temp;
        while(getline(ss,temp,'|'))prod[lhs].push_back(temp);
    }
    for(auto &p:prod)findFirst(p.first);
    for(auto &p:prod)findFollow(p.first);

    out<<"FIRST sets:\n";
    for(auto &p:firsts){
        out<<p.first<<" = { ";
        for(auto x:p.second)out<<x<<' ';
        out<<"}\n";
    }
    out<<"\nFOLLOW sets:\n";
    for(auto &p:follows){
        out<<p.first<<" = { ";
        for(auto x:p.second)out<<x<<' ';
        out<<"}\n";
    }
    return 0;
}
