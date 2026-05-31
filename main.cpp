#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void clearScreen() {
    // Clear screen
    system("clear");
}

void changeColor(string colorCode) {
    string command = "color " + colorCode;
    system(command.c_str());
}

struct Transaction {
      int id;           // id untuk setiap transaksi
      string date;      // Tanggal transaksi
      string type;      // Tipe transaksi "pemasukan" atau "pengeluaran"
      double amount;    // nominal uang. double agar bisa desimal
      string category;  // kategori misalnya : "Makanan", "Gaji"
      string note;      // catatan atau deskripsi singkat
};

void organizer(); // ini sudah ku buat
void customer(); // ini sudah ku buat
void viewAllTransactions(); // belum ku buat
void deleteTransactionById(); // belum ku buat
void clearAllHistory(); // belum ku buat
void addIncome(); // sudah ku buat
void addExpense(); // sudah ku buat
void updateTransaction(); // belum ku buat // digunakan untuk mengedit salah nomial atau mengubah nominal transaksi yang sudah lewat
void exportToReceipt(); // belum ku buat
void checkBalance(); // belum ku buat
void load(Transaction *&head); // belum ku buat
void save(Transaction *head); // belum ku buat

int const eventValue = 10;
vector<Transaction> transactions;

// MODE EDIT UNTUK MENGUBAH ISI TRANSAKSI
// 
void organizer() {
        cout << "                                                         ============================================\n";
        cout << "                                                                           ORGANIZER MENU                \n";
        cout << "                                                         ============================================\n";
        int choice;
        do {
                        cout << "1. View Events" << endl;
                        cout << "2. Delete Event" << endl;
                        cout << "3. Clear All History" << endl;
                        cout << "4. Back to Main Menu" << endl;
                        cout << "Enter your choice ";
            cin >> choice;

            switch (choice) {
            case 1: 
                viewAllTransactions();
                break;
            case 2:
                deleteTransactionById();
                break;
            case 3:
                clearAllHistory();
                break;
            case 4:
                return;
                break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }while (choice != 4);
}

// TAMPILAN MENU UNTUK PENGGUNA
// 
void customer() {
         cout << "                                                     ============================================\n";
         cout << "                                                                     CUSTOMER MENU                \n";
        cout << "                                                      ============================================\n";
    int choice;
     do {
                        cout << "1. Add Income" << endl;
                        cout << "2. Add Expense" << endl;
                        cout << "3. Edit Transaction" << endl;
                        cout << "4. View All Transaction" << endl;
                        cout << "5. Generate To Slip" << endl;
                        cout << "6. Check Balance" << endl;
                        cout << "7. Back to Main menu" << endl;
                        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: 
            addIncome();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            updateTransaction();
            break;
        case 4:
            viewAllTransactions();
            break;
        case 5:
            exportToReceipt();
            break;
        case 6:
            checkBalance();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
     } while (choice != 7);
}

// FUNGSI UNTUK MENAMBAHKAN PEMASUKAN
// 
void addIncome() {
    Transaction newTx;
        
    cout << "                                                     ============================================\n";
    cout << "                                                                   TAMBAH PEMASUKAN              \n";
    cout << "                                                     ============================================\n";

    newTx.id = transactions.size() + 1;
    newTx.type = "Pemasukan";
    
    cin.ignore();

    cin.ignore(); 
        
    cout << "                                                     Masukkan Tanggal (DD-MM-YYYY): ";
    getline(cin, newTx.date);

    cout << "                                                     Masukkan Nominal (Rp)        : ";
    cin >> newTx.amount;
    cin.ignore();

    cout << "                                                     Masukkan Kategori            : ";
    getline(cin, newTx.category);

    cout << "                                                     Masukkan Deskripsi/Note      : ";
    getline(cin, newTx.note);

    transactions.push_back(newTx);
    cout << "\n                                                     [SUKSES] Pemasukan berhasil dicatat!\n";
    cout << "                                                     ============================================\n";
}

// FUNGSI UNTUK MENAMBAHKAN PENGELUARAN
// 
void addExpense() {
    Transaction newTx;
        
    cout << "                                                     ============================================\n";
    cout << "                                                                  TAMBAH PENGELUARAN             \n";
    cout << "                                                     ============================================\n";

    newTx.id = transactions.size() + 1;
    newTx.type = "Pengeluaran";

    cin.ignore();

    cout << "                                                     Masukkan Tanggal (DD-MM-YYYY): ";
    getline(cin, newTx.date);

    cout << "                                                     Masukkan Nominal (Rp)        : ";
    cin >> newTx.amount;
    cin.ignore();

    cout << "                                                     Masukkan Kategori            : ";
    getline(cin, newTx.category);

    cout << "                                                     Masukkan Deskripsi/Note      : ";
    getline(cin, newTx.note);

    transactions.push_back(newTx);
    cout << "\n                                                     [SUKSES] Pengeluaran berhasil dicatat!\n";
    cout << "                                                     ============================================\n";
}

int main() {
    // untuk setup tampilan aplikasi di terminal
    changeColor("9F");
    clearScreen();

    // load data yang berjalan di ram saat membuka aplikasi
    // load();

    cout << "                                           ****************************************************" << endl;
        cout << "                                                                                           " << endl;
        cout << "                                                  WELCOME TO PERSONAL FINANCE CLI                          " << endl;
        cout << "                                                                                          " << endl;
        cout << "                                       ****************************************************" << endl;
        cout << "                                              Catat | Atur | Pantau | Amankan Keuanganmu           " << endl;
        cout << "                                       ****************************************************" << endl;

    while (true) {
        cout << "\n                                                                    Menu Main:" << endl;
        cout << "                                                                  1. Organizer Menu (Auditor)" << endl;
        cout << "                                                                  2. Customer Menu (Pencatat)" << endl;
        cout << "                                                                  3. Close & Save System" << endl;                   
        cout << "                                                                 Enter your choice: ";

        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            clearScreen();
            organizer();
            break;
        case 2:
            clearScreen();
            customer();
            break;
        case 3:
            clearScreen();
            // save();
            cout << "                                                             ********************************" << endl;
            cout << "                                                        Terima kasih telah menggunakan sistem pencatatan keuangan!\n";
            cout << "                                                             ********************************" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}