#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string irrellevant = " /t";
const string inc = "#include";
bool isIncludeStatement(const string& s) {
	int i;
	for (i = 0; i < s.size() && irrellevant.find(s[i]) < irrellevant.size(); ++i);
	if (s.size()-i < inc.size())
		return false;
	return inc == s.substr(i,inc.size());
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
