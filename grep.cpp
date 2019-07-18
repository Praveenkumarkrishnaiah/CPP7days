#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static bool is_match(string &text, string &pattern){
	return std::string::npos != text.find(pattern);
}


int main(int argc, char const *argv[])
{
	switch(argc){
		case 0: case 1: cerr << "specify the pattern" << endl; 
		return 254;

		case 2: cerr << "specify the filename" << endl;
		return 254;

		case 3: break;

		default: cerr << "not implemented" << endl;
		return 255;
	}

	string pattern(argv[1]);
	string filename(argv[2]);

	ifstream infile(filename);
	ofstream outfile("log.txt");


	string line;
	int lineCount = 0;
	while(infile >> line){
		lineCount++;
		if(is_match(line,pattern)){
			outfile << "Line number: " << lineCount << " " << line << " found at index: " << line.find(pattern) << endl;
		}
	}


	return 0;
}