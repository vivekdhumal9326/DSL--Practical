/* Mini Project: Temperature Converter  '''
   
'''Language used: C++   
Data Structure used: Arrays  
 Group Members: 1. Aishwarya Ganesh Suryawanshi (40)  
                2. Vivek Vilas Dhumal (41)    
Problem Statement – Develop a Health Record Management System that allows 
users to input, store, and display health records of patients. Each health record should 
include details such as the patient's name, blood pressure, blood sugar level, and body 
temperature in various scales (Celsius, Fahrenheit, Kelvin). The system should also 
evaluate the health data and provide alerts if any values fall outside of normal ranges. 
*/ 
 
  
#include <iostream> 
#include <string> 
using namespace std; 
 
// Structure for health records (Name, Blood Pressure, Sugar, Temperature) 
struct HealthRecord { 
    string name;          // Patient's name 
    float bloodPressure;  // Blood pressure in mmHg 
    float bloodSugar;     // Blood sugar in mg/dL 
    float temperatureC;   // Temperature in Celsius 
    float temperatureF;   // Temperature in Fahrenheit 
    float temperatureK;   // Temperature in Kelvin 
    HealthRecord* next; 
}; 
 
// Function to create a new health record node with temperature conversion 
HealthRecord* createNewRecord(string name, float bp, float sugar, float temp, int 
tempScale) { 
    HealthRecord* newRecord = new HealthRecord(); 
    newRecord->name = name; 
    newRecord->bloodPressure = bp; 
    newRecord->bloodSugar = sugar; 
 
    // Convert temperature based on the input scale (1 = Celsius, 2 = Fahrenheit, 3 = Kelvin) 
    if (tempScale == 1) {  // Celsius input 
        newRecord->temperatureC = temp; 
        newRecord->temperatureF = (temp * 9/5) + 32; 
        newRecord->temperatureK = temp + 273.15; 
    } else if (tempScale == 2) {  // Fahrenheit input 
        newRecord->temperatureF = temp; 
        newRecord->temperatureC = (temp - 32) * 5/9; 
        newRecord->temperatureK = newRecord->temperatureC + 273.15; 
    } else if (tempScale == 3) {  // Kelvin input 
        newRecord->temperatureK = temp; 
        newRecord->temperatureC = temp - 273.15; 
        newRecord->temperatureF = (newRecord->temperatureC * 9/5) + 32; 
    } 
 
    newRecord->next = nullptr; 
    return newRecord; 
} 
 
// Function to insert a health record at the end of the linked list 
void insertRecord(HealthRecord* &head, string name, float bp, float sugar, float temp, int 
tempScale) { 
    HealthRecord* newRecord = createNewRecord(name, bp, sugar, temp, tempScale); 
 
    if (head == nullptr) { 
        head = newRecord; 
    } else { 
        HealthRecord* tempPtr = head; 
        while (tempPtr->next != nullptr) { 
            tempPtr = tempPtr->next; 
        } 
        tempPtr->next = newRecord; 
    } 
} 
 
// Function to check if the blood pressure is within a healthy range 
void checkBloodPressure(float bp) { 
    if (bp > 140 || bp < 90) { 
        cout << "Abnormal blood pressure! Consider consulting a doctor.\n"; 
    } else { 
        cout << "Normal blood pressure.\n"; 
    } 
} 
 
// Function to check if the blood sugar is within a healthy range 
void checkBloodSugar(float sugar) { 
    if (sugar > 140) { 
        cout << "High blood sugar! Consider consulting a doctor.\n"; 
    } else if (sugar < 70) { 
        cout << "Low blood sugar! Consider consulting a doctor.\n"; 
    } else { 
        cout << "Normal blood sugar.\n"; 
    } 
} 
 
// Function to check the temperature (in Celsius) and decide if hospital care is needed 
void checkTemperature(float tempC) { 
    if (tempC > 37) { 
        cout << "Fever detected! Consider consulting a doctor.\n"; 
    } else { 
        cout << "Normal body temperature.\n"; 
    } 
} 
 
// Function to display all health records and perform checks 
void displayRecords(HealthRecord* head) { 
    if (head == nullptr) { 
        cout << "No health records to display.\n"; 
        return; 
    } 
 
    HealthRecord* tempPtr = head; 
    int recordCount = 1; 
     
    while (tempPtr != nullptr) { 
        cout << "\nHealth Record " << recordCount++ << ":\n"; 
        cout << "Name: " << tempPtr->name << "\n"; 
        cout << "Blood Pressure: " << tempPtr->bloodPressure << " mmHg\n"; 
        cout << "Blood Sugar: " << tempPtr->bloodSugar << " mg/dL\n"; 
        cout << "Temperature: " << tempPtr->temperatureC << " °C / "  
             << tempPtr->temperatureF << " °F / "  
             << tempPtr->temperatureK << " K\n"; 
         
        // Perform health checks 
        checkBloodPressure(tempPtr->bloodPressure); 
        checkBloodSugar(tempPtr->bloodSugar); 
        checkTemperature(tempPtr->temperatureC); 
         
        tempPtr = tempPtr->next; 
    } 
} 
 
int main() { 
    HealthRecord* head = nullptr; // Head pointer for the linked list 
    char continueChoice; 
 
    do { 
        string name; 
        float bp, sugar, temp; 
        int tempScale; 
         
        // Take input for patient's name, blood pressure, sugar, and temperature 
        cout << "\nEnter the patient's name: "; 
        cin.ignore(); // Clear input buffer 
        getline(cin, name); 
        cout << "Enter the blood pressure (mmHg): "; 
        cin >> bp; 
        cout << "Enter the blood sugar level (mg/dL): "; 
        cin >> sugar; 
 
        // Input temperature scale and value 
        cout << "Choose the temperature scale:\n"; 
        cout << "1. Celsius\n2. Fahrenheit\n3. Kelvin\n"; 
        cout << "Enter your choice: "; 
        cin >> tempScale; 
        cout << "Enter the body temperature: "; 
        cin >> temp; 
 
        // Insert the health record into the linked list 
        insertRecord(head, name, bp, sugar, temp, tempScale); 
 
        // Ask if the user wants to add another record 
        cout << "\nDo you want to enter another health record? (y/n): "; 
        cin >> continueChoice; 
 
    } while (continueChoice == 'y' || continueChoice == 'Y'); 
 
    // Display all health records and perform health checks 
    displayRecords(head); 
 
    return 0; 
} 
 
/* Output 
 
Enter the patient's name: Aish 
Enter the blood pressure (mmHg): 150 
Enter the blood sugar level (mg/dL): 123 
Choose the temperature scale: 
1. Celsius 
2. Fahrenheit 
3. Kelvin 
Enter your choice: 1 
Enter the body temperature: 37 
Do you want to enter another health record? (y/n): y 
Enter the patient's name: Vivek 
Enter the blood pressure (mmHg): 111 
Enter the blood sugar level (mg/dL): 170 
Choose the temperature scale: 
1. Celsius 
2. Fahrenheit 
3. Kelvin 
Enter your choice: 2 
Enter the body temperature: 145 
Do you want to enter another health record? (y/n): n 
Health Record 1: 
Name: Aish 
Blood Pressure: 150 mmHg 
Blood Sugar: 123 mg/dL 
Temperature: 37 °C / 98.6 °F / 310.15 K 
Abnormal blood pressure! Consider consulting a doctor. 
Normal blood sugar. 
Normal body temperature. 
Health Record 2: 
Name: Vivek 
Blood Pressure: 111 mmHg 
Blood Sugar: 170 mg/dL 
Temperature: 62.7778 °C / 145 °F / 335.928 K 
Normal blood pressure. 
High blood sugar! Consider consulting a doctor. 
Fever detected! Consider consulting a doctor. 
=== Code Execution Successful ===  
  */
