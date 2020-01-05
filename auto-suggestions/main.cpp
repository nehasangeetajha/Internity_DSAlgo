#include"auto-complete.h"

int main()
{
    TrieNode * trietree = getNode();
 char filename[100] = "dictionary.txt";
	ifstream infile;
	infile.open(filename);
if(!infile.is_open()){
    cout<<"Some problem in opening the file!"<<endl;
	exit(EXIT_FAILURE);
}
char word[50];
infile>>word;
while(infile.good()){

	 insert(trietree,word);
	infile>>word;
}

vector <char> ch;
//dictionary *d;
cout<<"enter the initials of word:"<<endl;
cin>>word;
TrieNode* temp=search(trietree,word);
if(temp==NULL)
    cout<<"No words found with this prefix in the dictionary "<<endl;
else
{
    cout<<"Words found in dictionary:"<<endl;
    cout<<word<<endl;
    autocomplete(temp,ch,word);
}
}
