#include "../include/xml_exam.h"
#include <iostream>
using namespace std;

void runTests() {
    // Test 1: Valid XML
    string test1 = "<tutorial><topic>XML</topic></tutorial>";
    bool expected1 = true;
    cout << "Test 1: " << (examXml(test1) == expected1 ? "Passed" : "Failed") << endl;

    // Test 2: Invalid XML with unmatched string in closing tag
    string test2 = "<tutorial style=\"\"><topic>XML</topic></tutorial stble=\"\">";
    bool expected2 = false;
    cout << "Test 2: " << (examXml(test2) == expected2 ? "Passed" : "Failed") << endl;

    // Test 3: Invalid XML with missing closing tag
    string test3 = "<tutorial><topic>XML</topic>";
    bool expected3 = false;
    cout << "Test 3: " << (examXml(test3) == expected3 ? "Passed" : "Failed") << endl;

    // Test 4: invalid XML with wrong string in tag
    string test4 = "<tutorial <><topic>XML</topic></tutorial>";
    bool expected4 = false;
    cout << "Test 4: " << (examXml(test4) == expected4 ? "Passed" : "Failed") << endl;

    // Test 5: Empty XML string
    string test5 = "";
    bool expected5 = false;
    cout << "Test 5: " << (examXml(test5) == expected5 ? "Passed" : "Failed") << endl;
    
    // Test 6: Valid XML even with space inside the text
    string test6 = "<tutorial><topic>           XML</topic></tutorial>";
    bool expected6 = true;
    cout << "Test 6: " << (examXml(test6) == expected6 ? "Passed" : "Failed") << endl;

    // Test 7: valid XML with matched string in closing tag
    string test7 = "<tutorial style=\"\"><topic>XML</topic></tutorial style=\"\">";
    bool expected7 = true;
    cout << "Test 7: " << (examXml(test7) == expected7 ? "Passed" : "Failed") << endl;

    // Test 8: Valid XML with space in head and back
    string test8 = " <tutorial><topic>           XML</topic></tutorial> ";
    bool expected8 = true;
    cout << "Test 8: " << (examXml(test8) == expected6 ? "Passed" : "Failed") << endl;
}   
        
    
    

int main() {
    // run the test
    runTests();
    return 0;
}