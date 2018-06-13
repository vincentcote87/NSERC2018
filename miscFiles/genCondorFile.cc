#include <iostream>
#include <fstream>
#include <string>
#include <primesieve.hpp>

using namespace std;

int main() {
   string exeName;
   ofstream condorFile;
   uint64_t start = 0;
   uint64_t stop = 1000000000000000; //range * stop = target max
   uint64_t range = 1000000000000; //of each run
   uint64_t subrange = 1000000000; //how often to record during the run
   uint64_t temp = 0;
   string outputFolder = "outputJune12";

   cout<<"Enter the name of the executable program: ";
   cin>>exeName;

   cout<<"Your job will run "<<exeName<<" from "<<start<<" to "<<stop<<" iterations, with intervals of "<<range<< " and subintervals of " << subrange <<endl;

   condorFile.open("run.condor");
   condorFile << "Executable = " <<exeName<<endl<<endl;
   for(uint64_t i = start; i < stop; i += range) {
	 temp = i;
	 condorFile<<"Arguments = "<<i<<" "<<i + range<<" "<<subrange<<endl;
	 condorFile<<"Log = ct.log"<<endl;
	 condorFile<<"Output = " << outputFolder << "/o.";
	 while(temp < stop) {
	    if(temp == 0)
	       temp = 1;
	    condorFile<<0;
	    temp *= 10;
	 }
	 condorFile<<i<<"_"<<i+range<<endl;
	 condorFile<<"Queue"<<endl<<endl;
   }
   return 0;
}
