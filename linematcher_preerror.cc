#include <iostream>
#include <fstream>
#include "./miscFiles/include/int_double.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Entry {
	uint64_t milliseconds, start, stop, first, last;
	int_double theta;
	void print() const {
		cout << milliseconds << ',' << start << ',' << stop << ',' << first << ',' << last << ',';
		print_int_double(theta);
	}
	void println() const {
		print();
		cout << '\n';
	}
	void printendl() const {
		print();
		cout << endl;
	}
};

vector<Entry> data;

void interpret(const char* source) {
	data.clear();
	ifstream in;
    in.open(source);
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
            Entry e;
            double low, high;
            istringstream iss{line};
            iss >> e.milliseconds >> e.start >> e.stop >> e.first >> e.last \
            	>> low >> high;
            e.theta = int_double{low, high};
            data.push_back(e);
    }
}

bool cleanup(vector<Entry>& result, const vector<Entry>& data) {
	result.clear();
	if (data.empty())
		return true;
	result.push_back(data[0]);
	uint64_t lastmatch = data[0].stop;
	for (int i = 1; i < data.size(); ++i) {
		if (data[i].start > lastmatch) {
			//We can ignore this, if the rest of the file doesn't work we lose the entire list.
		} else if (data[i].start == lastmatch) {
			result.push_back(data[i]);
			lastmatch = data[i].stop;
		} else {
			//We can ignore this, if the rest of the file doesn't work we lose the entire list.
		}
	}
	return true;
}

void print(const vector<Entry>& a) {
	for (int i = 0; i < a.size(); ++i) {
		a[i].printendl();
	}
}

int main(int N, char* arg[]) {
	if (N != 2) {
		    cout << "usage:\n   " << arg[0] << " filename" << endl;
		    return 0;
	}
	interpret(arg[1]);
	vector<Entry> smooth;
	cleanup(smooth, data);
	print(smooth);
	return 0;
}

