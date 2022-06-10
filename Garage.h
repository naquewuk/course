#pragma once

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
    Transport* editTransport(Transport* transport) const;

    int getTransportAmount() const { return availableTransport.size(); }

private:
    Vehicle* editVehicle(Vehicle* vehicle);
    Motorcycle* editMotorcycle(Motorcycle* motorcycle);
    Truck* editTruck(Truck* truck);
    Bus* editBus(Bus* bus);

    std::vector<Transport*> availableTransport;
};
