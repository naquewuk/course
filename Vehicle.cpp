#include "Vehicle.h"

Vehicle::Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
                 int tmp_max_baggage, int tmp_passengers_number, std::string tmp_seat_upholstery,
                 Body tmp_body, Section tmp_section) :

        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed),
        max_baggage(tmp_max_baggage),
        passengers_number(tmp_passengers_number),
        seat_upholstery(tmp_seat_upholstery),
        body(tmp_body),
        section(tmp_section)

{
    type = Transport::Type::Vehicle;
    checkInfo();
}

std::string Vehicle::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << getbrand()
       << "\nModel: " << getmodel()
       << "\nMaxSpeed" << getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << getFuelConsumption()
       << "\nWeight of " << getbrand() << " is about " << getWeight()
       << "\nMax baggage: " << max_baggage
       << "\nPassengers number: " << passengers_number
       << "\nSeat upholstery type: " << seat_upholstery
       << "\nBody: " << wichBody(body)
       << "\nSection: " << wichSection(section);

    return ss.str();
}

std::string Vehicle::wichBody(Body m_body)
{
    switch (m_body) {
        case Vehicle::Sedan:
            return "Sedan";
            break;
        case Vehicle::Wagon:
            return "Wagon";
            break;
        case Vehicle::Cabriolet:
            return "Cabriolet";
            break;
        default:
            return "Unknown";
            break;
    }
}

std::string Vehicle::wichSection(Section m_section)
{
    switch (m_section){
        case Vehicle::A:
            return "Mini Car";
            break;
        case Vehicle::B:
            return "Small Car";
            break;
        case Vehicle::C:
            return "Medium Car";
            break;
        case Vehicle::D:
            return "Large Car";
            break;
        case Vehicle::E:
            return "Executive Car";
            break;
        case Vehicle::F:
            return "Luxury Car";
            break;
        case Vehicle::J:
            return "SUV(Sport Utility)";
            break;
        case Vehicle::M:
            return "Multi Purpose Car";
            break;
        case Vehicle::S:
            return "Sport Coupe";
        default:
            return "Unknown";
            break;
    }
}

void Vehicle::checkInfo() {

    Transport::checkInfo();

    if (max_baggage <= 0)
        throw std::invalid_argument("Error..\n Wrong max baggage.");

    if(passengers_number <= 0)
        throw std::invalid_argument("Error..\nWrong passengers number.");
}