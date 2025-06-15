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
    PersonNode* first;
    PersonNode* last;

public:
    PersonList(PersonNode* start = nullptr) {
        this->first = start;
        this->last = start;
        if (start) start->nextPerson = nullptr;
    }

    void addPerson(PersonNode* newPerson) {
        if (!newPerson) return;
        newPerson->nextPerson = nullptr;

        if (!first) {
            first = newPerson;
            last = newPerson;
        } else {
            last->nextPerson = newPerson;
            last = newPerson;
        }
    }

    void showList() {
        PersonNode* current = first;
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
        if (!first) return;

        if (first->personName == targetName) {
            PersonNode* temp = first;
            first = first->nextPerson;
            delete temp;
            if (!first) last = nullptr;
            return;
        }

        PersonNode* current = first;
        while (current->nextPerson && current->nextPerson->personName != targetName) {
            current = current->nextPerson;
        }

        if (current->nextPerson) {
            PersonNode* temp = current->nextPerson;
            current->nextPerson = temp->nextPerson;
            if (temp == last) last = current;
            delete temp;
        }
    }

    PersonNode* getFirst() const {
        return first;
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

    PersonNode* current = contactList.getFirst();
    while (current) {
        PersonNode* temp = current;
        current = current->nextPerson;
        delete temp;
    }

    return 0;
}
