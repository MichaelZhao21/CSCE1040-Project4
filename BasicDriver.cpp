#include "Util.h"

BasicDriver::BasicDriver() {}

BasicDriver::BasicDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open,
                         bool pets, const string &notes, int cargoCap) : Driver(name, id, cap, hcp, type, rating, open,
                                                                                pets, notes, cargoCap) {}

void BasicDriver::printDriver() {
    Driver::printDriver();
    vs text = {"Basic Class",
               "No extra info!"};
    Util::prettyPrint(text);
}

pair<int, int> BasicDriver::getCapacityRange() {
    return pair<int, int>{2, 4};
}