#pragma once

#include "Transport.h"

class Vehicle : public Transport{
public:

    enum Body
    {
        Sedan,
        Wagon,
        Cabriolet
    };

    enum Section
    {
        A, //Mini Cars,
        B, //Small Cars,
        C, //Medium Cars,
        D, //Large Cars,
        E, //Executive Cars,
        F, //Luxury Cars,
        J, //Sport Utility - SUV,
        M, //Multi Purposecars,
        S  //Sport Coupe
    };

    Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
            int tmp_max_baggage, int tmp_passengers_number, std::string tmp_seat_upholstery, Body tmp_body, Section tmp_section);

    int getmaxbaggage() const { return max_baggage; }
    int getpassengersnumber() const { return passengers_number; }
    std::string getseatupholstery () const { return seat_upholstery; }

    void setmaxbaggage(int m_max_baggage) { max_baggage = m_max_baggage; }
    void setpassengersnumber(int m_passengers_number) { passengers_number = m_passengers_number; }
    void setseatupholstery(std::string m_seat_upholstery) { seat_upholstery = m_seat_upholstery;}

    std::string Info() const override;

    Body getbody() const { return body; }
    Body setBody(Body m_body) { body = m_body; }

    Section getSection() const { return section; }
    Section setSection(Section m_section) { section = m_section; }

    static std::string wichBody(Body m_body);
    static std::string wichSection(Section m_section);

protected:
    void checkInfo() override;

private:
    int max_baggage;
    int passengers_number;
    std::string seat_upholstery;

    Body body;
    Section section;
};

