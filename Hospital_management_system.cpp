#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Person {
protected:
    int    id;
    string name;
    int    age;
    string contact;

public:
    // Setters
    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setContact(string c) { contact = c; }

    // Getters
    int    getID() { return id; }
    string getName() { return name; }
    int    getAge() { return age; }
    string getContact() { return contact; }
};

class Patient : public Person {
private:
    string disease;
    string admitDate;

public:
    // Setter
    void setDisease(string d) { disease = d; }
    void setAdmitDate(string dt) { admitDate = dt; }

    // Getter
    string getDisease() { return disease; }
    string getAdmitDate() { return admitDate; }

    // read patient details from user
    void inputPatient() {
        cout << "\n  Enter Patient ID      : "; cin >> id;
        cin.ignore();
        cout << "  Enter Patient Name    : "; getline(cin, name);
        cout << "  Enter Age             : "; cin >> age;
        cin.ignore();
        cout << "  Enter Contact         : "; getline(cin, contact);
        cout << "  Enter Disease         : "; getline(cin, disease);
        cout << "  Enter Admit Date      : "; getline(cin, admitDate);
    }

    // show patient details on screen
    void displayPatient() {
        cout << "\n  ----------------------------------------";
        cout << "\n  Patient ID    : " << id;
        cout << "\n  Name          : " << name;
        cout << "\n  Age           : " << age;
        cout << "\n  Contact       : " << contact;
        cout << "\n  Disease       : " << disease;
        cout << "\n  Admit Date    : " << admitDate;
        cout << "\n  ----------------------------------------\n";
    }

    //save patient record to patient.txt 
    void saveToFile() {
        ofstream file("patient.txt", ios::app); 
        if (file.is_open()) {
            file << id << "\n"
                << name << "\n"
                << age << "\n"
                << contact << "\n"
                << disease << "\n"
                << admitDate << "\n"
                << "---\n"; 
            file.close();
            cout << "\n  [OK] Patient record saved.\n";
        }
        else {
            cout << "\n  [ERROR] Could not open patient.txt\n";
        }
    }

    bool loadFromFile(ifstream& file) {
        string line;
        if (!getline(file, line)) return false;  // id
        id = stoi(line);
        getline(file, name);
        getline(file, line); age = stoi(line);
        getline(file, contact);
        getline(file, disease);
        getline(file, admitDate);
        getline(file, line); 
        return true;
    }
};

class Doctor : public Person {
private:
    string specialization;
    string availability;

public:
    // Setters
    void setSpecialization(string s) { specialization = s; }
    void setAvailability(string a) { availability = a; }

    // Getters
    string getSpecialization() { return specialization; }
    string getAvailability() { return availability; }

    // read doctor details from user ---
    void inputDoctor() {
        cout << "\n  Enter Doctor ID          : "; cin >> id;
        cin.ignore();
        cout << "  Enter Doctor Name        : "; getline(cin, name);
        cout << "  Enter Age                : "; cin >> age;
        cin.ignore();
        cout << "  Enter Contact            : "; getline(cin, contact);
        cout << "  Enter Specialization     : "; getline(cin, specialization);
        cout << "  Enter Availability (days): "; getline(cin, availability);
    }

    void displayDoctor() {
        cout << "\n  ----------------------------------------";
        cout << "\n  Doctor ID        : " << id;
        cout << "\n  Name             : " << name;
        cout << "\n  Age              : " << age;
        cout << "\n  Contact          : " << contact;
        cout << "\n  Specialization   : " << specialization;
        cout << "\n  Availability     : " << availability;
        cout << "\n  ----------------------------------------\n";
    }

    // save doctor record to doctor.txt
    void saveToFile() {
        ofstream file("doctor.txt", ios::app);
        if (file.is_open()) {
            file << id << "\n"
                << name << "\n"
                << age << "\n"
                << contact << "\n"
                << specialization << "\n"
                << availability << "\n"
                << "---\n";
            file.close();
            cout << "\n  [OK] Doctor record saved.\n";
        }
        else {
            cout << "\n  [ERROR] Could not open doctor.txt\n";
        }
    }

    bool loadFromFile(ifstream& file) {
        string line;
        if (!getline(file, line)) return false;
        id = stoi(line);
        getline(file, name);
        getline(file, line); age = stoi(line);
        getline(file, contact);
        getline(file, specialization);
        getline(file, availability);
        getline(file, line); // separator
        return true;
    }
};

class Appointment {
private:
    int    appointmentID;
    int    patientID;
    int    doctorID;
    string date;
    string timeSlot;

public:
  
    void inputAppointment() {
        cout << "\n  Enter Appointment ID : "; cin >> appointmentID;
        cout << "  Enter Patient ID     : "; cin >> patientID;
        cout << "  Enter Doctor ID      : "; cin >> doctorID;
        cin.ignore();
        cout << "  Enter Date           : "; getline(cin, date);
        cout << "  Enter Time Slot      : "; getline(cin, timeSlot);
    }
    void displayAppointment() {
        cout << "\n  ----------------------------------------";
        cout << "\n  Appointment ID : " << appointmentID;
        cout << "\n  Patient ID     : " << patientID;
        cout << "\n  Doctor ID      : " << doctorID;
        cout << "\n  Date           : " << date;
        cout << "\n  Time Slot      : " << timeSlot;
        cout << "\n  ----------------------------------------\n";
    }

    // Getter 
    int getAppointmentID() { return appointmentID; }
    int getPatientID() { return patientID; }

    //FILE: save to appointment.txt 
    void saveToFile() {
        ofstream file("appointment.txt", ios::app);
        if (file.is_open()) {
            file << appointmentID << "\n"
                << patientID << "\n"
                << doctorID << "\n"
                << date << "\n"
                << timeSlot << "\n"
                << "---\n";
            file.close();
            cout << "\n  [OK] Appointment saved.\n";
        }
        else {
            cout << "\n  [ERROR] Could not open appointment.txt\n";
        }
    }

    //load one appointment from file stream 
    bool loadFromFile(ifstream& file) {
        string line;
        if (!getline(file, line)) return false;
        appointmentID = stoi(line);
        getline(file, line); patientID = stoi(line);
        getline(file, line); doctorID = stoi(line);
        getline(file, date);
        getline(file, timeSlot);
        getline(file, line); // separator
        return true;
    }
};

class Billing {
private:
    int    billID;
    int    patientID;
    string patientName;
    double consultationFee;
    double medicineCost;
    double roomCharges;
    double totalAmount;

public:
   
    void inputBilling() {
        cout << "\n  Enter Bill ID          : "; cin >> billID;
        cout << "  Enter Patient ID       : "; cin >> patientID;
        cin.ignore();
        cout << "  Enter Patient Name     : "; getline(cin, patientName);
        cout << "  Enter Consultation Fee : "; cin >> consultationFee;
        cout << "  Enter Medicine Cost    : "; cin >> medicineCost;
        cout << "  Enter Room Charges     : "; cin >> roomCharges;

        totalAmount = consultationFee + medicineCost + roomCharges;
    }

    void displayReceipt() {
        cout << "\n  ========================================";
        cout << "\n         HOSPITAL BILLING RECEIPT        ";
        cout << "\n  ========================================";
        cout << "\n  Bill ID           : " << billID;
        cout << "\n  Patient ID        : " << patientID;
        cout << "\n  Patient Name      : " << patientName;
        cout << "\n  ----------------------------------------";
        cout << "\n  Consultation Fee  : Rs. " << fixed << setprecision(2) << consultationFee;
        cout << "\n  Medicine Cost     : Rs. " << medicineCost;
        cout << "\n  Room Charges      : Rs. " << roomCharges;
        cout << "\n  ----------------------------------------";
        cout << "\n  TOTAL AMOUNT      : Rs. " << totalAmount;
        cout << "\n  ========================================\n";
    }

    int getBillID() { return billID; }
    int getPatientID() { return patientID; }

    // save to billing.txt
    void saveToFile() {
        ofstream file("billing.txt", ios::app);
        if (file.is_open()) {
            file << billID << "\n"
                << patientID << "\n"
                << patientName << "\n"
                << consultationFee << "\n"
                << medicineCost << "\n"
                << roomCharges << "\n"
                << totalAmount << "\n"
                << "---\n";
            file.close();
            cout << "\n  [OK] Bill saved.\n";
        }
        else {
            cout << "\n  [ERROR] Could not open billing.txt\n";
        }
    }

    bool loadFromFile(ifstream& file) {
        string line;
        if (!getline(file, line)) return false;
        billID = stoi(line);
        getline(file, line); patientID = stoi(line);
        getline(file, patientName);
        getline(file, line); consultationFee = stod(line);
        getline(file, line); medicineCost = stod(line);
        getline(file, line); roomCharges = stod(line);
        getline(file, line); totalAmount = stod(line);
        getline(file, line); // separator
        return true;
    }
};

void printHeader(string title) {
    cout << "\n  ========================================\n";
    cout << "    " << title << "\n";
    cout << "  ========================================\n";
}


void addPatient() {
    printHeader("ADD PATIENT");
    Patient p;
    p.inputPatient();
    p.saveToFile();
}

void viewAllPatients() {
    printHeader("ALL PATIENTS");
    ifstream file("patient.txt");
    if (!file.is_open()) {
        cout << "\n  [INFO] No patient records found.\n";
        return;
    }
    Patient p;
    int count = 0;
    while (p.loadFromFile(file)) {
        p.displayPatient();
        count++;
    }
    file.close();
    if (count == 0) cout << "\n  No records found.\n";
    else cout << "\n  Total patients: " << count << "\n";
}

void searchPatient() {
    printHeader("SEARCH PATIENT");
    int searchID;
    cout << "  Enter Patient ID to search: "; cin >> searchID;

    ifstream file("patient.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No records file found.\n"; return; }

    Patient p;
    bool found = false;
    while (p.loadFromFile(file)) {
        if (p.getID() == searchID) {
            p.displayPatient();
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "\n  [INFO] Patient with ID " << searchID << " not found.\n";
}

void updatePatient() {
    printHeader("UPDATE PATIENT");
    int searchID;
    cout << "  Enter Patient ID to update: "; cin >> searchID;

    ifstream file("patient.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No records file found.\n"; return; }

    // Load all records into memory
    Patient records[100];
    int count = 0;
    while (records[count].loadFromFile(file))
        count++;
    file.close();

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (records[i].getID() == searchID) {
            cout << "\n  Record found. Enter new details:\n";
            records[i].inputPatient();
            found = true;
            break;
        }
    }
    if (!found) { cout << "\n  [INFO] Patient not found.\n"; return; }

    // Rewrite the file
    ofstream out("patient.txt"); // overwrite mode (no ios::app)
    for (int i = 0; i < count; i++) {
        // Re-save each patient to file
        out << records[i].getID() << "\n"
            << records[i].getName() << "\n"
            << records[i].getAge() << "\n"
            << records[i].getContact() << "\n"
            << records[i].getDisease() << "\n"
            << records[i].getAdmitDate() << "\n"
            << "---\n";
    }
    out.close();
    cout << "\n  [OK] Patient record updated.\n";
}

void deletePatient() {
    printHeader("DELETE PATIENT");
    int searchID;
    cout << "  Enter Patient ID to delete: "; cin >> searchID;

    ifstream file("patient.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No records file found.\n"; return; }

    Patient records[100];
    int count = 0;
    while (records[count].loadFromFile(file))
        count++;
    file.close();

    bool found = false;
    ofstream out("patient.txt");
    for (int i = 0; i < count; i++) {
        if (records[i].getID() == searchID) {
            found = true; // skip this record (delete it)
        }
        else {
            out << records[i].getID() << "\n"
                << records[i].getName() << "\n"
                << records[i].getAge() << "\n"
                << records[i].getContact() << "\n"
                << records[i].getDisease() << "\n"
                << records[i].getAdmitDate() << "\n"
                << "---\n";
        }
    }
    out.close();
    if (found) cout << "\n  [OK] Patient record deleted.\n";
    else       cout << "\n  [INFO] Patient ID not found.\n";
}

void addDoctor() {
    printHeader("ADD DOCTOR");
    Doctor d;
    d.inputDoctor();
    d.saveToFile();
}

void viewAllDoctors() {
    printHeader("ALL DOCTORS");
    ifstream file("doctor.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No doctor records found.\n"; return; }
    Doctor d;
    int count = 0;
    while (d.loadFromFile(file)) {
        d.displayDoctor();
        count++;
    }
    file.close();
    if (count == 0) cout << "\n  No records found.\n";
    else cout << "\n  Total doctors: " << count << "\n";
}

void searchDoctor() {
    printHeader("SEARCH DOCTOR");
    int searchID;
    cout << "  Enter Doctor ID to search: "; cin >> searchID;

    ifstream file("doctor.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No records file found.\n"; return; }

    Doctor d;
    bool found = false;
    while (d.loadFromFile(file)) {
        if (d.getID() == searchID) {
            d.displayDoctor();
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "\n  [INFO] Doctor with ID " << searchID << " not found.\n";
}

void bookAppointment() {
    printHeader("BOOK APPOINTMENT");
    Appointment a;
    a.inputAppointment();
    a.saveToFile();
}

void viewAllAppointments() {
    printHeader("ALL APPOINTMENTS");
    ifstream file("appointment.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No appointments found.\n"; return; }
    Appointment a;
    int count = 0;
    while (a.loadFromFile(file)) {
        a.displayAppointment();
        count++;
    }
    file.close();
    if (count == 0) cout << "\n  No appointments found.\n";
    else cout << "\n  Total appointments: " << count << "\n";
}

void cancelAppointment() {
    printHeader("CANCEL APPOINTMENT");
    int searchID;
    cout << "  Enter Appointment ID to cancel: "; cin >> searchID;

    ifstream file("appointment.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No records file found.\n"; return; }

    Appointment records[100];
    int count = 0;
    while (records[count].loadFromFile(file))
        count++;
    file.close();

    bool found = false;
    ofstream out("appointment.txt");
    for (int i = 0; i < count; i++) {
        if (records[i].getAppointmentID() == searchID) {
            found = true; // skip = cancel
        }
        else {
            records[i].saveToFile(); // this appends — see note below
        }
    }
    
    out.close();
    ofstream clearFile("appointment.txt", ios::trunc);
    clearFile.close();

    for (int i = 0; i < count; i++) {
        if (records[i].getAppointmentID() != searchID) {
            records[i].saveToFile();
        }
    }

    if (found) cout << "\n  [OK] Appointment cancelled.\n";
    else       cout << "\n  [INFO] Appointment ID not found.\n";
}

void generateBill() {
    printHeader("GENERATE BILL");
    Billing b;
    b.inputBilling();
    b.displayReceipt();
    b.saveToFile();
}

void viewAllBills() {
    printHeader("ALL BILLS");
    ifstream file("billing.txt");
    if (!file.is_open()) { cout << "\n  [INFO] No billing records found.\n"; return; }
    Billing b;
    int count = 0;
    while (b.loadFromFile(file)) {
        cout << "\n  Bill ID: " << b.getBillID()
            << "  |  Patient ID: " << b.getPatientID();
        count++;
    }
    file.close();
    cout << "\n\n  Total bills: " << count << "\n";
}

void patientMenu() {
    int choice;
    do {
        printHeader("PATIENT MANAGEMENT");
        cout << "  1. Add Patient\n";
        cout << "  2. View All Patients\n";
        cout << "  3. Search Patient\n";
        cout << "  4. Update Patient Record\n";
        cout << "  5. Delete Patient Record\n";
        cout << "  0. Back to Main Menu\n";
        cout << "\n  Enter choice: "; cin >> choice;

        switch (choice) {
        case 1: addPatient();    break;
        case 2: viewAllPatients(); break;
        case 3: searchPatient(); break;
        case 4: updatePatient(); break;
        case 5: deletePatient(); break;
        case 0: break;
        default: cout << "\n  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

void doctorMenu() {
    int choice;
    do {
        printHeader("DOCTOR MANAGEMENT");
        cout << "  1. Add Doctor\n";
        cout << "  2. View All Doctors\n";
        cout << "  3. Search Doctor\n";
        cout << "  0. Back to Main Menu\n";
        cout << "\n  Enter choice: "; cin >> choice;

        switch (choice) {
        case 1: addDoctor();    break;
        case 2: viewAllDoctors(); break;
        case 3: searchDoctor(); break;
        case 0: break;
        default: cout << "\n  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

void appointmentMenu() {
    int choice;
    do {
        printHeader("APPOINTMENT MANAGEMENT");
        cout << "  1. Book Appointment\n";
        cout << "  2. View All Appointments\n";
        cout << "  3. Cancel Appointment\n";
        cout << "  0. Back to Main Menu\n";
        cout << "\n  Enter choice: "; cin >> choice;

        switch (choice) {
        case 1: bookAppointment();      break;
        case 2: viewAllAppointments();  break;
        case 3: cancelAppointment();    break;
        case 0: break;
        default: cout << "\n  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}

void billingMenu() {
    int choice;
    do {
        printHeader("BILLING MANAGEMENT");
        cout << "  1. Generate Bill / Receipt\n";
        cout << "  2. View All Bills\n";
        cout << "  0. Back to Main Menu\n";
        cout << "\n  Enter choice: "; cin >> choice;

        switch (choice) {
        case 1: generateBill(); break;
        case 2: viewAllBills(); break;
        case 0: break;
        default: cout << "\n  [!] Invalid choice.\n";
        }
    } while (choice != 0);
}
int main() {
    int choice;

    cout << "\n  =========================================\n";
    cout << "      HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "  =========================================\n";

    do {
        cout << "\n\n  ===== MAIN MENU =====\n";
        cout << "  1. Patient Management\n";
        cout << "  2. Doctor Management\n";
        cout << "  3. Appointment Management\n";
        cout << "  4. Billing Management\n";
        cout << "  0. Exit\n";
        cout << "\n  Enter choice: "; cin >> choice;

        switch (choice) {
        case 1: patientMenu();     break;
        case 2: doctorMenu();      break;
        case 3: appointmentMenu(); break;
        case 4: billingMenu();     break;
        case 0:
            cout << "\n  Thank you! Goodbye.\n\n";
            break;
        default:
            cout << "\n  [!] Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}