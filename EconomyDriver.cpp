#include "EconomyDriver.h"

EconomyDriver::EconomyDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open,
                             bool pets, const string &notes, double reliability) : Driver(name, id, cap, hcp, type,
                                                                                              rating, open, pets,
                                                                                              notes), reliability(reliability) {}

EconomyDriver::EconomyDriver() : reliability(0) {}

double EconomyDriver::getReliability() const {
    return reliability;
}

void EconomyDriver::setReliability(double reliability) {
    EconomyDriver::reliability = reliability;
}

void EconomyDriver::printDriver() {
    Driver::printDriver();
    vs text = {"Driver #" + to_string(id) + " - Economy Info",
               "Reliability: " + to_string(reliability)};
}