#include <iostream>
#include <memory>
#include <stdexcept>
#include "Garage.h"
#include "Transport.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Bus.h"

int main()
{
    int num;
    Garage garage;
    Transport* transport = nullptr;
    std::string brand;
    std::string model;
    int weight, maxspeed, fuelconsumption;

    while (true)
    {
        std::cout << "Choose role:" << std::endl;
        std::cout << "1. Admin." << std::endl;
        std::cout << "2. User." << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> num;
        system("cls");

        try{
            bool exit = false;
            switch (num) {
                case 1: // Choose Admin
                {
                    int num1;
                    std::cout << "Welcome, Admin." << std::endl;
                    std::cout << "Choose your next step:" << std::endl;
                    std::cout << "1. Add transport."<< std::endl;
                    std::cout << "2. Remove transport."<< std::endl;
                    std::cout << "3. Edit transport."<< std::endl;
                    std::cout << "4. Print all available transport."<< std::endl;
                    std::cout << "0. Exit."<< std::endl;
                    std::cin >> num1;
                    system("cls");

                    switch (num1) {
                        case 1:  // Add Transport
                        {
                            int num2;
                            std::cout << "1. Vehicle." << std::endl;
                            std::cout << "2. Motorcycle." << std::endl;
                            std::cout << "3. Truck. " << std::endl;
                            std::cout << "4. Bus." << std::endl;
                            std::cin >> num2;
                            system("cls");

                            switch (num2)
                            {
                                case 1: // add Vehicle
                                {
                                    int maxbaggage, passengersnumber;
                                    std::string seatupholsery;
                                    Vehicle::Body body;
                                    int enterbody;
                                    Vehicle::Section section;
                                    int entersection;
                                    int comfort = 20;

                                    std::cout << "Enter all fields for Vehicle.\n";
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "Model: ";
                                    std::getline(std::cin, model);
                                    std::cout << "Weight (in kg): ";
                                    std::cin >> weight;
                                    std::cout << "Max speed (km/h): ";
                                    std::cin >> maxspeed;
                                    std::cout << "Fuel Consumption(per 100 km): ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "Max baggage (in kg): ";
                                    std::cin >> maxbaggage;
                                    std::cout << "Max passenger number: ";
                                    std::cin >> passengersnumber;
                                    std::cout << "Seat Upholsery: ";
                                    std::cin >> seatupholsery;
                                    std::cout << "Body type:\n1. Sedan.\n2. Wagon.\n3. Cabriolet" << std::endl;
                                    std::cin >> enterbody;
                                    body = (enterbody <= 3 && enterbody >= 1) ? static_cast<Vehicle::Body>(enterbody) : Vehicle::Unknown;
                                    std::cout << "Section:\n1. A - Mini Car.\n2. B - Small Car.\n3. C - Medium Car.\n4. D - Large Car.\n5. E - Executive Car."
                                                 "\n6. F - Luxury Car.\n7. J - Sport Utility - SUV.\n8. M - Multi Purpose Car.\n9. S - Sport Coupe." << std::endl;
                                    std::cin >> entersection;
                                    section = (entersection <= 9 && entersection >= 1) ? static_cast<Vehicle::Section>(entersection) : Vehicle::U;

                                    comfort += (fuelconsumption < 20) ? 10 : 0;
                                    comfort += (maxbaggage > 100) ? 15 : 10;
                                    comfort += (passengersnumber > 4 && (entersection == 7 || entersection == 8)) ? 15 : 0;

                                    transport = new Vehicle(brand, model, weight, maxspeed, fuelconsumption, comfort, maxbaggage, passengersnumber, seatupholsery, body, section);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                case 2: // add Motorcycle
                                {
                                    bool strollerpresence;
                                    char strollerPresence;
                                    int comfort = 20;

                                    std::cout << "Enter all fields for Motorcycle" << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "Model: ";
                                    std::getline(std::cin, model);
                                    std::cout << "Weight: ";
                                    std::cin >> weight;
                                    std::cout << "Max speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "Fuel Consumption(per 100 km): ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "Stroller Presence y/n: ";
                                    std::cin >> strollerPresence;
                                    strollerpresence = (strollerPresence == 'y'|| strollerPresence == 'Y') ? true : false;

                                    comfort += (fuelconsumption < 10) ? 15 : 0;
                                    comfort += (strollerpresence && maxspeed < 250) ? 15 : 0;

                                    transport = new Motorcycle(brand, model, weight, maxspeed, fuelconsumption, comfort, strollerpresence);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                case 3: // add Truck
                                {
                                    int carryingcapacity;
                                    int comfort = 0;
                                    std::cout << "Enter all fields for Truck." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "Model: ";
                                    std::getline(std::cin, model);
                                    std::cout << "Weight (kg): ";
                                    std::cin >> weight;
                                    std::cout << "Max speed (km/h): ";
                                    std::cin >> maxspeed;
                                    std::cout << "Fuel Consumption(per 100 km): ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "Carrying capacity: ";
                                    std::cin >> carryingcapacity;

                                    transport = new Truck(brand, model, weight, maxspeed, fuelconsumption, comfort,  carryingcapacity);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                case 4: // add Bus
                                {
                                    int passengersnumber;
                                    bool conditionpresense;
                                    char conditionPresense;
                                    bool recliningseats;
                                    char recliningSeats;
                                    int seatingcomfort;
                                    int maxbaggageforpassenger;

                                    int comfort = 20;

                                    std::cout << "Enter all fields for Bus." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "Model: ";
                                    std::getline(std::cin, model);
                                    std::cout << "Weight: ";
                                    std::cin >> weight;
                                    std::cout << "Max speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "Fuel Consumption: ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "Passengers number: ";
                                    std::cin >> passengersnumber;
                                    std::cout << "Condition Presence y/n: ";
                                    std::cin >> conditionPresense;
                                    conditionpresense = (conditionPresense == 'Y' || conditionPresense == 'y' ) ? true : false;
                                    std::cout << "Reclining seats y/n: ";
                                    std::cin >> recliningSeats;
                                    recliningseats = (recliningSeats == 'Y' || recliningSeats == 'y') ? true : false;
                                    std::cout << "Seating comfort(0-100 ): ";
                                    std::cin >> seatingcomfort;
                                    std::cout << "Max baggage for passenger: ";
                                    std::cin >> maxbaggageforpassenger;

                                    comfort += (passengersnumber > 20 && passengersnumber < 50) ? 10 : 0;
                                    comfort += (conditionpresense = true) ? 15 : -5;
                                    comfort += (recliningseats == true) ? 10 : 0;
                                    comfort += (seatingcomfort >= 0 && seatingcomfort <= 25) ? -5 :
                                            (seatingcomfort > 25 && seatingcomfort <= 50) ? 0 :
                                            (seatingcomfort > 50 && seatingcomfort <= 75) ? 5 : 10;
                                    comfort += (maxbaggageforpassenger > 6) ? 10 : 0;

                                    transport = new Bus(brand, model, weight, maxspeed, fuelconsumption, comfort,
                                                        passengersnumber, conditionpresense, recliningseats, seatingcomfort,
                                                        maxbaggageforpassenger);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                default:
                                    break;
                            }
                            break;
                        }

                        case 2: // Remove Transport
                        {
                            if(garage.isEmptyGarage() != true)
                            {
                                int pos = 0;
                                garage.printTransport();
                                std::cout << "0. Exit\nEnter: ";
                                std::cin >> pos;

                                garage.removeTransport(pos);
                                system("cls");
                            }

                            else
                            {
                                std::cout << "Garage is empty. " << std::endl;
                            }
                            break;
                        }

                        case 3: // Edit Transport
                        {
                            if(garage.isEmptyGarage() != true)
                            {
                                int pos = 0;
                                garage.printTransport();
                                std::cout << "0. Exit\nEnter: ";
                                std::cin >> pos;

                                if(pos < 0 || pos > garage.getTransportAmount())
                                    throw std::invalid_argument("Error...\nWrong transport position.");

                                else if(pos == 0)
                                    break;

                                else
                                {
                                    transport = garage.getTransport(pos);
                                    garage.removeTransport(pos);
                                    system("cls");
                                    garage.addTransport(garage.editTransport(transport));
                                    system("cls");

                                }
                            }
                            else
                                std::cout << "Garage is empty. " << std::endl;
                            break;

                        }

                        case 4: //Print Transport
                        {
                            if(garage.isEmptyGarage() != true)
                                garage.printTransport();
                            else
                                std::cout << "Garage is empty. "<< std::endl;
                            break;
                        }

                        case 0:
                            break;

                        default:
                            break;
                    }

                    break;
                }

                case 2: // User

                {
                     if(garage.isEmptyGarage() == true)
                         std::cout << "Welcome to my garage. I am sorry, but garage is empty." << std::endl;

                     else
                     {
                         int num2;
                         std::cout << "Welcome to my garage." << std::endl;
                         std::cout << "Wanna do smth?\nFor Example: " << std::endl;
                         std::cout << "1. You can take car." << std::endl;
                         std::cout << "2. We can select a car for you. "<< std::endl;
                         std::cout << "0. Exit\nEnter: ";
                         std::cin >> num2;

                         switch(num2)
                         {
                             case 1:
                             {
                                 int pos;
                                 garage.printTransport();
                                 std::cout << "Enter the number of a transport: " << std::endl;
                                 std::cout << "0. Exit\nEnter: ";
                                 std::cin >> pos;

                                 if( pos > garage.getTransportAmount() || pos < 0)
                                     throw std::invalid_argument("Error..\nWrong position!");

                                 else if(pos == 0)
                                     break;

                                 else
                                 {
                                     std::cout << "You choose " << brand << " " << model << std::endl;
                                     std::cout << "Have a good ride. Be carefully!" << std::endl;
                                 }
                                 break;
                             }

                             case 2:
                             {
                                 Transport* m_transport;
                                 int passengersnumber, baggage;
                                 int pos;
                                 std::cout << "Enter please. How many of you?: ";
                                 std::cin >> passengersnumber;

                                 std::cout << "Enter please. How much baggage with you?:" ;
                                 std::cin >> baggage;
                                 std::cout << "Select mode:\n1.Choose by prority\n2.Choose by comfort" << std::endl;
                                 std::cin >> pos;
                                 if (pos == 2)
                                     m_transport = garage.takeCar(passengersnumber, baggage,
                                                                  [](Transport* t){return t->getComfort();});
                                 else
                                     m_transport = garage.takeCar(passengersnumber, baggage);

                                 if(m_transport)
                                 {
                                     std::cout << m_transport->Info() << std::endl;
                                     std::cout << "Good luck!" << std::endl;
                                 }
                                 else
                                     std::cout << "Transport don't found";

                                 break;
                             }

                             case 0:
                                 break;

                             default:
                                 break;

                         }
                     }
                     break;
                }

                case 0:
                    exit = true;
                    break;

                default:
                    break;
            }
            if(exit)
            {
                break;
            }
        } catch (const std::exception& ex){
            std::cerr << ex.what() << std::endl;
        }

    }
    return 0;
}