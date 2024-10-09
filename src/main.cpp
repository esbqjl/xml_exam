#include "../include/xml_exam.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	// Check if an argument is passed
	if (argc < 2) {
		cout << "Usage: XML_exam.exe <XML string>" << endl;
		return 1;
	}

	// Concatenate all command-line arguments into a single string (since XML may contain spaces)
	string xmlInput;
	for (int i = 1; i < argc; ++i) {
		xmlInput += argv[i];
		if (i != argc - 1) {
			xmlInput += " "; // Add space between arguments
		}
	}

	// Validate the XML string
	bool isValid = examXml(xmlInput);
	cout << (isValid ? "Valid XML" : "Invalid XML") << endl;

	return 0;
}