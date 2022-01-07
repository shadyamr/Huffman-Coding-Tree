#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "HCTree.h"
using namespace std;
void line_table()
{
    for (int i = 0; i < 30; i++)
        cout << "-";
}
void double_endl()
{
    std::cout << endl << endl;
}
int main()
{
    HCTree h;
    string str, encodedString, decodedString, 
        sen = "[*] ENTER SENTENCE: ",
        charfreq = "[*] CHARACTER & FREQUENCIES:",
        encodemsg = "[*] ENCODED DATA: ",
        decodemsg = "[*] DECODED DATA: ";

    cout << sen;
    getline(cin, str);
    cout << endl;

    h.calcFreq(str, str.length());
    h.HuffmanCodes(str.length());

    cout << charfreq << endl;
    line_table();
    cout << endl;
    for (auto v = h.codes.begin(); v != h.codes.end(); v++)
    {
        cout << v->first << ' ' << v->second << endl;
    }

    for (auto i : str)
    {
        encodedString += h.codes[i];
    }
    line_table();
    double_endl();

    cout << encodemsg << encodedString << endl << endl;
    decodedString = h.decode(encodedString);
    cout << decodemsg << decodedString << endl;
}