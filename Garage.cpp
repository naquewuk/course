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

bool Garage::isEmptyGarage() const
{
    return availableTransport.empty();
}

void Garage::printTransport() const
{
    int i = 1;
    for(auto transport : availableTransport){
        std::cout << i++ << " " << std::setprecision(2) << std::fixed << transport->Info() << std::endl;
    }
}

Transport* Garage::getTransport(int pos) const
{
    return availableTransport[pos - 1];
}

Transport* Garage::editTransport(Transport *transport)
{
    
}

