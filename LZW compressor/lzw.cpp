#include<bits/stdc++.h>
using namespace std;

vector<int> encoding(string s1)
{
	cout << "Encoding\n";
	unordered_map<string, int> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string p = "", c = "";
	p += s1[0];
	int code = 256;
	vector<int> output_code;
	cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < s1.length(); i++) {
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << endl;
			output_code.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	cout << p << "\t" << table[p] << endl;
	output_code.push_back(table[p]);
	return output_code;
}

int main()
{
    string line;
    string s;

  fstream myfile ("example.txt",ios::out|ios::in);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      s+=line;
    }
    myfile.close();
  }
  fstream myFile("code.txt",ios::in|ios::out);

  vector<int>output_code = encoding(s);
  for(int i = 0;i<output_code.size();i++)
  {
      int temp = output_code[i];
      myFile<<temp<<" ";
  }
  myFile <<endl;
  myFile.close();


}
