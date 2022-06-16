#include "Vehicle.h"

Vehicle::Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort,
                 int tmp_maxBaggage, int tmp_passengersNumber, std::string tmp_seatUpholstery,
                 Body tmp_body, Section tmp_section) :

        Transport(tmp_brand, tmp_model, tmp_weight, tmp_maxSpeed, tmp_fuelConsumption, tmp_comfort),
        maxBaggage(tmp_maxBaggage),
        passengersNumber(tmp_passengersNumber),
        seatUpholstery(tmp_seatUpholstery),
        body(tmp_body),
        section(tmp_section)

{
    type = Transport::Type::Vehicle;
    checkInfo();
}

std::string Vehicle::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << getBrand()
       << "\nModel: " << getModel()
       << "\nMaxSpeed: " << getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << getFuelConsumption()
       << "\nWeight of " << getBrand() << " is about " << getWeight()
       << "\nMax baggage: " << maxBaggage
       << "\nPassengers number: " << passengersNumber
       << "\nSeat upholstery type: " << seatUpholstery
       << "\nBody: " << wichBody(body)
       << "\nSection: " << wichSection(section)
       << "\nComfort (max: 70): " << getComfort() ;

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
            break;

        default:
            return "Unknown";
            break;
    }
}

void Vehicle::checkInfo() {

    Transport::checkInfo();

    if (maxBaggage <= 0)
        throw std::invalid_argument("Error..\n Wrong max baggage.");

    if(passengersNumber <= 0)
        throw std::invalid_argument("Error..\nWrong passengers number.");
}