#include "Util.h"
#include "GroupDriver.h"


GroupDriver::GroupDriver() : foodAllowed(false), extraLegRoom(false), recliningSeats(false), noise(NoiseLevel::SILENT) {}

GroupDriver::GroupDriver(const string &name, int id, int cap, bool hcp, double rating, bool open,
                         bool pets, const string &notes, int cargoCap, bool foodAllowed, bool extraLegRoom,
                         bool recliningSeats, NoiseLevel noise) : Driver(name, id, cap, hcp, rating, open, pets,
                                                                         notes, cargoCap), foodAllowed(foodAllowed),
                                                                  extraLegRoom(extraLegRoom),
                                                                  recliningSeats(recliningSeats), noise(noise) {}

bool GroupDriver::getFoodAllowed() const {
    return foodAllowed;
}

void GroupDriver::setFoodAllowed(bool foodAllowed) {
    GroupDriver::foodAllowed = foodAllowed;
}

bool GroupDriver::getExtraLegRoom() const {
    return extraLegRoom;
}

void GroupDriver::setExtraLegRoom(bool extraLegRoom) {
    GroupDriver::extraLegRoom = extraLegRoom;
}

bool GroupDriver::getRecliningSeats() const {
    return recliningSeats;
}

void GroupDriver::setRecliningSeats(bool recliningSeats) {
    GroupDriver::recliningSeats = recliningSeats;
}

NoiseLevel GroupDriver::getNoise() const {
    return noise;
}

void GroupDriver::setNoise(NoiseLevel noise) {
    GroupDriver::noise = noise;
}

void GroupDriver::printDriver(vs& extra) {
    vs text = {"Class: Group",
               "Food allowed: " + Util::bts(foodAllowed),
               "Extra Legroom: " + Util::bts(extraLegRoom),
               "Reclining Seats: " + Util::bts(recliningSeats),
               "Noise Level Allowed: " + noiseLevelToString(noise)};
    Driver::printDriver(text);
}

string GroupDriver::noiseLevelToString(NoiseLevel noise) {
    switch (noise) {
        case SILENT:
            return "NO NOISE ALLOWED";
        case LOW:
            return "Low Spoken Volume";
        case MEDIUM:
            return "Normal conversation";
        case HIGH:
            return "Loud conversation okay";
        case UNRESTRICTED:
            return "UNRESTRICTED";
        default:
            perror("Invalid NoiseLevel in GroupDriver::noiseLevelToString");
            return "";
    }
}

int GroupDriver::getDriverType() {
    return 3;
}
