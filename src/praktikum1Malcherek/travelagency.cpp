#include<iostream>
//#include<QJsonDocument>
#include "json.hpp"
#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
using namespace nlohmann;
using namespace std;

travelAgency::travelAgency()
{

}

travelAgency::~travelAgency()
{

    for(auto& item:Bookings)
        delete item;

}

void travelAgency::readFile()
{
    string id, fromDate, toDate, fromDestination, toDestination, airline, hotel, town, pickupLocation, returnLocation, company, type;
    double price;
    double flightpreis = 0.0;
    int anzahlflight = 0;
    double hotelpreis = 0.0;
    int anzahlhotel = 0;
    double rentalpreis = 0.0;
    int anzahlrental = 0;

    ifstream outputstream("bookings.json");

    if(!outputstream)
        throw std::runtime_error("Datei konnte nicht geoeffnet werden");
    //cerr<<"Datei konnte nicht geoffnet werden"<<endl;

    json data;



    outputstream >> data;

    for(auto& item: data){
        if(item["type"] =="")
            throw std::runtime_error("Attribut darf nicht leer sein");
        if(item["type"] == "Flight"){
            airline = item["airline"];
            fromDate = item["fromDate"];
            fromDestination = item["fromDest"];
            id = item["id"];
            price = item["price"].get<double>();
            toDate = item["toDate"];
            toDestination = item["toDest"];
            type = item["type"];

            if(airline.empty() || fromDate.empty() || fromDestination.empty() || id.empty() || toDate.empty() || toDestination.empty())
                throw std::runtime_error("Ein oder mehrere Attribute sind leer!");
            if(price <= 0.0)
                throw std::runtime_error("Ungueltiger Preiswert!");
            if(fromDestination.length() !=3 || toDestination.length() != 3)
                throw std::runtime_error("Ungültiges Flughafenkürzel!");


            anzahlflight++;
            flightpreis += price;
            flightBooking* Flight = new flightBooking(id, price, fromDate, toDate, fromDestination, toDestination, airline, type);
            Bookings.push_back(Flight);
        }else if(item["type"] == "Hotel"){
            fromDate = item["fromDate"];
            hotel = item["hotel"];
            id = item["id"];
            price = item["price"].get<double>();
            toDate = item["toDate"];
            town = item["town"];
            type = item["type"];

            if(fromDate.empty() || hotel.empty() || id.empty() ||  toDate.empty() || town.empty())
                throw std::runtime_error("Ein oder mehrere Attribute sind leer!");
            if(price <= 0.0)
                throw std::runtime_error("Ungueltiger Preiswert!");


            anzahlhotel++;
            hotelpreis +=price;
            hotelBooking* Hotel = new hotelBooking(id, price, fromDate, toDate, hotel, town, type);
            Bookings.push_back(Hotel);
        }else{
            company = item["company"];
            fromDate = item["fromDate"];
            id = item["id"];
            pickupLocation = item["pickupLocation"];
            price = item["price"].get<double>();
            returnLocation = item["returnLocation"];
            toDate = item["toDate"];
            type = item["type"];

            if(company.empty() || fromDate.empty() ||  id.empty() || pickupLocation.empty() || returnLocation.empty() ||  toDate.empty())
                throw std::runtime_error("Ein oder mehrere Attribute sind leer!");
            if(price <= 0.0)
                throw std::runtime_error("Ungueltiger Preiswert!");

            anzahlrental++;
            rentalpreis +=price;
            rentalcarReservation* Rental = new rentalcarReservation(company, pickupLocation, returnLocation, type, id, price, fromDate, toDate);
        }

    }
    cout<<"Es wurden "<<anzahlflight<<" Flugbuchungen im Wert von "<<flightpreis<<"Euro "<< anzahlrental<<
          " Mietwagenbuchungen im Wert von "<<rentalpreis<<" Euro und "<<anzahlhotel<<" Hotelreservierungen im Wert von"<<hotelpreis<<" Euro angelegt"<<endl;

}

void travelAgency::readBinaryFile()
{
    const string& outputFileName = "bookingsBinary.bin";
    ifstream outputFilestream(outputFileName.c_str(),std::ios::binary);
    if (!outputFilestream){
        cerr << outputFileName << " kann nicht geoeffnet werden!\n";
    }

    char type;
    char id[39];
    double preis;
    char fromDate[9];
    char toDate[9];
    char fromDest[4];
    char toDest[4];
    char airline[16];
    char pickupLocation[16];
    char returnLocation[16];
    char company[16];
    char hotel[16];
    char town[16];

    double flightpreis = 0.0;
    int anzahlflight = 0;
    double hotelpreis = 0.0;
    int anzahlhotel = 0;
    double rentalpreis = 0.0;
    int anzahlrental = 0;
    int length;



    // outputFilestream.seekg(0);
    do{
        outputFilestream.read(&type, sizeof(char));
        string string_type(1, type);
        if (outputFilestream.eof())
            break;

        outputFilestream.read(reinterpret_cast<char*>(id), 38);
        id[38] = '\0';
        length = sizeof(id) / sizeof(id[0]);
        string string_id(id, length);

        outputFilestream.read(reinterpret_cast<char*>(&preis), sizeof(preis));

        outputFilestream.read(reinterpret_cast<char*>(fromDate), 8);
        fromDate[8] = '\0';
        length = sizeof(fromDate) / sizeof(fromDate[0]);
        string string_fromDate(fromDate, length);

        outputFilestream.read(reinterpret_cast<char*>(toDate), 8);
        toDate[8] = '\0';
        length = sizeof(toDate) / sizeof(toDate[0]);
        string string_toDate(toDate, length);


        if(type == 'F'){


            outputFilestream.read(reinterpret_cast<char*>(fromDest), 3);
            fromDest[3] = '\0';
            length = sizeof(fromDest) / sizeof(fromDest[0]);
            string string_fromDest(fromDest, length);

            outputFilestream.read(reinterpret_cast<char*>(toDest), 3);
            toDest[3] = '\0';
            length = sizeof(toDest) / sizeof(toDest[0]);
            string string_toDest(toDest, length);

            outputFilestream.read(reinterpret_cast<char*>(airline), 15);
            airline[15] = '\0';
            length = sizeof(airline) / sizeof(airline[0]);
            string string_airline(airline, length);


            anzahlflight++;
            flightpreis += preis;
            flightBooking* Flight = new flightBooking(string_id, preis, string_fromDate, string_toDate, string_fromDest, string_toDest, string_airline, string_type);
            Bookings.push_back(Flight);

        }else if(type == 'H'){

            outputFilestream.read(reinterpret_cast<char*>(hotel), 15);
            hotel[15] = '\0';
            length = sizeof(hotel) / sizeof(hotel[0]);
            string string_hotel(hotel, length);

            outputFilestream.read(reinterpret_cast<char*>(town), 15);
            town[15] = '\0';
            length = sizeof(town) / sizeof(town[0]);
            string string_town(town, length);

            cout<<type<<endl;
            anzahlhotel++;
            hotelpreis +=preis;
            hotelBooking* Hotel = new hotelBooking(string_id, preis, string_fromDate, string_toDate, string_hotel, string_town, string_type);
            Bookings.push_back(Hotel);
        }else{

            outputFilestream.read(reinterpret_cast<char*>(pickupLocation), 15);
            pickupLocation[15] = '\0';
            length = sizeof(pickupLocation) / sizeof(pickupLocation[0]);
            string string_pickupLocation(pickupLocation, length);

            outputFilestream.read(reinterpret_cast<char*>(returnLocation), 15);
            returnLocation[15] = '\0';
            length = sizeof(returnLocation) / sizeof(returnLocation[0]);
            string string_returnLocation(returnLocation, length);

            outputFilestream.read(reinterpret_cast<char*>(company), 15);
            company[15] = '\0';
            length = sizeof(company) / sizeof(company[0]);
            string string_company(company, length);

            cout<<type<<endl;
            anzahlrental++;
            rentalpreis +=preis;
            rentalcarReservation* Rental = new rentalcarReservation(string_company, string_pickupLocation, string_returnLocation, string_type, string_id, preis, string_fromDate, string_toDate);
        }

    }while(!outputFilestream.eof());
    outputFilestream.close();
    cout<<"Es wurden "<<anzahlflight<<" Flugbuchungen im Wert von "<<flightpreis<<" Euro "<< anzahlrental<<
          " Mietwagenbuchungen im Wert von "<<rentalpreis<<" Euro und "<<anzahlhotel<<" Hotelreservierungen im Wert von"<<hotelpreis<<" Euro angelegt"<<endl;
}
