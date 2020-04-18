#ifndef LUXURYDRIVER_H
#define LUXURYDRIVER_H

#include "Defs.h"
#include "Driver.h"

class LuxuryDriver : public Driver {
public:
    /**
     * Constructors
     */
    LuxuryDriver();
    LuxuryDriver(const string &name, int id, int cap, bool hcp, double rating, bool open, bool pets,
                 const string &notes, int cargoCap, bool tv, bool phone, bool bar, bool partyLights, bool bluetooth,
                 bool wifi, const string& extras);

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
    void printDriver(vs& extra) override;

    /**
     * Gets the driver type in an integer
     * @return integer representing the type of driver
     */
    int getDriverType() override;

private:
    bool TV, phone, bar, partyLights, bluetooth, wifi;
    string extras;
public:
    const string &getExtras() const;

    void setExtras(const string &extras);

};

#endif //LUXURYDRIVER_H