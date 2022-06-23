#include "Garage.h"

Garage::~Garage()
{
    for (auto transport : availableTransport)
    {
        delete transport;
    }
}

void Garage::addTransport(Transport* transport)
{
    availableTransport.push_back(transport);
}

void Garage::removeTransport(int pos)
{
    if( pos > availableTransport.size() || pos <= 0)
        throw std::invalid_argument("Wrong position!");

    else
        availableTransport.erase(availableTransport.begin() + pos - 1);
}

Transport* Garage::takeCar(int passengersnumber, int baggage,
                           std::function<int(Transport*)> f )
{
    std::sort(availableTransport.begin(), availableTransport.end(),
              [&f](Transport* const& a, Transport* const& b)->bool {
            return (f(a)) > (f(b));
            });
    for (const auto &item : this->availableTransport)
    {
        if(item->canTransport(passengersnumber, baggage))
        {
            return item;
        }
    }

    return nullptr;
}

bool Garage::isEmptyGarage() const
{
    return availableTransport.empty();
}

void Garage::printTransport() const
{
    int i = 1;
    for(auto transport : availableTransport){
        std::cout << i++ << ". " << std::setprecision(2) << std::fixed << transport->Info() << std::endl;
    }
}

Transport* Garage::getTransport(int pos) const
{
    return availableTransport[pos - 1];
}

Transport* Garage::editTransport(Transport* transport)
{
    Vehicle* vehicle = nullptr;
    Motorcycle* motorcycle = nullptr;
    Truck* truck = nullptr;
    Bus* bus = nullptr;

    std::cout << transport->Info();

    switch(transport->getType())
    {
        case Transport::Type::Vehicle:
            vehicle = dynamic_cast<Vehicle*>(transport);
            break;
        case Transport::Type::Motorcycle:
            motorcycle = dynamic_cast<Motorcycle*>(transport);
            break;
        case Transport::Type::Truck:
            truck = dynamic_cast<Truck*>(transport);
            break;
        case Transport::Type::Bus:
            bus = dynamic_cast<Bus*>(transport);
            break;
        default:
            throw std::invalid_argument("Error..\nUnknown Transport.");
            break;
    }

    if (vehicle != nullptr)
    {
        vehicle = editVehicle(vehicle);
        transport = vehicle;
    }
    else if (motorcycle != nullptr)
    {
        motorcycle = editMotorcycle(motorcycle);
        transport = motorcycle;
    }
    else if (truck != nullptr)
    {
        truck = editTruck(truck);
        transport = truck;
    }
    else if( bus != nullptr)
    {
        bus = editBus(bus);
        transport = bus;
    }

    return transport;
}

Vehicle* Garage::editVehicle(Vehicle* vehicle)
{
    char voice;

    std::string brand, model;
    int weight, fuelconsumption, maxspeed;

    int bodyIndex, sectionIndex;
    int maxbaggage, passengersnumber;
    std::string seatupholstery;

    Vehicle::Body body;
    Vehicle::Section section;

    std::cout << "Brand: " << vehicle->getBrand() << " Model: " << vehicle->getModel() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new brand and model: ";
        std::cout << "Brand: ";
        std::cout.flush();
        std::cin >> std::ws;
        std::getline(std::cin, brand);
        std::cout << "Model: ";
        std::getline(std::cin, model);
        vehicle->setBrand(brand);
        vehicle->setModel(model);
    }

    std::cout << "Weight: " << vehicle->getWeight() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new weight: ";
        std::cin >> weight;
        vehicle->setWeight(weight);
    }

    std::cout << "Max speed: " << vehicle->getMaxSpeed() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new max speed: ";
        std::cin >> maxspeed;
        vehicle->setMaxSpeed(maxspeed);
    }

    std::cout << "Fuel Consupmtion: " << vehicle->getFuelConsumption() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new fuel consumtion: ";
        std::cin >> fuelconsumption;
        vehicle->setFuelConsumtion(fuelconsumption);
    }

    std::cout << "Max baggage: " << vehicle->getMaxBaggage() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new Max baggage: ";
        std::cin >> maxbaggage;
        vehicle->setMaxBaggage(maxbaggage);
    }

    std::cout << "Max passengers number: " << vehicle->getPassengersNumber() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new Max passengers number: ";
        std::cin >> passengersnumber;
        vehicle->setPassengersNumber(passengersnumber);
    }

    std::cout << "Seat upholsety: " << vehicle->getSeatUpholstery() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new seat upholsery: ";
        std::cin >> seatupholstery;
        vehicle->setSeatUpholstery(seatupholstery);
    }

    std::cout << "Vehicle Body: " << Vehicle::wichBody(vehicle->getbody()) << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Body Type:\n1. Sedan.\n2. Wagon.\n3. Cabriolet.\nEnter number: ";
        std::cin >> bodyIndex;
        body = (bodyIndex <=3 && bodyIndex >= 1) ? static_cast<Vehicle::Body>(bodyIndex) : Vehicle::Body::Unknown;
        vehicle->setBody(body);
    }

    std::cout << "Vehicle Section: " << Vehicle::wichSection(vehicle->getSection()) << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Section:\n1. A - Mini Car.\n2. B - Small Car.\n3. C - Medium Car.\n4. D - Large Car.\n5. E - Executive Car."
                     "\n6. F - Luxury Car.\n7. J - Sport Utility - SUV.\n8. M - Multi Purpose Car.\n9. S - Sport Coupe." << std::endl;
        std::cout << "Enter number:";
        std::cin >> sectionIndex;
        section = (sectionIndex <= 9 && sectionIndex >= 1) ? static_cast<Vehicle::Section>(sectionIndex) : Vehicle::Section::U;
        vehicle->setSection(section);
    }

    return vehicle;
}

Motorcycle* Garage::editMotorcycle(Motorcycle* motorcycle)
{
    char voice;

    std::string brand, model;
    int weight, fuelconsumption, maxspeed;

    int stroller;
    bool strollerpresence;

    std::cout << "Brand: " << motorcycle->getBrand() << " Model: " << motorcycle->getModel() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::cout << "Model: ";
        std::getline(std::cin, model);
        motorcycle->setBrand(brand);
        motorcycle->setModel(model);
    }

    std::cout << "Weight: " << motorcycle->getWeight() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new weight: ";
        std::cin >> weight;
        motorcycle->setWeight(weight);
    }

    std::cout << "Max speed: " << motorcycle->getMaxSpeed() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new max speed: ";
        std::cin >> maxspeed;
        motorcycle->setMaxSpeed(maxspeed);
    }

    std::cout << "Fuel Consupmtion: " << motorcycle->getFuelConsumption() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new fuel consumtion: ";
        std::cin >> fuelconsumption;
        motorcycle->setFuelConsumtion(fuelconsumption);
    }

    std::cout << "Presence of stroller: " << motorcycle->getStrollerPresence() << " want to edit? y/n: ";
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "1. Yes.\nElse. No." << std::endl;
        std::cout << "Enter value: ";
        std::cin >> stroller;
        strollerpresence = (stroller == 1) ? true : false;
        motorcycle->setStrollerPresence(strollerpresence);
    }

    return motorcycle;
}

Truck* Garage::editTruck(Truck* truck)
{
    char voice;

    std::string brand, model;
    int weight, fuelconsumption, maxspeed;

    int carryingcapacity;

    std::cout << "Brand: " << truck->getBrand() << " Model: " << truck->getModel() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::cout << "Model: ";
        std::getline(std::cin, model);
        truck->setBrand(brand);
        truck->setModel(model);
    }

    std::cout << "Weight: " << truck->getWeight() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new weight: ";
        std::cin >> weight;
        truck->setWeight(weight);
    }

    std::cout << "Max speed: " << truck->getMaxSpeed() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new max speed: ";
        std::cin >> maxspeed;
        truck->setMaxSpeed(maxspeed);
    }

    std::cout << "Fuel Consupmtion: " << truck->getFuelConsumption() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new fuel consumtion: ";
        std::cin >> fuelconsumption;
        truck->setFuelConsumtion(fuelconsumption);
    }

    std::cout << "Carrying capacity: " << truck->getCarryingCapacity() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new carrying capacity: ";
        std::cin >> carryingcapacity;
        truck->setCarryingCapacity(carryingcapacity);
    }

    return truck;
}

Bus* Garage::editBus(Bus* bus)
{
    char voice;

    std::string brand, model;
    int weight, fuelconsumption, maxspeed;

    int passengersnumber;
    int seatingcomfort;
    int maxbaggageforpassenger;

    bool conditionpresense;
    int condition;

    bool recliningseats;
    int seats;

    std::cout << "Brand: " << bus->getBrand() << " Model: " << bus->getModel() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Brand: ";
        std::getline(std::cin, brand);
        std::cout << "Model: ";
        std::getline(std::cin, model);
        bus->setBrand(brand);
        bus->setModel(model);
    }

    std::cout << "Weight: " << bus->getWeight() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new weight: ";
        std::cin >> weight;
        bus->setWeight(weight);
    }

    std::cout << "Max speed: " << bus->getMaxSpeed() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new max speed: ";
        std::cin >> maxspeed;
        bus->setMaxSpeed(maxspeed);
    }

    std::cout << "Fuel Consupmtion: " << bus->getFuelConsumption() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new fuel consumtion: ";
        std::cin >> fuelconsumption;
        bus->setFuelConsumtion(fuelconsumption);
    }

    std::cout << "Passengers number: " << bus->getPassengersNumber() << " want to edit? y/n: ";
    std::cin >> voice;
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new passengers number: ";
        std::cin >> passengersnumber;
        bus->setPassengersNumber(passengersnumber);
    }

    std::cout << "Presence of condition: " << bus->getConditionPresense() << " want to edit? y/n: ";
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "1. Yes.\nElse. No." << std::endl;
        std::cout << "Enter value: ";
        std::cin >> condition;
        conditionpresense = (condition == 1) ? true : false;
        bus->setConditionPresense(conditionpresense);
    }

    std::cout << "Presence of reclining seats: " << bus->getRecliningSeats() << " want to edit? y/n: ";
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "1. Yes.\nElse. No." << std::endl;
        std::cout << "Enter value: ";
        std::cin >> seats;
        recliningseats = (seats == 1) ? true : false;
        bus->setRecliningSeats(recliningseats);
    }

    std::cout << "Seating comfort: " << bus->getSeatingComfort() << " want to edit? y/n: ";
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new seating comfort: ";
        std::cin >> seatingcomfort;
        bus->setSeatingComfort(seatingcomfort);
    }

    std::cout << "Max baggage for one passenger: " << bus->getMaxBaggageForPassenger() << " want to edit? y/n: ";
    if(voice == 'Y' || voice == 'y')
    {
        std::cout << "Enter new max baggage for one passenger: ";
        std::cin >> maxbaggageforpassenger;
        bus->setMaxBaggageForPassenger(maxbaggageforpassenger);
    }

    return bus;
}




