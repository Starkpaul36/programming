#include<iostream>
#include "rentalcarreservation.h"

using namespace std;

rentalcarReservation::rentalcarReservation(std::string company, std::string pickupLocation, std::string returnLocation, std::string type, std::string id, double price, std::string fromDate, std::string toDate)
        :booking(id, price, fromDate, toDate), pickupLocation(pickupLocation), returnLocation(returnLocation), company(company)
{
    type = "RentalCar";
}

std::string rentalcarReservation::showDetails()
{
    string print = "";
    print ="Mietwagenreservierung mit " +  company + ". Abholung am " + fromDtae + " in " + pickupLocation + ". Rueckgabe am " + toDate + " in " + returnLocation + ". Preis: " + to_string(price) + " Euro";
    return print;
}
