#include <iostream>
#include <fstream>
#include "./miscFiles/include/int_double.h"
#include <string>
#include <sstream>

using namespace std;

int main(int N, char* arg[]) {
	if (N != 2) {
		cout << "usage:\n   " << arg[0] << " filename" << endl;
	}
	ifstream in;
	in.open(arg[1]);
	int_double sum = 0.0;
	string line;
	//int where = 1;
	while (getline(in, line)) {
		for (int i = 0; i < line.size(); ++i) {
			switch  (line[i]) {
				case '[':
				case ',':
				case ']':
				line[i] = ' ';
				default:
				break;
			}
		}
		double q, w, e, r, t, low, high;
		istringstream iss{line};
		iss >> q >> w >> e >> r >> t >> low >> high;
		//cout << where++ << ' ';
		sum += int_double{low, high};
		cout << q << ',' << w << ',' << e << ',' << r << ',' << t << ',';
		print_int_double(sum);
		cout << endl;
	}
	return 0;
}
