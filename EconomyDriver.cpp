#include "Util.h"
#include "EconomyDriver.h"


EconomyDriver::EconomyDriver() : reliability(0) {}

EconomyDriver::EconomyDriver(const string &name, int id, int cap, bool hcp, double rating, bool open,
                             bool pets, const string &notes, int cargoCap, int reliability) : Driver(name, id, cap, hcp,
                                                                                                        rating, open,
                                                                                                        pets, notes,
                                                                                                        cargoCap),
                                                                                                 reliability(reliability) {}

int EconomyDriver::getReliability() const {
    return reliability;
}

void EconomyDriver::setReliability(int reliability) {
    EconomyDriver::reliability = reliability;
}

void EconomyDriver::printDriver(vs& extra) {
    vs text = {"Class: Economy",
               "Reliability: " + to_string(reliability) + "%"};
    Driver::printDriver(text);
}

int EconomyDriver::getDriverType() {
    return 1;
}
