MeanGreenEagleLift: main.o Pass.o Ride.o Driver.o Passes.o Rides.o Drivers.o Util.o EconomyDriver.o BasicDriver.o GroupDriver.o LuxuryDriver.o
	g++ -o MeanGreenEagleLift main.o Pass.o Ride.o Driver.o Passes.o Rides.o Drivers.o Util.o EconomyDriver.o BasicDriver.o GroupDriver.o LuxuryDriver.o

main.o: main.cpp Pass.h Ride.h Driver.h Passes.h Rides.h Drivers.h Util.h
	g++ -c main.cpp

Pass.o: Pass.cpp Util.h Pass.h Defs.h
	g++ -c Pass.cpp

Ride.o: Ride.cpp Util.h Ride.h Defs.h
	g++ -c Ride.cpp

Driver.o: Driver.cpp Util.h Driver.h Defs.h
	g++ -c Driver.cpp

Passes.o: Passes.cpp Util.h Pass.h
	g++ -c Passes.cpp

Rides.o: Rides.cpp Util.h Ride.h
	g++ -c Rides.cpp

Drivers.o: Drivers.cpp Util.h Driver.h
	g++ -c Drivers.cpp

Util.o: Util.cpp Pass.h Ride.h Driver.h Passes.h Rides.h Drivers.h Util.h Defs.h
	g++ -c Util.cpp

EconomyDriver.o: EconomyDriver.cpp Util.h EconomyDriver.h
	g++ -c EconomyDriver.cpp

BasicDriver.o: BasicDriver.cpp Util.h BasicDriver.h
	g++ -c BasicDriver.cpp

GroupDriver.o: GroupDriver.cpp Util.h GroupDriver.h
	g++ -c GroupDriver.cpp

LuxuryDriver.o: LuxuryDriver.cpp Util.h LuxuryDriver.h
	g++ -c LuxuryDriver.cpp

clean:
	rm MeanGreenEagleLift *.o

run:
	make && ./MeanGreenEagleLift