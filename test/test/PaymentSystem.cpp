#include "PaymentSystem.h"
#include <iostream>

using namespace std;

void PaymentSystem::processPayment() {
    int paymentMethod;
    cout << "Choose Payment Method:\n1. Credit Card\n2. Cash\n";
    cin >> paymentMethod;

    if (paymentMethod == 1 || paymentMethod == 2) {
        cout << "Payment successful!\n";
    }
    else {
        cout << "Invalid payment method. Try again.\n";
        processPayment();
    }
}