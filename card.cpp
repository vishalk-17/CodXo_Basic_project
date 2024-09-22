#include <iostream>
#include <string>
#include <vector>

bool isValidCreditCardNumber(const std::string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    for (int i = cardNumber.size() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    return sum % 10 == 0;
}

int main() {
    std::string cardNumber;
    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    if (isValidCreditCardNumber(cardNumber)) {
        std::cout << "Credit card number is valid." << std::endl;
    } else {
        std::cout << "Credit card number is invalid." << std::endl;
    }

    return 0;
}





// OUTPUT



/*

PS C:\Users\sah37\OneDrive\Desktop\csharp> cd "c:\Users\sah37\OneDrive\Desktop\csharp\project\" ; if ($?) { g++ card.cpp -o card } ; if ($?) { .\card }


Enter a credit card number: 6011000990139424
Credit card number is valid.


Enter a credit card number: 6011000990139425
Credit card number is invalid.

*/