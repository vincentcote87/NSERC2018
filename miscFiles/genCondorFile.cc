#include <iostream>
#include <fstream>
#include <primesieve.hpp>

using namespace std;

int main() {
   string exeName;
   ofstream condorFile;
   uint64_t start = 0;
   uint64_t stop = 10;
   uint64_t range = 10000000000;
   uint64_t temp = 0;

   cout<<"Enter the name of the executable program: ";
   cin>>exeName;
   cout<<"Enter the starting value: ";
   cin>>start;
   cout<<"Enter the end value: ";
   cin>>stop;

   cout<<"Your job will run "<<exeName<<" from "<<start<<" to "<<stop<<" with intervals of "<<range<<endl;

   condorFile.open("run.condor");
   condorFile << "Executable = " <<exeName<<endl<<endl;
   for(uint64_t i = start; i < stop; i += range) {
      temp = i;
      condorFile<<"Arguments = "<<i<<" "<<i + range<<endl;
      condorFile<<"Log = ct.log"<<endl;
      condorFile<<"Output = ./output/o.";
      while(temp < stop) {
	 if(temp == 0)
	    temp = 1;
	 condorFile<<0;
	 temp *= 10;
      }
      condorFile<<i<<"_"<<i+range<<endl;
      condorFile<<"Queue"<<endl<<endl;
   }
}
