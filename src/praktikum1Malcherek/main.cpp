#include <iostream>
#include "travelagency.h"
#include <exception>
using namespace std;

int main()
{

    travelAgency test;
    char value;

    while (true) {
        cout<<"Json(J) oder binairDatei(b)?\t";
        cin>>value;

        switch (value) {
        case 'J':
        case 'j':
            try{
            test.readFile();
        }catch(runtime_error fehler){
                cout << "Fehler bei der Dateiverarbeitung: " << endl;
                cout << fehler.what() << endl;
                cout << "Korrigieren Sie die Datei, und geben Sie dann den Dateinamen erneut ein." << endl;
                continue;

            }

            break;
        case 'b':
           // test.readBinaryFile("bookingsBinary.bin");
            test.readBinaryFile();
            break;
        default:
            break;
        }

    }



    return 0;
}
