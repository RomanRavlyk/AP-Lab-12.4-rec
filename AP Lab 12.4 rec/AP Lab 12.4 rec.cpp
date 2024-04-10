#include <iostream>

using namespace std;

typedef int Info;
struct Elem {
    Elem* link;
    Info info;
};

void insertHelper(Elem* current, Elem* newElem, Elem*& L) {

    if (current->link == L) {
        current->link = newElem;
        newElem->link = L;
        return;
    }
    insertHelper(current->link, newElem, L);
}

void insert(Elem*& L, Info value) {
    Elem* newElem = new Elem;
    newElem->info = value;

    if (L == NULL) {
        L = newElem;
        newElem->link = L;
        return;
    }

    insertHelper(L, newElem, L);
}



void print(Elem* start, Elem* current) {
    if (current != nullptr) {
        cout << current->info << " ";
        if (current->link != start) {
            print(start, current->link);
        }
        else {
            cout << endl;
        }
    }
    else {
        cout << "list is empty" << endl;
    }
}

bool hasDuplicates(Elem* current, Elem* start) {
    if (current == nullptr)
        return false;

    Elem* checker = start;

    if (checker != current) {
        if (checker->info == current->info)
            return true;
        else
            return hasDuplicates(current, checker->link);
    }
    else {
        return hasDuplicates(current->link, start);
    }
}

bool hasDuplicates(Elem* L) {
    if (L == nullptr)
        return false;

    return hasDuplicates(L, L->link);
}
int main() {
    Elem* list = nullptr;

    for (int i = 0; i < 10; i++) {
        int x;
        cout << "Which num you want to insert?: ";
        cin >> x;
        insert(list, x);
    }
    cout << endl;
    cout << "Your list: ";
    Elem* current = list;

    print(list, current);

    if (hasDuplicates(list)) {
        std::cout << "List has duplicates" << std::endl;
    }
    else {
        std::cout << "List has no duplicates" << std::endl;
    }

    return 0;
}