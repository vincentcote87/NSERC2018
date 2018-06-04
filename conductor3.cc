#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


#include <deque>
#include <queue>
#include <vector>
#include <utility>

#include <tuple>

#include <thread>
#include <atomic>
#include <chrono>

#include <string>
#include <fstream>
#include <cstdlib>

typedef long long integer;
typedef long double rational;

const int THREADS = 10;
std::atomic<bool> done[THREADS];

void processRegion (integer n, integer start, integer stop, integer gap, integer me) {
   const std::string command = std::string("./miscFiles/theta_int_double2 ") + std::to_string(start) + std::string(" ") + std::to_string(stop) + std::string{" "} + std::to_string(gap) + std::string(" &> ./out3/") + std::to_string(n);
   std::cout << command << std::endl;
   std::system(command.c_str());
   done[me] = true;
}

const integer numberOfGaps = 10;
const integer gap = 10000000000000;
const integer recordEvery = 1000000000000;

/*
std::pair<integer, std::pair<integer, integer>> jobDescription(const integer id, const integer start, const integer stop) {
   return std::make_pair(id, std::make_pair(start, stop));
   }
*/

void startJob(std::vector<std::thread>& thr, std::queue<std::tuple<integer, integer, integer, integer>>& job) {
   std::cout << "\nAnother call to startJob()\n";
   for (size_t i = 0; !job.empty() && i < thr.size(); ++i) {
      std::cout << "thread i " << i <<  std::endl;
      if (done[i]) {
	 std::cout << "yes";
	 done[i] = false;
	 if (thr[i].joinable())
	    thr[i].join();
	 thr[i] = std::thread(processRegion, std::get<0>(job.front()), std::get<1>(job.front()), std::get<2>(job.front()), std::get<3>(job.front()), i);
	 job.pop();
	 
      }
      std::cout << ".ok" << std::endl;
   }
}

void resetDone() {
   for (int i = 0; i < THREADS; ++i) {
      done[i] = true;
   }
}

int main() {
   resetDone();
   std::vector<std::thread> thr;
   thr.resize(THREADS);
   std::queue<std::tuple<integer, integer, integer, integer>> job;
   integer last = 0;
   for (integer id = 0; id < numberOfGaps; ++id) {
      job.push(std::make_tuple(id, last, last + gap, recordEvery));
      last += gap;
      startJob(thr, job);
   }
   std::cout << "Done adding jobs\n";
   int i = 0;
   while (!job.empty()) {
      //std::this_thread::sleep_for(std::chrono::minutes{5});
      startJob(thr, job);
   }
   std::cout << "Joining threads before exiting" << std::endl;
   for (int i = 0; i < thr.size(); ++i) {
      if (thr[i].joinable())
	 thr[i].join();
   }
   std::cout << "About to exit" << std::endl;
   return 0;
}
