#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string irrellevant = " /t";
const int inc_size = 2;
const string inc[inc_size] = {"cout", "std::cout"};
bool isIncludeStatement(const string& s) {
	int minSize = inc[0].size();
	for (int i = 1; i < inc_size; ++i) {
		minSize = std::min(minSize, (int) inc[i].size());
	}
	int i;
	for (i = 0; i < s.size() && irrellevant.find(s[i]) < irrellevant.size(); ++i);
		if (s.size()-i < minSize)
				return false;
	for (int word = 0; word < inc_size; ++word) {
	    if (inc[word].size() > s.size() - i)
	        continue;
		if (inc[word] == s.substr(i,inc[word].size()))
			return true;
	}
	return false;
}

int main(int argN, char* arg[]) {
	if (argN < 2) {
		std::cout << "usage: process file file ...." << std::endl;
		return 0;
	}
	for (int w = 1; w < argN; ++w) {
		ifstream in;
		in.open(arg[w]);
		std::vector<std::string> file;
		string line;
		while (getline(in, line)) {
			file.push_back(line);
		}
		in.close();
		ofstream out;
		out.open(arg[w]);
		int i;
		for (i=0; i <file.size()/2; ++i) {
			out << file[i] << '\n';
		}
		for (; i < file.size(); ++i) {
			if (!isIncludeStatement(file[i]))
				out << file[i] << endl;
		}
	}
	return 0;
}
