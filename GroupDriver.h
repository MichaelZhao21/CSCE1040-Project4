#ifndef GROUPDRIVER_H
#define GROUPDRIVER_H

#include "Defs.h"
#include "Driver.h"

enum NoiseLevel {SILENT, LOW, MEDIUM, HIGH, UNRESTRICTED};

class GroupDriver : public Driver {
public:
    /**
     * Constructor
     */
    GroupDriver();
    GroupDriver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
                const string &notes, int cargoCap, bool foodAllowed, bool extraLegRoom, bool recliningSeats,
                NoiseLevel noise);

    /**
     * Setters and getters
     */
    bool getFoodAllowed() const;
    void setFoodAllowed(bool foodAllowed);
    bool getExtraLegRoom() const;
    void setExtraLegRoom(bool extraLegRoom);
    bool getRecliningSeats() const;
    void setRecliningSeats(bool recliningSeats);
    NoiseLevel getNoise() const;
    void setNoise(NoiseLevel noise);

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
    bool foodAllowed, extraLegRoom, recliningSeats;
    NoiseLevel noise;

    /**
     * Converts the NoiseLevel enum to a string
     *
     * @param type - NoiseLevel enum
     * @return string
     */
    static string noiseLevelToString(NoiseLevel noise);
};

#endif //GROUPDRIVER_H