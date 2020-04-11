#ifndef DRIVER_H
#define DRIVER_H

#include "Defs.h"

enum VehicleType {COMPACT_2_DR = 1, SEDAN_4_DR, SUV, VAN, OTHER};

class Driver {
public:
    /**
     * Constructors
     */
    Driver();
    Driver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
           const string &notes, int cargoCap);

    /**
     * Getters and setters
     */
    const string &getName() const;
    void setName(const string &name);
    int getId() const;
    void setId(int id);
    int getCap() const;
    void setCap(int cap);
    bool getHcp() const;
    void setHcp(bool hcp);
    VehicleType getType() const;
    void setType(VehicleType type);
    double getRating() const;
    void setRating(double rating);
    bool getOpen() const;
    void setOpen(bool open);
    bool getPets() const;
    void setPets(bool pets);
    const string &getNotes() const;
    void setNotes(const string &notes);
    int getCargoCap() const;
    void setCargoCap(int cargoCap);

    /**
     * Prints the driver
     */
    virtual void printDriver();

    /**
     * Gets the minimum and maximum capacity
     * of the type of driver
     * @return pair of ints representing [min, max]
     */
    virtual pair<int, int> getCapacityRange() = 0;

protected:
    string name, notes;
    int id, cap, cargoCap;
    double rating;
    bool hcp, open, pets;
    VehicleType type;

    /**
     * Converts the VehicleType enum to a string
     *
     * @param type - VehicleType enum
     * @return string
     */
    static string vehicleTypeToString(VehicleType type);
};

#endif //DRIVER_H