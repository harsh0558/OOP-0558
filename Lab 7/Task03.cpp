#include <iostream>
using namespace std;

class Ticket {
public:
    int ticketID;
    string passengerName;
    float price;
    string date;
    string destination;

public:
    Ticket(int id, string name, float cost, string dt, string dest){
        ticketID = id;
        passengerName = name;
        price = cost;
        date = dt;
        destination = dest;
    }

    void reserve() {
        cout << "Ticket reserved for: " << passengerName << endl;
    }

    void cancel() {
        cout << "Ticket canceled for: " << passengerName << endl;
    }

    void displayTicketInfo() {
        cout << "Ticket ID: "<<ticketID<<endl;
        cout<<"Passenger: "<<passengerName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
    }

};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double cost, string dt, string dest, string airline, string flight, string seat)
        : Ticket(id, name, cost, dt, dest){
            airlineName = airline;
            flightNumber = flight;
            seatClass = seat;
        }

    void displayTicketInfo() {
        cout << "Ticket ID: "<<ticketID<<endl;
        cout<<"Passenger: "<<passengerName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Airline: "<<airlineName<<endl;
        cout<<"Flight No: "<<flightNumber<<endl; 
        cout<<"Seat Class: "<<seatClass<<endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double cost, string dt, string dest, string train, string coach, string time)
        : Ticket(id, name, cost, dt, dest){
            trainNumber = train;
            coachType = coach;
            departureTime = time;
        }

    void reserve()  {
        cout<<"Train ticket reserved for: "<<passengerName<<endl;
    }

    void displayTicketInfo(){
        Ticket::displayTicketInfo();
        cout<<"Train No: "<<trainNumber<<endl;
        cout<<"Coach Type: "<<coachType<<endl;
        cout<<"Departure: "<<departureTime<<endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double cost, string dt, string dest, string company, string seat)
        : Ticket(id, name, cost, dt, dest){
            busCompany = company;
            seatNumber = seat;
        }

    void cancel()  {
        cout<<"Bus ticket canceled for: "<<passengerName<<endl;
    }

    void displayTicketInfo()  {
        cout << "Ticket ID: "<<ticketID<<endl;
        cout<<"Passenger: "<<passengerName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Bus Company: "<<busCompany<<endl;
        cout<<"Seat No: "<<seatNumber<<endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double cost, string dt, string dest, string artist, string venueName, string seat)
        : Ticket(id, name, cost, dt, dest){
            artistName = artist;
            venue = venueName;
            seatType = seat;
        }

    void displayTicketInfo()  {
        cout << "Ticket ID: "<<ticketID<<endl;
        cout<<"Passenger: "<<passengerName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Artist: "<<artistName<<endl;
        cout<<"Venue: "<<venue<<endl;
        cout<<"Seat Type: "<<seatType<<endl;
    }
};

