#include "Util.h"
#include "Drivers.h"

Drivers::Drivers() : driverList(unordered_map<int, Driver*>()), nextId(100000) {}

Drivers::Drivers(const unordered_map<int, Driver*> &driverList, int nextId) : driverList(driverList), nextId(nextId) {}

int Drivers::getNextId() const {
    return nextId;
}

void Drivers::setNextId(int nextId) {
    Drivers::nextId = nextId;
}

void Drivers::addDriver() {
    string name, notes;
    int id, cap, cc;
    double rating;
    bool hcp, open, pets;

    cout << "<<< Add Driver >>>" << endl;
    id = nextId++;
    vs driverMenu = {"Pick a type",
                     "Economy Driver - Cheap, small rides (1-2 passengers)",
                     "Basic Driver - Nothing special, your standard driver (2-4 passengers)",
                     "Group Driver - Bigger cars, for more people and luggage (5-7 passengers)",
                     "Luxury Driver - Limos only!!! (8-20 passengers)"};
    int driverType = Util::menu(driverMenu);
    Util::parseInput(name, "Name", false);
    Util::parseInput(cap, "Car capacity", capacities[driverType - 1].first, capacities[driverType - 1].second, false);
    Util::parseInput(cc, "Cargo Capacity in number of standard luggage bags", cargoCapacities[driverType - 1].first, cargoCapacities[driverType - 1].second, false);
    Util::parseInput(hcp, "Handicapped capable", false);
    Util::parseInput(rating, "Driver rating", 0, 5, false);
    Util::parseInput(open, "Availability", false);
    Util::parseInput(pets, "Allows pets", false);
    Util::parseInput(notes, "Notes", false);
    if (driverType == 1) {
        int rel;
        Util::parseInput(rel, "Reliability % <Less = Cheaper>", 0, 100, false);
        driverList[id] = new EconomyDriver(name, id, cap, hcp, rating, open, pets, notes, cc, rel);
    }
    else if (driverType == 2) {
        bool airCon, music;
        Util::parseInput(airCon, "Air Conditioning", false);
        Util::parseInput(music, "Allows passenger to play music", false);
        driverList[id] = new BasicDriver(name, id, cap, hcp, rating, open, pets, notes, cc, airCon, music);
    }
    else if (driverType == 3) {
        bool foodAllowed, extraLegRoom, recliningSeats;
        int noise;
        Util::parseInput(foodAllowed, "Food Allowed", false);
        Util::parseInput(extraLegRoom, "Extra Legroom", false);
        Util::parseInput(recliningSeats, "Reclining Seats", false);
        Util::parseInput(noise, "Noise Level", vs{"NO NOISE ALLOWED", "Low Spoken Volume", "Normal Conversation", "Loud Conversation okay", "UNRESTRICTED"}, false);
        driverList[id] = new GroupDriver(name, id, cap, hcp, rating, open, pets, notes, cc, foodAllowed, extraLegRoom, recliningSeats, (NoiseLevel) noise);
    }
    else {
        bool TV, phone, bar, partyLights, bluetooth, wifi;
        string extras;
        Util::parseInput(TV, "TV", false);
        Util::parseInput(phone, "Phone Onboard", false);
        Util::parseInput(bar, "Bar", false);
        Util::parseInput(partyLights, "Party Lights", false);
        Util::parseInput(bluetooth, "Bluetooth", false);
        Util::parseInput(wifi, "WiFi", false);
        Util::parseInput(extras, "Extra Amenities", false);
        driverList[id] = new LuxuryDriver(name, id, cap, hcp, rating, open, pets, notes, cc, TV, phone, bar, partyLights, bluetooth, wifi, extras);
    }

    cout << endl;
    driverList[id]->printDriver(emptyStringVector);
    Util::waitForEnter();
}

void Drivers::editDriver() {
    string name, notes;
    int cap, cc;
    double rating;
    bool hcp, open, pets;

    cout << "<<< Edit Driver >>>" << endl;
    if (driverListEmpty()) return;
    int index = findDriver();
    int driverType = driverList[index]->getDriverType();

    cout << "<<< Edit information for Driver #" << index << " >>>" << endl;
    if (Util::parseInput(name, "Name", true)) driverList[index]->setName(name);
    if (Util::parseInput(cap, "Car capacity", capacities[driverType - 1].first, capacities[driverType - 1].second, true)) driverList[index]->setCap(cap);
    if (Util::parseInput(cc, "Cargo Capacity in number of standard luggage bags", cargoCapacities[driverType - 1].first, cargoCapacities[driverType - 1].second, true)) driverList[index]->setCargoCap(cc);
    if (Util::parseInput(hcp, "Handicapped capable", true)) driverList[index]->setHcp(hcp);
    if (Util::parseInput(rating, "Driver rating", 0, 5, true)) driverList[index]->setRating(rating);
    if (Util::parseInput(open, "Availability", true)) driverList[index]->setOpen(open);
    if (Util::parseInput(pets, "Allows pets", true)) driverList[index]->setPets(pets);
    if (Util::parseInput(notes, "Notes", true)) driverList[index]->setNotes(notes);
    if (driverType == 1) {
        auto* e = dynamic_cast<EconomyDriver*>(driverList[index]);
        int rel;
        if (Util::parseInput(rel, "Reliability <Less = Cheaper>", 0, 100, true)) e->setReliability(rel);
    }
    else if (driverType == 2) {
        auto* b = dynamic_cast<BasicDriver*>(driverList[index]);
        bool airCon, music;
        if (Util::parseInput(airCon, "Air Conditioning", false)) b->setAirConditioning(airCon);
        if (Util::parseInput(music, "Allows passenger to play music", false)) b->setMusic(music);
    }
    else if (driverType == 3) {
        auto* g = dynamic_cast<GroupDriver*>(driverList[index]);
        bool foodAllowed, extraLegRoom, recliningSeats;
        int noise;
        if (Util::parseInput(foodAllowed, "Food Allowed", true)) g->setFoodAllowed(foodAllowed);
        if (Util::parseInput(extraLegRoom, "Extra Legroom", true)) g->setExtraLegRoom(extraLegRoom);
        if (Util::parseInput(recliningSeats, "Reclining Seats", true)) g->setRecliningSeats(recliningSeats);
        if (Util::parseInput(noise, "Noise Level", vs{"NO NOISE ALLOWED", "Low Spoken Volume", "Normal Conversation", "Loud Conversation okay", "UNRESTRICTED"}, true)) g->setNoise((NoiseLevel) noise);
    }
    else if (driverType == 4) {
        auto* l = dynamic_cast<LuxuryDriver*>(driverList[index]);
        bool TV, phone, bar, partyLights, bluetooth, wifi;
        string extras;
        if (Util::parseInput(TV, "TV", true)) l->setTv(TV);
        if (Util::parseInput(phone, "Phone Onboard", true)) l->setPhone(phone);
        if (Util::parseInput(bar, "Bar", true)) l->setBar(bar);
        if (Util::parseInput(partyLights, "Party Lights", true)) l->setPartyLights(partyLights);
        if (Util::parseInput(bluetooth, "Bluetooth", true)) l->setBluetooth(bluetooth);
        if (Util::parseInput(wifi, "WiFi", true)) l->setWifi(wifi);
        if (Util::parseInput(extras, "Extra Amenities", false)) l->setExtras(extras);
    }

    cout << endl;
    driverList[index]->printDriver(emptyStringVector);
    Util::waitForEnter();
}

void Drivers::removeDriver() {
    cout << "<<< Remove Driver >>>" << endl;
    if (driverListEmpty()) return;
    int index = findDriver();
    delete driverList[index];
    driverList.erase(index);
}

int Drivers::findDriver() {
    assert(!driverList.empty());
    vs text {"Pick a driver"};
    for (pair<int, Driver*> dp : driverList) {
        text.push_back(to_string(dp.first) + " | " + driverTypeIntToString(dp.second->getDriverType()) + " | " + dp.second->getName());
    }
    int index = Util::menu(text);
    return stoi(text[index]);
}

void Drivers::findAndPrintDriver() {
    cout << "<<< Find Driver >>>" << endl;
    if (driverListEmpty()) return;
    driverList[findDriver()]->printDriver(emptyStringVector);
    Util::waitForEnter();
}

void Drivers::printAllDrivers() {
    cout << "<<< Print All Drivers >>>" << endl;
    if (driverListEmpty()) return;
    for (pair<int, Driver*> d : driverList)
        d.second->printDriver(emptyStringVector);
    Util::waitForEnter();
}

bool Drivers::driverListEmpty() {
    if (driverList.empty()) {
        cout << "No drivers :(" << endl << endl;
        Util::waitForEnter();
        return true;
    }
    return false;
}

string Drivers::driverTypeIntToString(int dt) {
    if (dt == 1) return "Economy";
    if (dt == 2) return "Basic  ";
    if (dt == 3) return "Group  ";
    if (dt == 4) return "Luxary ";
    perror("Invalid driver type in Drivers::driverTypeIntToString(int dt);");
    return "";
}

Drivers::~Drivers() {
    for (pair<int, Driver*> d : driverList)
        delete d.second;
}
