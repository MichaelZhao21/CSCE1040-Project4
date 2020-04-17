#ifndef DRIVERS_H
#define DRIVERS_H

#include "Defs.h"
#include "Driver.h"
using namespace std;

class Drivers {
public:

    /**
     * Constructors and Destructor
     */
    Drivers();
    Drivers(const unordered_map<int, Driver*> &driverList, int nextId);
    virtual ~Drivers();

    /**
     * Getters and setters
     */
    int getNextId() const;
    void setNextId(int nextId);

    /**
     * Prompts and adds a driver
     */
    void addDriver();

    /**
     * Edits a driver
     */
    void editDriver();

    /**
     * Removes a driver
     */
    void removeDriver();

    /**
     * Prompts for an gets a driver in driverList
     * @return an int representing the id of the driver found
     */
    int findDriver();

    /**
     * Calls findDriver() and prints that driver
     */
    void findAndPrintDriver();

    /**
     * Prints all drivers
     */
    void printAllDrivers();

    /**
     * Checks to see if the driver list is empty,
     * outputs to the user, and waits for enter
     * @return a boolean representing the emptiness of the driverlist
     */
    bool driverListEmpty();

    /**
     * Converts the driver type to a string
     * @param dt - Integer representing the type of driver
     * @return driver type name
     */
    string driverTypeIntToString(int dt);

    unordered_map<int, Driver*> driverList;

private:
    int nextId;
    vector<pair<int, int>> capacities = {{1, 2}, {2, 4}, {5, 7}, {8, 20}};
    vector<pair<int, int>> cargoCapacities = {{0, 1}, {2, 4}, {6, 10}, {1, 15}};
    vs emptyStringVector{};

};

#endif //DRIVERS_H
