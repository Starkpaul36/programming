#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include"booking.h"

class hotelBooking : public booking
{
public:
    hotelBooking(std::string id, double price, std::string fromDate, std::string toDate, std::string hotel, std::string town, std::string type);
    std::string showDetails()override;

private:
    std::string hotel;
    std::string town;
};

#endif // HOTELBOOKING_H
