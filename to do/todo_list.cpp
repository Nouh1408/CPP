#include <iostream>
#include <string>
#include <list>
using namespace std;

class Todoitem {
private:
    int id;
    string comment;
    bool completed;

public:
    Todoitem() : id(0), comment(""), completed(false) {}
    ~Todoitem() = default;

    bool create(string new_description) {
        id = rand() % 100 + 1;
        comment = new_description;
        return true;
    }

    int getID() {
        return id;
    }

    string getComment() {
        return comment;
    }

    bool isCompleted() {
        return completed;
    }

    void setCompleted(bool value) {
        completed = value;
    }
};

int main() {
    char input_option;
    int input_id;
    string input_comment;
    string version = "v0.2.0";
    list<Todoitem> todoItems;
    list<Todoitem>::iterator it;

    srand(time(NULL));
    todoItems.clear();

    while (1) {
        system("cls");
        cout << "Todo list " << version << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            string completedStatus = it->isCompleted() ? "Completed" : "Not Completed";
            cout << it->getID() << " | " << it->getComment() << " | " << completedStatus << endl;
        }

        if (todoItems.empty()) {
            cout << "Add a todo!" << endl;
        }
        cout << endl;

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "Choice: ";
        cin >> input_option;

        if (input_option == 'q') {
            cout << "Work harder!" << endl;
            break;
        } else if (input_option == 'a') {
            cout << "Add a new comment: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_comment);

            Todoitem newitem;
            newitem.create(input_comment);
            todoItems.push_back(newitem);
        } else if (input_option == 'c') {
            cout << "Enter ID to mark as completed: ";
            cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it->getID()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
    return 0;
}
