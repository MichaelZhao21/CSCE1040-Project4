#include "Util.h"
#include "BasicDriver.h"


BasicDriver::BasicDriver() : airConditioning(false), music(false) {}

BasicDriver::BasicDriver(const string &name, int id, int cap, bool hcp, double rating, bool open,
                         bool pets, const string &notes, int cargoCap, bool airConditioning, bool music) : Driver(name, id, cap, hcp, rating, open,
                                                                                pets, notes, cargoCap),
                                                                                airConditioning(airConditioning),
                                                                                music(music) {}

bool BasicDriver::getAirConditioning() const {
    return airConditioning;
}

void BasicDriver::setAirConditioning(bool airConditioning) {
    BasicDriver::airConditioning = airConditioning;
}

bool BasicDriver::getMusic() const {
    return music;
}

void BasicDriver::setMusic(bool music) {
    BasicDriver::music = music;
}

void BasicDriver::printDriver(vs& extra) {
    vs text = {"Class: Basic",
               "Air Conditioning: " + Util::bts(airConditioning),
               "Allows passenger to Play Music: " + Util::bts(music)};
    Driver::printDriver(text);
}

int BasicDriver::getDriverType() {
    return 2;
}