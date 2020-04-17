#include "Util.h"
#include "Driver.h"

Driver::Driver() : name(""), id(0), cap(0), hcp(false), rating(0.0), open(false),
                pets(false), notes(""), cargoCap(0) {}

Driver::Driver(const string &name, int id, int cap, bool hcp, double rating, bool open, bool pets,
               const string &notes, int cargoCap) : name(name), id(id), cap(cap), hcp(hcp), rating(rating), open(open),
                                                pets(pets), notes(notes), cargoCap(cargoCap) {}

const string &Driver::getName() const {
    return name;
}

void Driver::setName(const string &name) {
    Driver::name = name;
}

int Driver::getId() const {
    return id;
}

void Driver::setId(int id) {
    Driver::id = id;
}

int Driver::getCap() const {
    return cap;
}

void Driver::setCap(int cap) {
    Driver::cap = cap;
}

bool Driver::getHcp() const {
    return hcp;
}

void Driver::setHcp(bool hcp) {
    Driver::hcp = hcp;
}

double Driver::getRating() const {
    return rating;
}

void Driver::setRating(double rating) {
    Driver::rating = rating;
}

bool Driver::getOpen() const {
    return open;
}

void Driver::setOpen(bool open) {
    Driver::open = open;
}

bool Driver::getPets() const {
    return pets;
}

void Driver::setPets(bool pets) {
    Driver::pets = pets;
}

const string &Driver::getNotes() const {
    return notes;
}

void Driver::setNotes(const string &notes) {
    Driver::notes = notes;
}

int Driver::getCargoCap() const {
    return cargoCap;
}

void Driver::setCargoCap(int cargoCap) {
    Driver::cargoCap = cargoCap;
}

void Driver::printDriver(vs& extra) {
    vs text {"Driver #" + to_string(id),
                   "Name: " + name,
                   "Vehicle capacity: " + to_string(cap),
                   "Cargo capacity (luggage bags): " + to_string(cargoCap),
                   "Handicapped capable: " + Util::bts(hcp),
                   "Driver Rating: " + to_string(rating),
                   "Available: " + Util::bts(open),
                   "Pets allowed: " + Util::bts(pets),
                   "Notes: " + notes};
    if (!extra.empty())
        text.insert(text.end(), extra.begin(), extra.end());
    Util::prettyPrint(text);
}