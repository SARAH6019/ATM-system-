#include <iostream>
#include <windows.h>
#include <string>

struct User {
    int userID;
    std::string username;
    std::string pin;
    double balance1;
    double balance2;
};


std::string translate(const std::string& message, const std::string& lang) {
    if (lang == "Turkish") {
        if (message == "Welcome") return "Hosgeldiniz!";
        if (message == "Enter your UserID") return "Kullanici ID'nizi giriniz:";
        if (message == "Enter your PIN") return "PIN'inizi giriniz:";
        if (message == "Incorrect PIN") return "Yanlis PIN. Erisim reddedildi.";
        if (message == "Authentication successful") return "Dogrulama basarili.";
        if (message == "Choose a language") return "Lutfen bir dil seciniz:";
        if (message == "Thank you for using the ATM") return "ATM kullandiginiz icin tesekkurler.";
        if (message == "Enter your choice") return "Seçiminizi girin";
		if (message == "ATM Menu") return "ATM Menusu:";
        if (message == "1. Change PIN") return "1. PIN Degistir";
        if (message == "2. Withdraw Cash") return "2. Nakit Cekme";
        if (message == "3. Deposit Money") return "3. Para Yatirma";
        if (message == "4. Exit") return "4. Cikis";
        if (message == "Invalid choice") return "Gecersiz secim.";
        if (message == "Enter your new PIN") return "Yeni PIN'inizi giriniz:";
        if (message == "PIN changed successfully") return "PIN basariyla degistirildi.";
        if (message == "Enter the amount to withdraw") return "Cekmek istediginiz miktari giriniz:";
        if (message == "Insufficient funds") return "Yetersiz bakiye.";
        if (message == "Withdrawal successful") return "Cekim basarili.";
        if (message == "Enter the amount to deposit") return "Yatirmak istediginiz miktari giriniz:";
        if (message == "Deposit successful") return "Para yatirma basarili.";
    }
    return message; 
}

int main() {
    SetConsoleOutputCP(1256);

    
    User users[] = {
        {101, "OMER", "1203", 500, 2000},
        {102, "BESTE", "9807", 4000, 3000},
        {103, "FILIP", "4605", 1000, 15000}
    };
    int userCount = sizeof(users) / sizeof(users[0]);

    
    int languageChoice;
    std::string selectedLanguage = "English";

    std::cout << translate("Choose a language", selectedLanguage) << ":\n";
    std::cout << "1. English\n";
    std::cout << "2. Turkish\n";
    std::cout << "Enter your choice (1-2): ";
    std::cin >> languageChoice;

    switch (languageChoice) {
        case 1:
            selectedLanguage = "English";
            break;
        case 2:
            selectedLanguage = "Turkish";
            break;
        default:
            std::cout << translate("Invalid choice", selectedLanguage) << "\n";
            return 1;
    }

    
    int userID;
    std::string enteredPin;

    std::cout << translate("Enter your UserID", selectedLanguage) << ": ";
    std::cin >> userID;

    std::cout << translate("Enter your PIN", selectedLanguage) << ": ";
    std::cin >> enteredPin;

    
    User* currentUser = NULL;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].userID == userID && users[i].pin == enteredPin) {
            currentUser = &users[i];
            break;
        }
    }

    if (!currentUser) {
        std::cout << translate("Incorrect PIN", selectedLanguage) << "\n";
        return 1;
    }

    std::cout << translate("Authentication successful", selectedLanguage) << "\n";
    std::cout << translate("Welcome", selectedLanguage) << " " << currentUser->username << "!\n";

    int atmChoice;
    do {
        
        std::cout << "\n" << translate("ATM Menu", selectedLanguage) << "\n";
        std::cout << translate("1. Change PIN", selectedLanguage) << "\n";
        std::cout << translate("2. Withdraw Cash", selectedLanguage) << "\n";
        std::cout << translate("3. Deposit Money", selectedLanguage) << "\n";
        std::cout << translate("4. Exit", selectedLanguage) << "\n";
        std::cout << translate("Enter your choice", selectedLanguage) << ": ";
        std::cin >> atmChoice;

        switch (atmChoice) {
            case 1: { 
                std::string newPin;
                std::cout << translate("Enter your new PIN", selectedLanguage) << ": ";
                std::cin >> newPin;
                if (newPin.length() != 4) {
                    std::cout << translate("Invalid PIN", selectedLanguage) << "\n";
                } else {
                    currentUser->pin = newPin;
                    std::cout << translate("PIN changed successfully", selectedLanguage) << "\n";
                }
                break;
            }
            case 2: { 
                double withdrawalAmount;
                std::cout << translate("Enter the amount to withdraw", selectedLanguage) << ": ";
                std::cin >> withdrawalAmount;

                if (withdrawalAmount > currentUser->balance1) {
                    std::cout << translate("Insufficient funds", selectedLanguage) << "\n";
                } else {
                    currentUser->balance1 -= withdrawalAmount;
                    std::cout << translate("Withdrawal successful", selectedLanguage) << ": $" << currentUser->balance1 << "\n";
                }
                break;
            }
            case 3: { 
                double depositAmount;
                std::cout << translate("Enter the amount to deposit", selectedLanguage) << ": ";
                std::cin >> depositAmount;

                currentUser->balance1 += depositAmount;
                std::cout << translate("Deposit successful", selectedLanguage) << ": $" << currentUser->balance1 << "\n";
                break;
            }
            case 4: { 
                std::cout << translate("Thank you for using the ATM", selectedLanguage) << "\n";
                break;
            }
            default:
                std::cout << translate("Invalid choice", selectedLanguage) << "\n";
        }
    } while (atmChoice != 4);

    return 0;
}
