#include "matching_brackets.h"
#include <cstdint>

#include <stack>
#include <map>

bool matching_brackets::check(const std::string s)
{
    std::stack<char> parse;
    const std::map<char, char> pair_brackets {{'}','{'},
                                              {')','('},
                                              {']','['},};

    for(auto &c : s)
    {
        bool resume_loop = false;
        switch(c)
        {
            case '(':
            case '[':
            case '{':
            {
                parse.push(c);
                break;
            }

            case ')':
            case ']':
            case '}':
            {
                if(parse.size())
                {
                    if(pair_brackets.find(c)->second == parse.top())
                        parse.pop();
                    else
                        resume_loop = true;
                }
                break;
            }

            default:
                break;
        }

        if(resume_loop)
            break;
    }

    return (parse.empty());
}
