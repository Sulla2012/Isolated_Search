// system include files
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::float> parse2(std::istream& in)
{
	std::vector<std::float> output;
    std::float num;
    while( in ) {
        std::cin >> num;  // throwaway 1
        std::cin >> num;  // data2
        output.push_back(num);
    }
    return output;
}

std::vector<std::int> parse1(std::istream& in)
{
	std::vector<std::int> output;
    std::int num;
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
  using namespace boost;
  
  parse(std::cin);
	std::ifstream file("scoutinglumi.tsv");
	
	//initialize vectors which will hold the run number and run luminosity.
	std::vector<std::int> runs;
	std::vector<std::float> runlumi;
	
	runs = parse1(file);
	runlumi = parse2(file);
	
	//get the run number. This is some magic function defined in one of the libraries we're using, set to some number to run
	runNumber = iEvent.id().run();
	
	// Set the cuttoff Luminosity for the run
	std::int lumiCutoff;
	lumiCutoff = 100000;
	
	//find the interator corresponding to the run number
	std::int runtag;
	runtag = find(runs.begin(),runs.end(), runNumber);
	
	std::float luminosity;
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
  

