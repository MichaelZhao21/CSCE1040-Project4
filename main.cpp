/**
 * Name:        Michael Zhao (michaelzhao314@gmail.com)
 * Date:        4/18/2020
 * Instructor:  David Keathly
 * Description: This project is a simulation of a real system used to schedule drivers
 *              and passengers using a transaction-based class system. The system can
 *              create schedules, manage rides, and automatically checks for requirements
 *              before allocating drivers to passengers. Additionally, it has a save and
 *              load system as well as input checking. The biggest change I've made is that
 *              there are actually 4 derived classes for drivers! They can pick their own driver
 *              type and the program actually uses runtime polymorphism to access these drivers.
 */

#include "Util.h"
using namespace std;

int main() {
    // Declare collector objects
    Drivers drivers;
    Passes passes;
    Rides rides;

    // Load :P
    Util::load(drivers, passes, rides);

    // Menu system loop
    Util::mainLoop(drivers, passes, rides);

    // Save :DD
    Util::save(drivers, passes, rides);

    // Don't forget this!!!
    return 0;
}