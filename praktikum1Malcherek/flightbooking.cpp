#include<iostream>
#include "flightbooking.h"

using namespace std;

flightBooking::flightBooking(std::string id, double price, std::string fromDate, std::string toDate, std::string fromDestination, std::string toDestination, std::string airline, std::string type)
        :booking(id, price, fromDate, toDate), fromDestination(fromDestination), toDestination(toDestination), airline(airline)
{
    type = "Flight";
}

std::string flightBooking::showDetails()
{
    string print = "";
    print = "Flugbuchung von " + fromDestination + " nach " +toDestination + " mit " + airline + " am " + fromDtae + " Preis: " + to_string( price) +  " Euro";
    return print;
}


