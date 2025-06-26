#include <iostream>
#include <string>
using namespace std;

class PersonNode {
public:
    string personName;
    PersonNode* nextPerson;

    PersonNode(string name, PersonNode* next = nullptr) {
        this->personName = name;
        this->nextPerson = next;
    }
};

class PersonList {
private:
    PersonNode* head;
    PersonNode* tail;

public:
    PersonList(PersonNode* start = nullptr) {
        this->head = start;
        this->tail = start;
        if (start) start->nextPerson = nullptr;
    }

    void addPerson(PersonNode* newPerson) {
        if (!newPerson) return;
        newPerson->nextPerson = nullptr;

        if (!head) {
            head = newPerson;
            tail = newPerson;
        } else {
            tail->nextPerson = newPerson;
            tail = newPerson;
        }
    }

    void showList() {
        PersonNode* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->personName << " -> ";
            current = current->nextPerson;
        }
        cout << "nullptr" << endl;
    }

    void removeByName(string targetName) {
        if (!head) return;

        if (head->personName == targetName) {
            PersonNode* temp = head;
            head = head->nextPerson;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        PersonNode* current = head;
        while (current->nextPerson && current->nextPerson->personName != targetName) {
            current = current->nextPerson;
        }

        if (current->nextPerson) {
            PersonNode* temp = current->nextPerson;
            current->nextPerson = temp->nextPerson;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    PersonNode* getHead() const {
        return head;
    }
};

int main() {
    PersonNode* p1 = new PersonNode("Albert");
    PersonNode* p2 = new PersonNode("Chris");
    PersonNode* p3 = new PersonNode("Billy");

    PersonList contactList(p1);
    contactList.addPerson(p2);
    contactList.addPerson(p3);

    contactList.showList();

    contactList.removeByName("Chris");
    cout << "After removing Chris: ";
    contactList.showList();

    PersonNode* current = contactList.getHead();
    while (current) {
        PersonNode* temp = current;
        current = current->nextPerson;
        delete temp;
    }

    return 0;
}
