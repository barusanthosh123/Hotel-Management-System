
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Room structure
struct Room {
    int roomNumber;
    string roomType;
    bool isAvailable;
    double pricePerNight;
};

// Customer structure
struct Customer {
    string name;
    int roomNumber;
    int nights;
};

// Hotel Management Class
class HotelManagement {
private:
    vector<Room> rooms;
    vector<Customer> customers;

public:
    // Initialize rooms
    void initializeRooms() {
        rooms = {
            {101, "Single", true, 50.0},
            {102, "Double", true, 75.0},
            {103, "Suite", true, 150.0}
        };
    }

    // Display available rooms
    void displayRooms() {
        cout << "\nAvailable Rooms:\n";
        for (const auto& room : rooms) {
            if (room.isAvailable) {
                cout << "Room Number: " << room.roomNumber
                     << ", Type: " << room.roomType
                     << ", Price per Night: $" << room.pricePerNight << endl;
            }
        }
    }

    // Book a room
    void bookRoom() {
        int roomNumber;
        string customerName;
        int nights;

        cout << "\nEnter Room Number to Book: ";
        cin >> roomNumber;

        bool found = false;
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isAvailable) {
                found = true;
                room.isAvailable = false;

                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, customerName);
                cout << "Enter Number of Nights: ";
                cin >> nights;

                customers.push_back({customerName, roomNumber, nights});
                cout << "Room " << roomNumber << " has been booked successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "Room not available or invalid room number.\n";
        }
    }

    // Display customer details
    void displayCustomers() {
        cout << "\nCustomer Details:\n";
        for (const auto& customer : customers) {
            cout << "Name: " << customer.name
                 << ", Room Number: " << customer.roomNumber
                 << ", Nights: " << customer.nights << endl;
        }
    }

    // Generate Bill
    void generateBill() {
        string customerName;
        cout << "\nEnter Customer Name to Generate Bill: ";
        cin.ignore();
        getline(cin, customerName);

        for (const auto& customer : customers) {
            if (customer.name == customerName) {
                for (const auto& room : rooms) {
                    if (room.roomNumber == customer.roomNumber) {
                        double total = customer.nights * room.pricePerNight;
                        cout << "Bill for " << customer.name << ":\n";
                        cout << "Room Number: " << customer.roomNumber << "\n"
                             << "Room Type: " << room.roomType << "\n"
                             << "Nights: " << customer.nights << "\n"
                             << "Total Cost: $" << total << endl;
                        return;
                    }
                }
            }
        }
        cout << "Customer not found.\n";
    }
};

int main() {
    HotelManagement hotel;
    hotel.initializeRooms();

    int choice;

    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Display Customers\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.displayRooms();
            break;
        case 2:
            hotel.bookRoom();
            break;
        case 3:
            hotel.displayCustomers();
            break;
        case 4:
            hotel.generateBill();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}



