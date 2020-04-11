#ifndef ECONOMYDRIVER_H
#define ECONOMYDRIVER_H

#include "Defs.h"
#include "Driver.h"

class EconomyDriver : public Driver {
public:
    /**
     * Constructors
     */
    EconomyDriver();
    EconomyDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
                  const string &notes, int cargoCap, double reliability);

    /**
     * Setters and getters
     */
    double getReliability() const;
    void setReliability(double reliability);

    /**
     * Prints the driver
     */
    void printDriver() override;

    /**
     * Gets the minimum and maximum capacity
     * of the type of driver
     * @return pair of ints representing [min, max]
     */
    pair<int, int> getCapacityRange() override;

private:
    double reliability;
};

#endif //ECONOMYDRIVER_H
