#pragma once

#include "Transport.h"

class Vehicle : public Transport{
public:
    Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
            int tmp_max_baggage, int tmp_passengers_number, std::string tmp_seat_upholstery);

    ~Vehicle() {};

    int getmaxbaggage() const { return max_baggage; }
    int getpassengersnumber() const { return passengers_number; }
    std::string getseatupholstery () const { return seat_upholstery; }

    void setmaxbaggage(int m_max_baggage) { max_baggage = m_max_baggage; }
    void setpassengersnumber(int m_passengers_number) { passengers_number = m_passengers_number; }
    void setseatupholstery( std::string m_seat_upholstery) { seat_upholstery = m_seat_upholstery;}

    std::string Info() const override;

    enum Body
    {
        Sedan,
        Wagon,
        Cabriolet
    };

    enum Class
    {
        A_MiniCars,
        B_SmallCars,
        C_MediumCars,
        D_LargerCars,
        E_ExecutiveCars,
        F_LuxuryCars,
        J_SportUtilitySUV,
        M_MultiPurposecars,
        S_SportCoupe,
        Unknown
    };

    Body getbody() const { return body; }
    Class getclass() const { return type; }

protected:
    void checkInfo() override;

    Body body;
    Class type;

private:
    int max_baggage;
    int passengers_number;
    std::string seat_upholstery;
};

