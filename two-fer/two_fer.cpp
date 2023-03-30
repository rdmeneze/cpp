#include "two_fer.h"
#include <sstream>
#include <iostream>
#include <algorithm>

std::string& ltrim(std::string &s)
{
    auto it = std::find_if(s.begin(), s.end(),
                           [](char c) {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(s.begin(), it);
    return s;
}

std::string& rtrim(std::string &s)
{
    auto it = std::find_if(s.rbegin(), s.rend(),
                           [](char c) {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(it.base(), s.end());
    return s;
}

std::string& trim(std::string &s) {
    return ltrim(rtrim(s));
}



namespace two_fer
{
std::string two_fer(const std::string name)
{
    std::string sResultName = name;
    trim(sResultName);

    std::cout << sResultName.length() << "\n";

    if(!sResultName.length())
    {
        sResultName = "you";
    }

    std::stringstream ss;

    ss << "One for ";
    ss << sResultName;
    ss << ", one for me.";

    return ss.str();
}

} // namespace two_fer

