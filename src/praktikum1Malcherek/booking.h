#ifndef BOOKING_H
#define BOOKING_H
#include<string>


class booking
{
public:
    booking(std::string id, double price, std::string fromDate, std::string toDate);
    virtual std::string showDetails()=0;

protected:
   std::string id;
   double price;
   std::string fromDtae;
   std::string toDate;

};

#endif // BOOKING_H
