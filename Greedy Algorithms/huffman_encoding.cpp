#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct Node
{
    char character;
    int frequency;

    Node* left;
    Node* right;


    Node(char c, int f)
    {
        character = c;
        frequency = f;

        left = NULL;
        right = NULL;
    }
};


// Compare nodes based on frequency
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->frequency > b->frequency;
    }
};


// Generate Huffman codes
void generateCode(Node* root, string code)
{
    if(root == NULL)
    {
        return;
    }


    // Leaf node
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->character
             << " : "
             << code
             << endl;
    }


    generateCode(root->left, code + "0");

    generateCode(root->right, code + "1");
}



int main()
{
    int n;

    cin >> n;


    priority_queue<
        Node*,
        vector<Node*>,
        Compare
    > minHeap;



    // Taking character and frequency
    for(int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        cin >> ch >> freq;


        minHeap.push(
            new Node(ch, freq)
        );
    }



    // Build Huffman Tree
    while(minHeap.size() > 1)
    {
        Node* left = minHeap.top();

        minHeap.pop();


        Node* right = minHeap.top();

        minHeap.pop();



        Node* newNode = new Node(
            '$',
            left->frequency + right->frequency
        );


        newNode->left = left;

        newNode->right = right;



        minHeap.push(newNode);
    }



    Node* root = minHeap.top();



    cout << "Huffman Codes:" << endl;


    generateCode(root, "");


    return 0;
}
