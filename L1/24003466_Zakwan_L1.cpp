#include <iostream> 
#include <string>   
#include <limits>

using namespace std; 

struct Student {
    int id;
    string name;
    int contact;
    string email;
};

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Student students[5];

    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "\n--- Student " << (i + 1) << " ---\n";

        cout << "Enter ID: ";
        cin >> students[i].id;
        clearInputBuffer(); 

        cout << "Enter Name: ";
        getline(cin, students[i].name);

        cout << "Enter Contact Number (e.g., 123456789): ";
        cin >> students[i].contact;
        clearInputBuffer();

        cout << "Enter Email: ";
        getline(cin, students[i].email);
    }

    cout << "\n===== Student Database Summary =====\n";
    for (int i = 0; i < 5; ++i) {
        cout << "**********" << endl;
        cout << "Student " << (i + 1) << endl;
        cout << "id: " << students[i].id << endl;
        cout << "name: " << students[i].name << endl;
        cout << "contact: " << students[i].contact << endl;
        cout << "email: " << students[i].email << endl;
    }
    cout << "********************\n";

    return 0;
}