#ifndef BASICDRIVER_H
#define BASICDRIVER_H

#include "Defs.h"
#include "Driver.h"

class BasicDriver : public Driver {
public:
    /**
     * Constructors
     */
    BasicDriver();
    BasicDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
                const string &notes, int cargoCap);

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
};

#endif //BASICDRIVER_H
