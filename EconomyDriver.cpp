#include "Util.h"

EconomyDriver::EconomyDriver() : reliability(0) {}

EconomyDriver::EconomyDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open,
                             bool pets, const string &notes, int cargoCap, double reliability) : Driver(name, id, cap,
                                                                                                        hcp, type,
                                                                                                        rating, open,
                                                                                                        pets, notes,
                                                                                                        cargoCap),
                                                                                                 reliability(reliability) {}

double EconomyDriver::getReliability() const {
    return reliability;
}

void EconomyDriver::setReliability(double reliability) {
    EconomyDriver::reliability = reliability;
}

void EconomyDriver::printDriver() {
    Driver::printDriver();
    vs text = {"Economy Class",
               "Reliability: " + to_string(reliability)};
    Util::prettyPrint(text);
}

pair<int, int> EconomyDriver::getCapacityRange() {
    return pair<int, int>{1, 2};
}