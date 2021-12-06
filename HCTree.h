#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

class HCTree
{
public:
    map<char, string> codes;
    map<char, int> freq;

    class New_Node {
    public:
        char data;
        int freq;
        New_Node* left;
        New_Node* right;
        New_Node(char character, int frequency)
        {
            data = character;
            freq = frequency;
            left = right = NULL;
        }

    };
    New_Node* top;
    HCTree() { top = NULL; };
    ~HCTree()
    {
        delete top;
    }
    void printCodes(struct New_Node* root, string str);
    void storeCodes(struct New_Node* root, string str);
    void HuffmanCodes(int size);
    string decode(string s);
    void calcFreq(string str, int n);
};