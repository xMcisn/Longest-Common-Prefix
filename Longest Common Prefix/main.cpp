// Markus Cisneros 7/21/2022 Find Longest Common Prefix Example Code main.cpp
/* Functionality: create a vector of strings, pass vector by reference to longestCommonPrefix.
 * Certain conditions must be met; vector size must be non-zero and greater than or 1 but less than or equal 200,
 * all strings must be made up of lowercase letters, and range anywhere from 0 - 200 characters long.
 * If above conditions are met, then print out the resulting longest common prefix between strings
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &vStrings);
bool stringIsLowerCase(string monitoredString);

int main()
{
    // vector<string> mainStrings = {"aac", "cab", "abb"}; 
    // vector<string> mainStrings = {"aaa", "aa", "aaa"}; 
    // vector<string> mainStrings = {"flower", "flow", "fly", "flush", "fryler", "f"}; 
    // vector<string> mainStrings = {"baab", "bacb", "b", "cbc"}; 
    vector<string> mainStrings = {"cir", "car"}; 


    string longCommonPre = longestCommonPrefix(mainStrings);

    if(longCommonPre != "")
    {
        cout << longCommonPre << endl;
    }

    return 0;
}

string longestCommonPrefix(vector<string> &vStrings)
{
    if(vStrings.size() < 1 || vStrings.size() > 200) { return ""; }
    
    if(vStrings.size() == 1)
    {
        return vStrings[0];
    }

    string tempLongest = "";
    string longestPrefixInCommon = "";

    for (int i = 0; i < vStrings.size(); i++)
    {
        if(!stringIsLowerCase(vStrings[i]) || ((vStrings[i].length() < 0) || (vStrings[i].length() > 200))) { return ""; }

        longestPrefixInCommon = "";
        for (int j = 0; j < vStrings[i].length(); j++)
        {
            if(i == 0)
            {
                tempLongest = vStrings[i];
                break;
            }
            else
            {
                if((j == 0) && (vStrings[i][j] != tempLongest[j]))
                {
                    return "";
                }
                else if(vStrings[i][j] == tempLongest[j])
                {
                    longestPrefixInCommon += tempLongest[j];
                }
                else if((vStrings[i][j] != tempLongest[j]) && (i == vStrings.size() - 1))
                {
                    return longestPrefixInCommon;
                }
            }
        }
        if(tempLongest.length() > longestPrefixInCommon.length() && (i > 0))
        {
            tempLongest = longestPrefixInCommon;
        }
    }

    if(longestPrefixInCommon != "")
    {
        return longestPrefixInCommon;
    }
    else
    {
        return "";
    }
}

bool stringIsLowerCase(string monitoredString)
{
    for (int i = 0; i < monitoredString.length(); i++)
    {
        if(monitoredString[i] < 'a' || monitoredString[i] > 'z')
        {
            return false;
        }
    }
    return true;
}