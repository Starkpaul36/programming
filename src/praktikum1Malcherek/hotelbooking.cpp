#include<iostream>
#include "hotelbooking.h"

using namespace std;


hotelBooking::hotelBooking(std::string id, double price, std::string fromDate, std::string toDate, std::string hotel, std::string town, std::string type)
        :booking(id, price, fromDate, toDate), hotel(hotel), town(town)
{
    type = "Hotel";
}

std::string hotelBooking::showDetails()
{
    string print = "";
    print = "Hotelreservierung in " + hotel + " in " + town + " vom " + fromDtae + " bis " + toDate + " preis: " + to_string(price) +  " Euro";
            return print;
}
