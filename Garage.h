#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Transport.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Bus.h"

class Garage{
public:
    Garage() = default;
    ~Garage();

    void addTransport(Transport* transport);
    void removeTransport(int pos);

    bool isEmptyGarage() const;

    void printTransport() const;

    Transport* getTransport(int pos) const;
    Transport* editTransport(Transport* transport);

    int getTransportAmount() const { return availableTransport.size(); }

    Transport* takeCar(int passengersnumber, int baggage) const;

private:
    Vehicle* editVehicle(Vehicle* vehicle);
    Motorcycle* editMotorcycle(Motorcycle* motorcycle);
    Truck* editTruck(Truck* truck);
    Bus* editBus(Bus* bus);

    std::vector<Transport*> availableTransport;
};

#endif