#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "HCTree.h"
using namespace std;
int main()
{
    HCTree h;
    string str, encodedString, decodedString;
    cout << "Enter a message or sentence." << endl;
    getline(cin, str);

    h.calcFreq(str, str.length());
    h.HuffmanCodes(str.length());

    cout << "Character & Frequencies:\n";
    for (auto v = h.codes.begin(); v != h.codes.end(); v++)
    {
        cout << v->first << ' ' << v->second << endl;
    }

    for (auto i : str)
    {
        encodedString += h.codes[i];
    }

    cout << "\nEncoded Data:\n" << encodedString << endl;

    decodedString = h.decode(encodedString);
    cout << "\nDecoded Data:\n" << decodedString << endl;
}