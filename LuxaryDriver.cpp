#include "Util.h"

LuxaryDriver::LuxaryDriver() : TV(false), phone(false), bar(false), partyLights(false), bluetooth(false), wifi(false) {}

LuxaryDriver::LuxaryDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open,
                           bool pets, const string &notes, int cargoCap, bool tv, bool phone, bool bar,
                           bool partyLights, bool bluetooth, bool wifi) : Driver(name, id, cap, hcp, type, rating, open,
                                                                                 pets, notes, cargoCap), TV(tv),
                                                                          phone(phone), bar(bar),
                                                                          partyLights(partyLights),
                                                                          bluetooth(bluetooth), wifi(wifi) {}

bool LuxaryDriver::getTv() const {
    return TV;
}

void LuxaryDriver::setTv(bool tv) {
    TV = tv;
}

bool LuxaryDriver::getPhone() const {
    return phone;
}

void LuxaryDriver::setPhone(bool phone) {
    LuxaryDriver::phone = phone;
}

bool LuxaryDriver::getBar() const {
    return bar;
}

void LuxaryDriver::setBar(bool bar) {
    LuxaryDriver::bar = bar;
}

bool LuxaryDriver::getPartyLights() const {
    return partyLights;
}

void LuxaryDriver::setPartyLights(bool partyLights) {
    LuxaryDriver::partyLights = partyLights;
}

bool LuxaryDriver::getBluetooth() const {
    return bluetooth;
}

void LuxaryDriver::setBluetooth(bool bluetooth) {
    LuxaryDriver::bluetooth = bluetooth;
}

bool LuxaryDriver::getWifi() const {
    return wifi;
}

void LuxaryDriver::setWifi(bool wifi) {
    LuxaryDriver::wifi = wifi;
}

void LuxaryDriver::printDriver() {
    Driver::printDriver();
    vs text = {"Luxary Class",
               "TV: " + Util::bts(TV),
               "Phone: " + Util::bts(phone),
               "Bar: " + Util::bts(bar),
               "Party Lights: " + Util::bts(partyLights),
               "Bluetooth: " + Util::bts(bluetooth),
               "WiFi: " + Util::bts(wifi)};
    Util::prettyPrint(text);
}

pair<int, int> LuxaryDriver::getCapacityRange() {
    return pair<int, int>{8, 20};
}
                                                                          
                                                                          