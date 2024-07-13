#include <iostream>
#include <random>

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList() {
        Node *current = head;
        Node *toDeleteNode;
        while(current != nullptr) {
            toDeleteNode = current;
            current = current->next;
            delete toDeleteNode;
        }
        head = nullptr;
    }

    void Push(int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void Print() const {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << ", ";
            temp = temp->next;
        }
    }

    void Reverse() {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};





int main() {
    std::default_random_engine random;
    LinkedList linkedList;
    for(int i = 0; i < 10; ++i) {
        linkedList.Push((int)(100.0f * random() / random.max()));
    }

    std::cout << "linked list: ";
    linkedList.Print();

    linkedList.Reverse();

    std::cout << "\nReversed linked list: ";
    linkedList.Print();
    return 0;
}
