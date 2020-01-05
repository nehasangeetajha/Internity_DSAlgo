#include<bits/stdc++.h>
//#include"dictionary.h"
#include<fstream>
#include<string>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
const int ALPHABET_SIZE =26;
int calc(string s);

class TrieNode
{
    public:
    TrieNode*children[ALPHABET_SIZE];
    bool isEndOfWord;

};

TrieNode*getNode(void)
    {
        TrieNode*pNode = new TrieNode;
        pNode->isEndOfWord = false;

        for(int i = 0;i<ALPHABET_SIZE;i++)
        {
            pNode->children[i] = NULL;
        }
        return pNode;
    }

void insert(TrieNode*root,string key)
{
    TrieNode*pcrawl = root;
    int i;
    for(i=0;i<key.length();i++)
    {
        int index = CHAR_TO_INDEX(key[i]);
        if(!pcrawl -> children[index])
        {
            pcrawl ->children[index] = getNode();
        }
        pcrawl = pcrawl->children[index];
    }
    pcrawl->isEndOfWord = true;
}

TrieNode* search(TrieNode* current,char* word){

while(*word!='\0')
    {
if(current->children[*word-'a']!=NULL)
{
    current=current->children[*word-'a'];
    ++word;
}
else
    break;
}
if(*word=='\0'){
    return current;
}
else
    return NULL;
// look for every character we are searching

}



void autocomplete(TrieNode* trietree, vector <char> word,char* prefix){
    bool nochild=true;
if(trietree->isEndOfWord==true && word.size()!=0){
    cout<<prefix;
    for(int i=0;i<word.size();i++){
        cout<<word[i];
    }
    cout<<endl;

}
for(int i=0;i<ALPHABET_SIZE;i++){
if(trietree->children[i]!=NULL){

    word.push_back(i+'a');
    autocomplete(trietree->children[i],word,prefix);
    word.pop_back();
}
}
word.pop_back();
}
