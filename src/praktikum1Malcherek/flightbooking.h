#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include"booking.h"

class flightBooking : public booking
{
public:
    flightBooking(std::string id, double price, std::string fromDate, std::string toDate, std::string fromDestination, std::string toDestination, std::string airline, std::string type);
    std::string showDetails()override;


private:
    std::string fromDestination;
    std::string toDestination;
    std::string airline;
};

#endif // FLIGHTBOOKING_H
