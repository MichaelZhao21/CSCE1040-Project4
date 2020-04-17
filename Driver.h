#ifndef DRIVER_H
#define DRIVER_H

#include "Defs.h"

class Driver {
public:
    /**
     * Constructors and Destructor
     */
    Driver();
    Driver(const string &name, int id, int cap, bool hcp, double rating, bool open, bool pets,
           const string &notes, int cargoCap);
    virtual ~Driver() = default;

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
    virtual void printDriver(vs& extra);

    /**
     * Gets the driver type in an integer
     * @return integer representing the type of driver
     */
    virtual int getDriverType() = 0;

protected:
    string name, notes;
    int id, cap, cargoCap;
    double rating;
    bool hcp, open, pets;
};

#endif //DRIVER_H