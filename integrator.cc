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
	int_double error = 0.0;
	int_double y, oldSum;
	uint64_t from = -1;
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
		uint64_t q, w, e, r, t;
		double low, high;
		istringstream iss{line};
		iss >> q >> w >> e >> r >> t >> low >> high;
		//cout << where++ << ' ';
		
		oldSum = sum;
		y = int_double{low, high} + error;
		sum = oldSum + y;
		error = (oldSum - sum) + y;
		
		if (from == -1)
			from = w;
		cout << q << ',' << from << ',' << e << ',' << r << ',' << t << ',';
		print_int_double(sum);
		cout << endl;
	}
	return 0;
}
