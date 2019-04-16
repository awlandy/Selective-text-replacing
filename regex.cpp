#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	ofstream outFile("replaced.txt", fstream::out);
	ifstream readFile("contact.vcf");
	string readout;
	smatch match;
	regex re("^N:(.*)");
	string replace("N:daddy_");

	while (!readFile.eof())
	{
		while (getline(readFile, readout))
		{
			regex_match(readout, match, re);
			if(match.size() > 1 ){
			outFile << replace << match.str(1) << "\n";
			}
			else
			{
				outFile << readout << "\n";
			}
		}
	}
	outFile.close();
	readFile.close();
}