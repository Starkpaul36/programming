#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include<vector>
#include <fstream>
#include"booking.h"


class travelAgency
{
public:
    travelAgency();
    virtual ~travelAgency();
    void readFile();
   // void readBinaryFile(const std::string& filename);
    void readBinaryFile();

private:
    std::vector<booking*>Bookings;
};

#endif // TRAVELAGENCY_H
