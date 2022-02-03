#include <iostream>;
#include <queue>
#include <chrono>  // for high_resolution_clock
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root = NULL;

    void AddNode(int data) {
        Node* tempNode = new Node(data);
        Node* current;
        Node* parent;

        if (root == NULL)
        {
            root = tempNode;
        }
        else
        {
            current = root;
            parent = NULL;

            while (true)
            {
                parent = current;

                if (data < parent->data) {
                    current = current->left;

                    if (current == NULL) {
                        parent->left = tempNode;
                        return;
                    }
                }
                else {
                    current = current->right;

                    if (current == NULL) {
                        parent->right = tempNode;
                        return;
                    }
                }
            }
        }
    }

    Node* Search(int data) {
        if (root == NULL)
        {
            return NULL;
        }

        Node* current = root;

        while (current->data != data) {
            if (current->data > data) {
                current = current->left;
            }
            else {
                current = current->right;
            }

            if (current == NULL) {
                return NULL;
            }
        }

        return current;
    }
};

int main()
{

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    Tree* tree = new Tree();
    int i;
    int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for (i = 0; i < 7; i++)
        tree->AddNode(array[i]);

    Node* temp = tree->Search(27);

    cout << temp->data << '\n';

    // Record end time
    auto finish = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = finish - start;
    cout << elapsed.count() << " ms";
};
