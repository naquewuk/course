#ifndef VEHICLE_H
#define VEHICLE_H

#include "Transport.h"

class Vehicle : public Transport{
public:

    enum Body
    {
        Sedan = 1,
        Wagon,
        Cabriolet,
        Unknown
    };

    enum Section
    {
        A = 1, //Mini Cars,
        B, //Small Cars,
        C, //Medium Cars,
        D, //Large Cars,
        E, //Executive Cars,
        F, //Luxury Cars,
        J, //Sport Utility - SUV,
        M, //Multi Purpose Cars,
        S, //Sport Coupe
        U  //Unknown
    };

    Vehicle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort,
            int tmp_max_baggage, int tmp_passengersNumber, std::string tmp_seatUpholstery, Body tmp_body, Section tmp_section);

    ~Vehicle() {};

    int getMaxBaggage() const { return maxBaggage; }
    int getPassengersNumber() const { return passengersNumber; }
    std::string getSeatUpholstery () const { return seatUpholstery; }

    void setMaxBaggage(int m_max_baggage) { maxBaggage = m_max_baggage; }
    void setPassengersNumber(int m_passengers_number) { passengersNumber = m_passengers_number; }
    void setSeatUpholstery(std::string m_seat_upholstery) { seatUpholstery = m_seat_upholstery;}


    bool canTransport(int passengersnumber, int baggage) override;

    std::string Info() const override;

    Body getbody() const { return body; }
    void setBody(Body m_body) { body = m_body; }

    Section getSection() const { return section; }
    void setSection(Section m_section) { section = m_section; }

    static std::string wichBody(Body m_body);
    static std::string wichSection(Section m_section);

    int prior() const override;

protected:
    void checkInfo() override;

private:
    int maxBaggage;
    int passengersNumber;
    std::string seatUpholstery;

    Body body;
    Section section;
};

#endif

