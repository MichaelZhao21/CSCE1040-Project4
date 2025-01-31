#include "Util.h"

bool Util::parseInput(int& in, const string& message, int min, int max, bool checkDefault) {
    in = min - 1;
    while (cin.fail() || in < min || in > max) {
        cout << message << " (" << min << "-" << max << "): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

bool Util::parseInput(double& in, const string &message, double min, double max, bool checkDefault) {
    in = min - 1;
    bool fail = true;
    while (fail) {
        fail = false;
        cout << message << " (" << min << "-" << max << "): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        if (cin.fail() || in < min || in > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            fail = true;
        }
    }
    cin.ignore();
    return true;
}

bool Util::parseInput(string& in, const string &message, bool checkDefault) {
    in = "";
    while (in.empty()) {
        cout << message << ": ";
        getline(cin, in);
        if (checkDefault && in.empty())
            return false;
    }
    return true;
}

bool Util::parseInput(int &in, const string &message, const vs &enumNames, bool checkDefault) {
    int max = enumNames.size();
    int min = 1;
    stringstream newMessage;
    newMessage << message << " (";
    for (int i = 1; i < max + 1; i++) {
        newMessage << i << " - " << enumNames[i - 1];
        if (i != max)
            newMessage << ", ";
    }
    newMessage << "): ";
    in = min - 1;
    while (cin.fail() || in < min || in > max) {
        cout << newMessage.str();
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

bool Util::parseInput(bool& in, const string &message, bool checkDefault) {
    char tempIn = ' ';
    while (toupper(tempIn) != 'Y' && toupper(tempIn) != 'N') {
        cout << message << " (y/n): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> tempIn;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    in = (toupper(tempIn) == 'Y');
    return true;
}

bool Util::parseInput(time_t& in, const string &message, bool checkDefault) {
    if (in == 0)
        in = time(nullptr);

    tm *ltm = localtime(&in);
    string date, timeIn;
    bool dateDef, timeDef;

    cout << message << ":" << endl;
    dateDef = formattedStringInput(date, "\tEnter the date (MM/DD/YYYY)", R"(^\d{2}\/\d{2}\/\d{4}$)", checkDefault);
    timeDef = formattedStringInput(timeIn, "\tEnter the time (HH:MM:SS)", R"(^\d{2}:\d{2}:\d{2}$)", checkDefault);

    if (dateDef) {
        ltm->tm_mon = stoi(date.substr(0, 2)) - 1;
        ltm->tm_mday = stoi(date.substr(3, 2));
        ltm->tm_year = stoi(date.substr(6, 4)) - 1900;
    }
    if (timeDef) {
        ltm->tm_hour = stoi(timeIn.substr(0, 2)) - 1;
        ltm->tm_min = stoi(timeIn.substr(3, 2));
        ltm->tm_sec = stoi(timeIn.substr(6, 2));
    }

    in = mktime(ltm);
    return true;
}

bool Util::formattedStringInput(string& in, const string &message, const string &format, bool checkDefault) {
    regex b(format);
    while (!regex_match(in, b)) {
        cout << message << ": ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

unordered_map<TextLabel, vs> Util::getBlockText() {
    unordered_map<TextLabel, vs> blockText;
    ifstream in("blocktext");
    string temp;
    vs currText;
    int ctr = 0;
    while (getline(in, temp)) {
        if (temp == "1") {
            blockText[(TextLabel)ctr] = currText;
            currText.clear();
            ctr++;
        }
        else currText.push_back(temp);
    }
    in.close();

    return blockText;
}

int Util::menu(vs text) {
    for (int i = 1; i < text.size(); i++)
        text[i] = to_string(i) + ". " + text[i];
    prettyPrint(text);
    int in;
    parseInput(in, "Choice", 1, text.size() - 1, false);
    cout << endl;
    return in;
}

void Util::load(Drivers &drivers, Passes &passes, Rides &rides) {
    ifstream in("mg.dat");
    if (in.good()) {
        unordered_map<int, Pass> passMap {};
        unordered_map<int, Driver*> driverMap {};
        unordered_map<int, Ride> rideMap {};
        string name, notes, pickLoc, dropLoc;
        int pay, id, cap, status, passId, driverId, rid, pid, did, cc;
        double rat;
        long pickTime, dropTime;
        bool hcp, pets, open;
        char rpd;

        in >> rid >> pid >> did;
        while (in >> rpd) {
            in.ignore();
            if (rpd == 'd') {
                int dt;
                in >> dt;
                in.ignore();
                getline(in, name);
                getline(in, notes);
                in >> id >> cap >> hcp >> rat >> open >> pets >> cc;
                if (dt == 1) {
                    int rel;
                    in >> rel;
                    driverMap[id] = new EconomyDriver(name, id, cap, hcp, rat, open, pets, notes, cc, rel);
                }
                else if (dt == 2) {
                    bool airCon, music;
                    in >> airCon >> music;
                    driverMap[id] = new BasicDriver(name, id, cap, hcp, rat, open, pets, notes, cc, airCon, music);
                }
                else if (dt == 3) {
                    bool foodAllowed, extraLegRoom, recliningSeats;
                    int noise;
                    in >> foodAllowed >> extraLegRoom >> recliningSeats >> noise;
                    driverMap[id] = new GroupDriver(name, id, cap, hcp, rat, open, pets, notes, cc, foodAllowed, extraLegRoom, recliningSeats, (NoiseLevel) noise);
                }
                else {
                    bool TV, phone, bar, partyLights, bluetooth, wifi;
                    string extras;
                    in >> TV >> phone >> bar >> partyLights >> bluetooth >> wifi;
                    cin.ignore();
                    getline(cin, extras);
                    driverMap[id] = new LuxuryDriver(name, id, cap, hcp, rat, open, pets, notes, cc, TV, phone, bar, partyLights, bluetooth, wifi, extras);
                }
            }
            else if (rpd == 'p') {
                getline(in, name);
                in >> id >> pay >> hcp >> rat >> pets;
                passMap[id] = Pass(name, id, (PayType) pay, hcp, rat, pets);
            }
            else if (rpd == 'r') {
                getline(in, pickLoc);
                getline(in, dropLoc);
                in >> id >> pickTime >> cap >> pets >> dropTime >> status >> rat >> passId >> driverId;
                rideMap[id] = Ride(id, pickLoc, pickTime, dropLoc, cap, pets, dropTime, (Status) status, rat, passId, driverId);
            }
        }
        drivers.driverList = driverMap;
        passes.passList = passMap;
        rides.rideList = rideMap;
        drivers.setNextId(did);
        passes.setNextId(pid);
        rides.setNextId(rid);
    }
    in.close();
}

void Util::save(Drivers &drivers, Passes &passes, Rides &rides) {
    ofstream out("mg.dat");
    out << rides.getNextId() << " " << passes.getNextId() << " " << drivers.getNextId() << endl;
    for (pair<int, Driver*> dp : drivers.driverList) {
        int dt = dp.second->getDriverType();
        out << 'd' << " " << dt;
        out << endl << dp.second->getName() << endl << dp.second->getNotes() << endl << dp.second->getId() << " " <<
            dp.second->getCap() << " " << dp.second->getHcp() << " " << dp.second->getRating() <<
            " " << dp.second->getOpen() << " " << dp.second->getPets() << " " << dp.second->getCargoCap() << endl;
        if (dt == 1) {
            auto* e = dynamic_cast<EconomyDriver*>(dp.second);
            out << e->getReliability() << endl;
        }
        else if (dt == 2) {
            auto* b = dynamic_cast<BasicDriver*>(dp.second);
            out << b->getAirConditioning() << " " << b->getMusic();
        }
        else if (dt == 3) {
            auto* g = dynamic_cast<GroupDriver*>(dp.second);
            out << g->getFoodAllowed() << " " << g->getExtraLegRoom() << " " << g->getRecliningSeats() << " " << (int) (g->getNoise()) << endl;
        }
        else {
            auto* l = dynamic_cast<LuxuryDriver*>(dp.second);
            out << l->getTv() << " " << l->getPhone() << " " << l->getBar() << " " << l->getPartyLights() << " " << l->getBluetooth() << " " << l->getWifi() << endl;
            out << l->getExtras() << endl;
        }
    }
    for (pair<int, Pass> pp : passes.passList) {
        Pass p = pp.second;
        out << 'p' << endl << p.getName() << endl << p.getId() << " " << (int) p.getPayType() << " " << p.getHcp() << " " <<
                p.getMinRating() << " " << p.getPets() << endl;
    }
    for (pair<int, Ride> rp : rides.rideList) {
        Ride r = rp.second;
        out << 'r' << endl << r.getPickLoc() << endl << r.getDropLoc() << endl << r.getId() << " " << r.getPickTime() <<
                " " << r.getSize() << " " << r.getPets() << " " << r.getDropTime() << " " <<
                (int) r.getStatus() << " " << r.getRating() << " " << r.getPassId() << " " << r.getDriverId() << endl;
    }
    out.close();
}

void Util::prettyPrint(vs messages) {
    int origWidth = (int) messages[0].length() + 6;
    int maxWidth = origWidth;
    for (unsigned int i = 1; i < messages.size(); i++) {
        if (messages[i].size() + 4 > maxWidth) {
            maxWidth = (int) messages[i].length() + 4;
        }
    }
    int diff = 0;
    int uneven = 0;
    if (origWidth % 2 != maxWidth % 2) uneven++;
    if (origWidth != maxWidth)
        diff = (maxWidth - origWidth) / 2;
    cout << "+" << string(diff, '-') << "- " << messages[0] << " -" << string(diff + uneven, '-') << "+" << endl;
    for (unsigned int i = 1; i < messages.size(); i++) {
        diff = maxWidth - messages[i].length() - 4;
        cout << "| " << messages[i] << string(diff, ' ') << " |" << endl;
    }
    cout << "+" << string(maxWidth - 2, '-') << "+" << endl << endl;
}

vs Util::getList(string title, const vector<Ride>& rideGroup, bool onlyTime, Passes& passes, Drivers& drivers) {
    vs text{move(title)};
    for (auto & r : rideGroup) {
        stringstream temp;
        temp << r.getId();
        if (!onlyTime){
            temp << " | " << "P: " << passes.passList[r.getPassId()].getName() << " (#" << r.getPassId() << ") | ";
            temp << "D: " << drivers.driverList[r.getDriverId()]->getName() << " (#" << r.getDriverId() << ")";
        }
        long start = r.getPickTime();
        long end = r.getDropTime();
        string st = ctime(&start);
        string et = ctime(&end);
        temp << " | " << st.substr(0, st.length() - 1) << " -> " << et.substr(0, et.length() - 1);
        text.push_back(temp.str());
    }
    return text;
}

void Util::printCurrTime() {
    time_t now = time(nullptr);
    cout << "Current time is: " << ctime(&now) << endl;
    waitForEnter();
}

void Util::waitForEnter() {
    cout << "Press enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}

string Util::bts(bool in) {
    if (in) return "yes";
    return "no";
}

string Util::printTime(time_t seconds) {
    return ctime(&seconds);
}

string Util::printUnlessDefault(double in, bool time) {
    if (in == -1) return "N/A";
    if (time) return printTime(in);
    return to_string(in);
}

void Util::mainLoop(Drivers& drivers, Passes& passes, Rides& rides) {
    unordered_map<TextLabel, vs> blockText = getBlockText();
    prettyPrint(blockText[TextLabel::INTRO]);
    bool submenu = false;
    int choice = 0;
    int choice2 = 0;

    while (submenu || choice != 4) {
        rides.checkRideCompletion();
        fixErrors(drivers, passes, rides);
        save(drivers, passes, rides);
        if (submenu) {
            switch (choice) {
                case 1:
                    choice2 = menu(blockText[TextLabel::DRIVER]);
                    switch (choice2) {
                        case 1:
                            drivers.addDriver();
                            break;
                        case 2:
                            drivers.editDriver();
                            break;
                        case 3:
                            drivers.removeDriver();
                            break;
                        case 4:
                            drivers.findAndPrintDriver();
                            break;
                        case 5:
                            drivers.printAllDrivers();
                            break;
                        case 6:
                            rides.printDriverSchedule(passes, drivers);
                            break;
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                case 2:
                    choice2 = menu(blockText[TextLabel::PASS]);
                    switch (choice2) {
                        case 1:
                            passes.addPass();
                            break;
                        case 2:
                            passes.editPass();
                            break;
                        case 3:
                            passes.removePass();
                            break;
                        case 4:
                            passes.findAndPrintPass();
                            break;
                        case 5:
                            passes.printAllPasses();
                            break;
                        case 6:
                            rides.addRide(passes, drivers);
                            break;
                        case 7:
                            rides.cancelRide(passes, drivers);
                            break;
                        case 8:
                            rides.rateRides(passes, drivers);
                            break;
                        case 9:
                            rides.printPassSchedule(passes, drivers);
                            break;
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                case 3:
                    choice2 = menu(blockText[TextLabel::ADMIN]);
                    switch (choice2) {
                        case 1:
                            rides.printAllRides();
                            break;
                        case 2:
                            rides.findandPrintRide(passes, drivers);
                            break;
                        case 3:
                            rides.printRideByStatus(Status::ACTIVE, passes, drivers);
                            break;
                        case 4:
                            rides.printRideByStatus(Status::COMPLETED, passes, drivers);
                            break;
                        case 5:
                            rides.printRideByStatus(Status::CANCELLED, passes, drivers);
                            break;
                        case 6:
                            rides.removeUselessRides();
                            break;
                        case 7:
                            rides.removeRide(passes, drivers);
                            break;
                        case 8:
                            Util::clearData(drivers, passes, rides);
                            break;
                        case 9:
                            Util::printCurrTime();
                            break;
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        else {
            choice = menu(blockText[TextLabel::MAIN]);
            submenu = (choice != 4);
        }

    }
    fixErrors(drivers, passes, rides);
}

void Util::clearData(Drivers& drivers, Passes& passes, Rides& rides) {
    ofstream dat("mg.dat");
    if (dat.good())
        dat << "";
    drivers = Drivers();
    passes = Passes();
    rides = Rides();
    dat.close();
}

void Util::fixErrors(Drivers& drivers, Passes& passes, Rides& rides) {
    drivers.driverList.erase(0);
    passes.passList.erase(0);
    rides.rideList.erase(0);
}