#include "Util.h"

Pass::Pass() : name(""), id(0), payType(PayType::CASH), hcp(false), minRating(0), pets(0) {}

Pass::Pass(const string &name, int id, PayType payType, bool hcp, double minRating, bool pets) : name(name), id(id),
                                                                                                 payType(payType),
                                                                                                 hcp(hcp),
                                                                                                 minRating(minRating),
                                                                                                 pets(pets) {}

const string &Pass::getName() const {
    return name;
}

void Pass::setName(const string &name) {
    Pass::name = name;
}

int Pass::getId() const {
    return id;
}

void Pass::setId(int id) {
    Pass::id = id;
}

PayType Pass::getPayType() const {
    return payType;
}

void Pass::setPayType(PayType payType) {
    Pass::payType = payType;
}

bool Pass::getHcp() const {
    return hcp;
}

void Pass::setHcp(bool hcp) {
    Pass::hcp = hcp;
}

double Pass::getMinRating() const {
    return minRating;
}

void Pass::setMinRating(double minRating) {
    Pass::minRating = minRating;
}

bool Pass::getPets() const {
    return pets;
}

void Pass::setPets(bool pets) {
    Pass::pets = pets;
}

void Pass::printPass() {

    cout << "Passenger #" << id << endl;
    cout << "-----------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Payment Preference: " << payTypeToString(payType) << endl;
    cout << "Handicapped: " << (hcp ? "yes" : "no") << endl;
    cout << "Default rating required: " << minRating << endl;
    cout << "Has pets: " << (pets ? "yes" : "no") << endl;
    cout << "-----------------" << endl << endl;
}

string Pass::payTypeToString(PayType p) {
    switch (p) {
        case CASH:
            return "cash";
        case CREDIT:
            return "credit";
        case DEBIT:
            return "debit";
        default:
            return "";
    }
}
