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
    BasicDriver(const string &name, int id, int cap, bool hcp, double rating, bool open, bool pets,
                const string &notes, int cargoCap, bool airConditioning, bool music);

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
    bool airConditioning, music;
public:
    bool getAirConditioning() const;

    void setAirConditioning(bool airConditioning);

    bool getMusic() const;

    void setMusic(bool music);
};

#endif //BASICDRIVER_H
