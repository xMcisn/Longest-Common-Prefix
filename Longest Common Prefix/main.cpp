// Markus Cisneros 7/17/2022 Find Longest Common Prefix Example Code main.cpp
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
    vector<string> mainStrings = {"flower", "flown", "floors", "float"}; 

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

    string tempLongest = "";
    string longestPrefixInCommon = "";
    bool common = true;

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
                if((i > 0) && (j == 0) && (vStrings[i][j] != tempLongest[j]))
                {
                    longestPrefixInCommon = "";
                    common = false;
                }
                else if((vStrings[i][j] == tempLongest[j]) && (common == 1))
                {
                    longestPrefixInCommon += tempLongest[j];
                }
            }
        }
        if((tempLongest.length() > longestPrefixInCommon.length()) && (i > 0))
        {
            tempLongest = longestPrefixInCommon;
        }
    }

    if(longestPrefixInCommon != "" && common != false)
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