#include "Util.h"
#include "Passes.h"


Passes::Passes() : passList(unordered_map<int, Pass>()), nextId(100000) {}

Passes::Passes(const unordered_map<int, Pass> &passList, int nextId) : passList(passList), nextId(nextId) {}

int Passes::getNextId() const {
    return nextId;
}

void Passes::setNextId(int nextId) {
    Passes::nextId = nextId;
}

void Passes::addPass() {
    string name;
    int id, payType;
    bool hcp, pets;
    double minRating;

    cout << "<<< Add Passenger >>>" << endl;
    id = nextId++;
    Util::parseInput(name, "Name", false);
    Util::parseInput(payType, "Payment type", vs{"Cash", "Credit", "Debit"}, false);
    Util::parseInput(hcp, "Handicapped", false);
    Util::parseInput(minRating, "Min rating required", 0, 5, false);
    Util::parseInput(pets, "Has pets", false);
    cout << endl;

    passList[id] = Pass(name, id, (PayType) payType, hcp, minRating, pets);
    passList[id].printPass();
    Util::waitForEnter();
}

void Passes::editPass() {
    string name;
    int id, payType;
    bool hcp, pets;
    double minRating;

    cout << "<<< Edit Passenger >>>" << endl;
    int index = findPass();
    Util::parseInput(name, "Name", true);
    Util::parseInput(payType, "Payment type", vs{"Cash", "Credit", "Debit"}, true);
    Util::parseInput(hcp, "Handicapped", true);
    Util::parseInput(minRating, "Min rating required", 0, 5, true);
    Util::parseInput(pets, "Has pets", true);
    cout << endl;

    passList[index].printPass();
    Util::waitForEnter();
}

void Passes::removePass() {
    cout << "<<< Remove Passenger >>>" << endl;
    passList.erase(findPass());
    cout << endl;
}

int Passes::findPass() {
    vs text {"Pick a passenger"};
    for (pair<int, Pass> pp : passList) {
        text.push_back(to_string(pp.first) + " | " + pp.second.getName());
    }
    int index = Util::menu(text);
    return stoi(text[index]);
}

void Passes::findAndPrintPass() {
    cout << "<<< Find Passenger >>>" << endl;
    passList[findPass()].printPass();
    Util::waitForEnter();
}

void Passes::printAllPasses() {
    for (pair<int, Pass> p : passList)
        p.second.printPass();
    Util::waitForEnter();
}