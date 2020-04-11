#ifndef ECONOMYDRIVER_H
#define ECONOMYDRIVER_H

#include "Defs.h"
#include "Driver.h"

class EconomyDriver : public Driver {
public:
    EconomyDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
                  const string &notes, double reliability);

    EconomyDriver();

    void printDriver() override;
private:
    double reliability;
public:
    double getReliability() const;

    void setReliability(double reliability);
};


#endif //ECONOMYDRIVER_H
