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
    EconomyDriver(const string &name, int id, int cap, bool hcp, double rating, bool open, bool pets,
                  const string &notes, int cargoCap, int reliability);

    /**
     * Setters and getters
     */
    int getReliability() const;
    void setReliability(int reliability);

    /**
     * Prints the driver
     */
    void printDriver(vs& extra) override;

    /**
     * Gets the driver type in an integer
     * @return integer representing the type of driver
     */
    int getDriverType() override;

private:
    int reliability;
};

#endif //ECONOMYDRIVER_H
