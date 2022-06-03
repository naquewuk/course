#include "Vehicle.h"

Vehicle::Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
                 int tmp_max_baggage, int tmp_passengers_number, std::string tmp_seat_upholstery):
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed),
        max_baggage(tmp_max_baggage),
        passengers_number(tmp_passengers_number),
        seat_upholstery(tmp_seat_upholstery)

{
    checkInfo();
}

std::string Vehicle::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << Transport::getbrand()
       << "\nModel: " << Transport::getmodel()
       << "\nMaxSpeed" << Transport::getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << Transport::getFuelConsumption()
       << "\nWeight of " << Transport::getbrand() << " is about " << Transport::getWeight()
       << "\nMax baggage: " << max_baggage
       << "\nPassengers number: " << passengers_number
       << "\nSeat upholstery type: " << seat_upholstery;
}

void Vehicle::checkInfo() {
    if (max_baggage <= 0)
        throw std::invalid_argument("Error..\n Wrong max baggage.");

    if(passengers_number <= 0)
        throw std::invalid_argument("Error..\nWrong passengers number.");
}