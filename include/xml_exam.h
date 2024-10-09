#ifndef XML_EXAM_H
#define XML_EXAM_H

#include <string>
// get rid of spaces in head and tail of a string
std::string simpleTrim(const std::string& str);
// to verify whther if the tag name is valid or not
bool isValidTagName(const std::string& tag);
// main method to verify the xml string is valid or not
bool examXml(const std::string& xml);

#endif XML_EXAM_H