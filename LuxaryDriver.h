#ifndef LUXARYDRIVER_H
#define LUXARYDRIVER_H

#include "Defs.h"
#include "Driver.h"

class LuxaryDriver : public Driver {
public:
    /**
     * Constructors
     */
    LuxaryDriver();
    LuxaryDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
                 const string &notes, int cargoCap, bool tv, bool phone, bool bar, bool partyLights, bool bluetooth,
                 bool wifi);

    /**
     * Getters and setters
     */
    bool getTv() const;
    void setTv(bool tv);
    bool getPhone() const;
    void setPhone(bool phone);
    bool getBar() const;
    void setBar(bool bar);
    bool getPartyLights() const;
    void setPartyLights(bool partyLights);
    bool getBluetooth() const;
    void setBluetooth(bool bluetooth);
    bool getWifi() const;
    void setWifi(bool wifi);

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
    bool TV, phone, bar, partyLights, bluetooth, wifi;

};

#endif //LUXARYDRIVER_H