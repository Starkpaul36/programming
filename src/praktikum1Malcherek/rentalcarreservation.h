#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include"booking.h"


class rentalcarReservation : public booking
{
public:
    rentalcarReservation(std::string company, std::string pickupLocation, std::string returnLocation, std::string type, std::string id, double price, std::string fromDate, std::string toDate);
    std::string showDetails()override;

private:
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;

};

#endif // RENTALCARRESERVATION_H
