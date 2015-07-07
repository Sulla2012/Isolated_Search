// system include files
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

vector<float> parse2(std::istream& in)
{
	vector<float> output;
    float num;
    while( in ) {
        std::cin >> num;  // throwaway 1
        std::cin >> num;  // data2
        output.push_back(num);
    }
    return output;
}

vector<int> parse1(std::istream& in)
{
	vector<int> output;
    int num;
    while( in ) {
        std::cin >> num;  // throwaway 1
        output.push_back(num);
        std::cin >> num;  // data2
    }
    return output;
}

int main()
{
  using namespace std;
  //using namespace boost;
  
  
  //parse(std::cin);
  std::ifstream file("scoutinglumi.tsv");
  
  //initialize vectors which will hold the run number and run luminosity.
  vector<int> runs;
  vector<float> runlumi;
	
  //runs = parse1(file);
  //runlumi = parse2(file);
	
  //get the run number. This is some magic function defined in one of the libraries we're using, set to some number to run
  int runNumber;
  runNumber = 193833;
	
  // Set the cuttoff Luminosity for the run
  int lumiCutoff;
  lumiCutoff = 100000;
	
  //find the interator corresponding to the run number
  int runtag;
  runtag = find(runs.begin(),runs.end(), runNumber);
	
  float luminosity;
  luminosity = runlumi.at(runtag);
	
  if(luminosity>lumiCutoff)
  {
	return;
  }
  
  //rest of the code goes here
  
  //just a test output 
  
  cout << "Luminosity for run" << runNumber << "is" << luminosity;
  
  return 0;
}
  

