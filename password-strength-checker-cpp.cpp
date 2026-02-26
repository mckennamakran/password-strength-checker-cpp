#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class PasswordStrengthChecker {
private:
    string password;
    bool hasUpper;
    bool hasLower;
    bool hasDigit;
    bool hasSpecial;
    int length;
    
    //check if character is special (not alphanumeric)
    bool isSpecialChar(char c) {
        string specialChars = "!@#$%^&*()_+-=[]{}|;:'\",.<>?/`~";
        return specialChars.find(c) != string::npos;
    }
    
    void analyzePassword() {
        hasUpper = false;
        hasLower = false;
        hasDigit = false;
        hasSpecial = false;
        length = password.length();
        
        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else if (isdigit(c)) hasDigit = true;
            else if (isSpecialChar(c)) hasSpecial = true;
        }
    }
    
public:
    void getPassword() {
        cout << "\n=== PASSWORD STRENGTH CHECKER ===\n";
        cout << "Enter your password: ";
        getline(cin, password);
        analyzePassword();
    }
    
    int calculateStrength() {
        int score = 0;
        
        //length criteria (max 3 points)
        if (length >= 12) score += 3;
        else if (length >= 8) score += 2;
        else if (length >= 6) score += 1;
        
        //character type criteria (1 point each)
        if (hasUpper) score += 1;
        if (hasLower) score += 1;
        if (hasDigit) score += 1;
        if (hasSpecial) score += 1;
        
        if (hasUpper && hasLower && hasDigit && hasSpecial && length >= 8) {
            score += 1;
        }
        
        return score;
    }
    
    string getStrengthRating(int score) {
        if (score >= 7) return "VERY STRONG";
        else if (score >= 5) return "STRONG";
        else if (score >= 3) return "MODERATE";
        else if (score >= 1) return "WEAK";
        else return "VERY WEAK";
    }
    
    void displayResults() {
        cout << "\n=== RESULTS ===\n";
        cout << "Password: " << string(password.length(), '*') << "\n\n";
        
        //display criteria met
        cout << "Criteria Check:\n";
        cout << "✓ Length: " << length << " characters\n";
        cout << (hasUpper ? "✓" : "✗") << " Uppercase letter\n";
        cout << (hasLower ? "✓" : "✗") << " Lowercase letter\n";
        cout << (hasDigit ? "✓" : "✗") << " Number\n";
        cout << (hasSpecial ? "✓" : "✗") << " Special character\n\n";
        
        //show score and rating
        int score = calculateStrength();
        string rating = getStrengthRating(score);
        
        cout << "Strength Score: " << score << "/8\n";
        cout << "Overall Rating: " << rating << "\n";
        
        //improvement suggestions
        cout << "\nSuggestions for improvement:\n";
        if (length < 8) {
            cout << "→ Make password at least 8 characters long\n";
        }
        if (!hasUpper) {
            cout << "→ Add uppercase letters\n";
        }
        if (!hasLower) {
            cout << "→ Add lowercase letters\n";
        }
        if (!hasDigit) {
            cout << "→ Add numbers\n";
        }
        if (!hasSpecial) {
            cout << "→ Add special characters (e.g., !@#$%^&*)\n";
        }
        
        if (hasUpper && hasLower && hasDigit && hasSpecial && length >= 12) {
            cout << "→ Your password meets all criteria!\n";
        }
        
        cout << "\n";
    }
    
    void showPasswordExamples() {
        cout << "\n=== PASSWORD EXAMPLES ===\n";
        cout << "Very Weak  : 12345\n";
        cout << "Weak       : password\n";
        cout << "Moderate   : Pass123\n";
        cout << "Strong     : Pass123!@#\n";
        cout << "Very Strong: P@ssw0rd!2024\n\n";
    }
};

int main() {
    PasswordStrengthChecker checker;
    char choice;
    
    cout << "WELCOME TO PASSWORD STRENGTH CHECKER\n";
    cout << "====================================\n";
    
    do {
        checker.getPassword();
        checker.displayResults();
        checker.showPasswordExamples();
        
        cout << "Check another password? (y/n): ";
        cin >> choice;
        cin.ignore(); 
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "\nThank you for using Password Strength Checker!\n";
    cout << "Remember: A strong password keeps your data safe!\n";
    
    return 0;
}
