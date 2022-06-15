#include <iostream>
#include <iomanip>
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
                            std::cout << "1. Vehcile." << std::endl;
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

                                    std::cout << "Enter all fiels for Vehicle." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "\nModel: ";
                                    std::getline(std::cin, model);
                                    std::cout << "\nWeight: ";
                                    std::cin >> weight;
                                    std::cout << "\nMax speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "\nFuel Consumption: ";
                                    std::cin >> fuelconsumption;

                                    comfort += (fuelconsumption < )

                                    std::cout << "\nMax baggage: ";
                                    std::cin >> maxbaggage;
                                    if(maxbaggage > 100)
                                        comfort += 20;

                                    std::cout << "\nMax passenger number: ";
                                    std::cin >> passengersnumber;
                                    if(passengersnumber > 4)
                                        comfort += 15;

                                    std::cout << "\nSeat Upholsery";
                                    std::getline(std::cin, seatupholsery);
                                    std::cout << "\nBody type:\n1. Sedan.\n2. Wagon.\n3. Cabriolet" << std::endl;
                                    std::cin >> enterbody;
                                    body = (enterbody <= 3 && enterbody >= 1) ? static_cast<Vehicle::Body>(enterbody) : Vehicle::Unknown;
                                    std::cout << "Section:\n1. A - Mini Car.\n2. B - Small Car.\n3. C - Medium Car.\n4. D - Large Car.\n5. E - Executive Car."
                                                 "\n6. F - Luxury Car.\n7. J - Sport Utility - SUV.\n8. M - Multi Purpose Car.\n9. S - Sport Coupe." << std::endl;
                                    std::cin >> entersection;
                                    if(enterbody == 6)
                                        comfort += 15;

                                    else if(enterbody == 8)
                                        comfort += 10;

                                    else if(enterbody == 9)
                                        comfort += 20;

                                    section = (entersection <= 9 && entersection >= 1) ? static_cast<Vehicle::Section>(entersection) :Vehicle::U;

                                    transport = new Vehicle(brand, model, weight, maxspeed, fuelconsumption, maxbaggage, passengersnumber, seatupholsery, body, section);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                case 2: // add Motorcycle
                                {
                                    bool strollerpresence;
                                    char strollerPresence;
                                    int comfort = 20;

                                    std::cout << "Enter all fields for Motorcycle." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "\nModel: ";
                                    std::getline(std::cin, model);
                                    std::cout << "\nWeight: ";
                                    std::cin >> weight;
                                    std::cout << "\nMax speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "\nFuel Consumption: ";
                                    std::cin >> fuelconsumption;

                                    comfort += (fuelconsumption < 10) ? 10 : 0;

                                    std::cout << "\nStroller Presence y/n: ";
                                    std::cin >> strollerPresence;
                                    strollerpresence = (strollerPresence == 'y'|| strollerPresence == 'Y') ? true : false;

                                    comfort += (strollerpresence && maxspeed < 200) ? 10 : 0;

                                    transport = new Motorcycle(brand, model, weight, maxspeed, fuelconsumption, strollerpresence);
                                    garage.addTransport(transport);
                                    system("cls");
                                    break;
                                }

                                case 3: // add Truck
                                {
                                    int carryingcapacity;

                                    std::cout << "Enter all fiels for Truck." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "\nModel: ";
                                    std::getline(std::cin, model);
                                    std::cout << "\nWeight: ";
                                    std::cin >> weight;
                                    std::cout << "\nMax speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "\nFuel Consumption: ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "\nCarrying capacity: ";
                                    std::cin >> carryingcapacity;

                                    transport = new Truck(brand, model, weight, maxspeed, fuelconsumption, carryingcapacity);
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

                                    std::cout << "Enter all fiels for Bus." << std::endl;
                                    std::cout << "Brand:";
                                    std::cin.ignore();
                                    std::getline(std::cin, brand);
                                    std::cout << "\nModel: ";
                                    std::getline(std::cin, model);
                                    std::cout << "\nWeight: ";
                                    std::cin >> weight;
                                    std::cout << "\nMax speed: ";
                                    std::cin >> maxspeed;
                                    std::cout << "\nFuel Consumption: ";
                                    std::cin >> fuelconsumption;
                                    std::cout << "\nPassengers number: ";
                                    std::cin >> passengersnumber;
                                    std::cout << "\nCondition Presence y/n: ";
                                    std::cin >> conditionPresense;
                                    conditionpresense = (conditionPresense == 'Y' || conditionPresense == 'y' ) ? true : false;
                                    std::cout << "\nReclining seats y/n: ";
                                    std::cin >> recliningSeats;
                                    recliningseats = (conditionPresense == 'Y' || conditionPresense == 'y') ? true : false;
                                    std::cout << "Seating comfort: ";
                                    std::cin >> seatingcomfort;
                                    std::cout << "Max baggage for passenger: ";
                                    std::cin >> maxbaggageforpassenger;

                                    transport = new Bus(brand, model, weight, maxspeed, fuelconsumption,
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
                                int position;
                                garage.printTransport();
                                std::cout << "Choose what you want to remove: " << std::endl;
                                std::cin >> position;

                                garage.removeTransport(position);
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
                                std::cout << "0. Exit\nEnter position which Transport: ";
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
                         std::cout << "Welcome to my garage." << std::endl;
                         std::cout << "Wanna do smth?\nFor Example: " << std::endl;
                         std::cout << "1. You can take car." << std::endl;
                         std::cout << "2. We can select a car for you. "<< std::endl;
                     }
                }

            }
        } catch (const std::exception& ex){
            std::cerr << ex.what() << std::endl;
        }

    }
    return 0;
}