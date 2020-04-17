#include "Util.h"
#include "LuxuryDriver.h"

LuxuryDriver::LuxuryDriver() : TV(false), phone(false), bar(false), partyLights(false), bluetooth(false), wifi(false) {}

LuxuryDriver::LuxuryDriver(const string &name, int id, int cap, bool hcp, double rating, bool open,
                           bool pets, const string &notes, int cargoCap, bool tv, bool phone, bool bar,
                           bool partyLights, bool bluetooth, bool wifi, const string &extras) : Driver(name, id, cap, hcp, rating, open,
                                                                                 pets, notes, cargoCap), TV(tv),
                                                                          phone(phone), bar(bar),
                                                                          partyLights(partyLights),
                                                                          bluetooth(bluetooth), wifi(wifi),
                                                                          extras(extras) {}

bool LuxuryDriver::getTv() const {
    return TV;
}

void LuxuryDriver::setTv(bool tv) {
    TV = tv;
}

bool LuxuryDriver::getPhone() const {
    return phone;
}

void LuxuryDriver::setPhone(bool phone) {
    LuxuryDriver::phone = phone;
}

bool LuxuryDriver::getBar() const {
    return bar;
}

void LuxuryDriver::setBar(bool bar) {
    LuxuryDriver::bar = bar;
}

bool LuxuryDriver::getPartyLights() const {
    return partyLights;
}

void LuxuryDriver::setPartyLights(bool partyLights) {
    LuxuryDriver::partyLights = partyLights;
}

bool LuxuryDriver::getBluetooth() const {
    return bluetooth;
}

void LuxuryDriver::setBluetooth(bool bluetooth) {
    LuxuryDriver::bluetooth = bluetooth;
}

bool LuxuryDriver::getWifi() const {
    return wifi;
}

void LuxuryDriver::setWifi(bool wifi) {
    LuxuryDriver::wifi = wifi;
}

const string &LuxuryDriver::getExtras() const {
    return extras;
}

void LuxuryDriver::setExtras(const string &extras) {
    LuxuryDriver::extras = extras;
}

void LuxuryDriver::printDriver(vs& extra) {
    vs text = {"Class: Luxury",
               "TV: " + Util::bts(TV),
               "Phone: " + Util::bts(phone),
               "Bar: " + Util::bts(bar),
               "Party Lights: " + Util::bts(partyLights),
               "Bluetooth: " + Util::bts(bluetooth),
               "WiFi: " + Util::bts(wifi),
               "Extra Amenities: " + extras};
    Driver::printDriver(text);
}

int LuxuryDriver::getDriverType() {
    return 4;
}