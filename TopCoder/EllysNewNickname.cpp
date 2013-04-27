// Problem Statement
// Elly recently learned that vowels (the letters 'a', 'e', 'i', 'o', 'u' and 'y') are no longer cool
// on the internet. That's why now she wants to remove some of the vowels in the nickname she uses.
// Elly wants her new nickname to contain no consecutive vowels, but she still wants to keep as
// many characters as possible.  You are given the current nickname Elly uses in the string nickname.
// Return its new length after it gets shortened.
// Definition
// Class:
// EllysNewNickname
// Method:
// getLength
// Parameters:
// string
// Returns:
// int
// Method signature:
// int getLength(string nickname)
// (be sure your method is public)
// Notes
// Note that no matter which vowels Elly decides to remove, the length of the resulting nickname will be the same.
// In Elly's language (and in this problem) 'y' is considered a vowel.

// Constraints
// nickname will contain between 1 and 50 characters, inclusive.
// nickname will contain only small letters of the English alphabet ('a'-'z').

// Examples
// 0)
// "tourist"
// Returns: 6
// The nickname "tourist" can become either "turist" or "torist". Its new length will be 6 characters.
// 1)
// "eagaeoppooaaa"
// Returns: 6
// Although there are many possible resulting nicknames, her strategy guarantees that the length of
// all of them will be 6. One of the possibilities in this case is "ageppo".
// 2)
// "esprit"
// Returns: 6
// There are cases in which the nickname remains the same.
// 3)
// "ayayayayayaya"
// Returns: 1
// The initial nickname can contain only vowels or only consonants.
// 4)
// "wuuut"
// Returns: 3
// 5)
// "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan"
// Returns: 16



#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

class EllysNewNickname
{
public:
    int getLength(string nickname) {
        bool temp = false;
        int length = nickname.size();
        for (string::iterator iter = nickname.begin(); iter != nickname.end(); ++iter) {
            if (*iter == 'a' || *iter == 'e' || *iter == 'i' || *iter == 'o' || *iter == 'u' || *iter == 'y') {
                if (temp) {
                    --length;
                }
                else
                    temp = true;
            }
            else {
                temp =false;
            }
        }
        return length;
    }
private:
};