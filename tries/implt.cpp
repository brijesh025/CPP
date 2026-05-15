#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch){return links[ch-'a'] != NULL;}
    void put(char ch, Node* node){links[ch-'a'] = node;}
    Node* get(char ch){return links[ch-'a'];}
    void increasePrefix(){cntPrefix++;}
    void reducePrefix(){cntPrefix--;}
    void increaseEnd(){cntEndWith++;}
    void deleteEnd(){cntEndWith--;}
};

class trie{
public:

    Node* root;
    trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int cntWord(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i]))return 0;
            node = node->get(word[i]);
        }
        return node->cntEndWith;
    }

    bool search(string word){
        return cntWord(word) > 0;
    }

    void eraseWord(string word){
        if(!search(word)) return;
        Node* node = root;
        for(int i=0;i<word.length();i++){
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

int main() {

    trie newTrie;

    newTrie.insert("brijesh");
    newTrie.insert("brijesh");
    newTrie.insert("brijesh");
    newTrie.insert("brij");
    newTrie.insert("brij");

    cout << newTrie.cntWord("brijesh") << endl;

    newTrie.eraseWord("brijesh");
    
    cout << newTrie.cntWord("brijesh") << endl;
    newTrie.eraseWord("brijesh");
    newTrie.eraseWord("brijesh");
    cout<< newTrie.cntWord("brij")<<endl;
    cout<< newTrie.cntWord("brije")<<endl;

    return 0;
}