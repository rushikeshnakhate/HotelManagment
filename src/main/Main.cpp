#include<iostream>
#include "Events.h"
#include "Database.h"
#include "Reception.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        Database::init();
        Reception::process(Event::CheckIn);
        Reception::process(Event::CheckOut, "1A");
        Reception::print();
    } catch (std::exception &ex) {
        cout << ex.what() << endl;
    }
}