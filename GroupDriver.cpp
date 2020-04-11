#include "Util.h"

GroupDriver::GroupDriver() : extraLegRoom(false), recliningSeats(false), noise(NoiseLevel::SILENT) {}

GroupDriver::GroupDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open,
                         bool pets, const string &notes, int cargoCap, bool foodAllowed, bool extraLegRoom,
                         bool recliningSeats, NoiseLevel noise) : Driver(name, id, cap, hcp, type, rating, open, pets,
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

void GroupDriver::printDriver() {
    Driver::printDriver();
    vs text = {"Group Class",
               "Food allowed: " + Util::bts(foodAllowed),
               "Extra Legroom: " + Util::bts(extraLegRoom),
               "Reclining Seats: " + Util::bts(recliningSeats),
               "Noise Level Allowed: " + noiseLevelToString(noise)};
    Util::prettyPrint(text);
}

pair<int, int> GroupDriver::getCapacityRange() {
    return pair<int, int>{5, 7};
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
