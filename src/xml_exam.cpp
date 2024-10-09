// xml_exam.cpp : Defines the entry point for the application.
#include "../include/xml_exam.h"
#include <stack>
#include <iostream>
using namespace std;


// We need to make sure both head and end do not have space
string simpleTrim(const string& str) {
	size_t start = 0;
	size_t end = str.length() - 1;

	// Skip leading whitespaces
	while (start < str.length() && isspace(str[start])) {
		start++;
	}

	// Skip trailing whitespaces
	while (end > start && isspace(str[end])) {
		end--;
	}

	// Return the trimmed string
	return str.substr(start, end - start + 1);
}


// Function to check if the tag name is valid
bool isValidTagName(const string& tag) {
	if (tag.empty() || !isalpha(tag[0])) {
		return false; // Tag name must start with a letter, this is only due to current task, we should work better in the future, ex: <?xml>
	}
	for (char ch : tag) {
		if (!isalnum(ch) && !ch == '_') {
			return false; // Tag name can only contain letters, digits, or underscores.
		}
	}
	return true;
}
// Main function to exam each xml
bool examXml(const string& xml) {
	if (xml.empty()) {
		return false;
	}
	//make a trim to xml
	string xml_copy = simpleTrim(xml);
	stack<string> tagStack;
	size_t i = 0;
	while (i < xml_copy.length()) {
		if (xml_copy[i] != '<') {
			if (tagStack.empty()) {
				return false;			// Case: no closing tag
			}
			i++;
			continue;
		}
		size_t tagStart = i + 1;
		bool isClosingTag = (tagStart < xml_copy.length() && xml_copy[tagStart] == '/');	// Check if it's closing tag
		if (isClosingTag) {
			tagStart++;							// If closing tag then we need to move index one behind
		}
		size_t tagEnd = xml_copy.find('>', tagStart);
		if (tagEnd == string::npos) {
			return false;							// Not a complete tag
		}
		string fullTag = xml_copy.substr(tagStart, tagEnd-tagStart);

		if (!isValidTagName(fullTag)) {
			return false;							// Not a valid tag
		}
		if (isClosingTag) {
			if (tagStack.empty() || tagStack.top() != fullTag) {
				return false;						// We didn't find any corresponding tags
			}
			else {
				tagStack.pop();						// Successfully pair, pop
			}
		}
		else {
			tagStack.push(fullTag);					// New Tag, push
		}
		i = tagEnd + 1;
	}
	// If all tags pair successfully, then we return true
	return tagStack.empty();
}


