#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "HCTree.h"
using namespace std;

void HCTree::printCodes(New_Node* root, string str)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << ": " << str << "\n";
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HCTree::storeCodes(New_Node* root, string str)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data != '$')
    {
        codes[root->data] = str;
    }
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

struct compare
{
    bool operator()(HCTree::New_Node* l, HCTree::New_Node* r)
    {
        return (l->freq > r->freq);
    }
};

priority_queue<HCTree::New_Node*, vector<HCTree::New_Node*>, compare> minHeap;
void HCTree::HuffmanCodes(int size)
{
    struct New_Node* left, * right, * top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
    {
        minHeap.push(new New_Node(v->first, v->second));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new New_Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

string HCTree::decode(string s)
{
    string ans = "";
    struct New_Node* root = minHeap.top();
    struct New_Node* curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        if (curr->left == NULL and curr->right == NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans + '\0';
}

void HCTree::calcFreq(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }
}