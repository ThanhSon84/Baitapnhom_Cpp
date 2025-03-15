#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> // Thư viện hỗ trợ hàm rand() và system()
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>

///============== Thư viện mã hóa và băm dữ liệu Crypto++
#include <sha.h>       // Thư viện SHA-256
using CryptoPP::SHA256;
#include <filters.h>  // Thư viện xử lý dữ liệu
#include <cryptlib.h>
using namespace std;
using namespace CryptoPP;
using CryptoPP::Exception;

#include "pch.h"
#include "aes.h"
#include <Windows.h>

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "aes.h"
using CryptoPP::AES;

#include "ccm.h"
using CryptoPP::CBC_Mode;

#include "assert.h"
///============== Thư viện mã hóa và băm dữ liệu Crypto++

// ========== 1. Lớp User: Quản lý thông tin tài khoản người dùng ==========

class User {
private:
    string username;         // Tên người dùng
    string hashedPassword;   // Mật khẩu (được băm)
    string email;            // Email người dùng

public:
    // Constructor mặc định (dùng cho danh sách nhiều người dùng)
    User() {}

    // Constructor khởi tạo với tham số
    User(string username, string hashedPassword, string email)
        : username(username), hashedPassword(hashedPassword), email(email) {}

    // Lấy tên người dùng
    string getUsername() const {
        return username;
    }

    // Xác minh mật khẩu người dùng
    bool verifyPassword(const string& password) const {
        return password == hashedPassword; // TODO: Thay bằng cơ chế băm
    }

    // Thay đổi mật khẩu
    void changePassword(const string& newPassword) {
        hashedPassword = newPassword; // TODO: Thay bằng mã hóa băm
    }

    // Thay đổi email
    void updateEmail(const string& newEmail) {
        email = newEmail;
    }

    // Hiển thị thông tin tài khoản
    void displayInfo() const {
        cout << "Username: " << username << ", Email: " << email << endl;
    }

    // Ghi thông tin người dùng xuống tệp
    void saveToFile() const {
        ofstream file("users.txt", ios::app); // Mở tệp ở chế độ ghi thêm
        if (file.is_open()) {
            file << username << " " << hashedPassword << " " << email << endl;
            file.close();
        }
    }

    // Tải danh sách người dùng từ tệp
    static unordered_map<string, User> loadAllUsers() {
        unordered_map<string, User> users;
        ifstream file("users.txt");
        if (file.is_open()) {
            string username, hashedPassword, email;
            while (file >> username >> hashedPassword >> email) {
                users[username] = User(username, hashedPassword, email);
            }
            file.close();
        }
        return users;
    }
};

// ========== 2. Hàm sinh mã OTP // HashPassword ==========

// Sinh mã OTP ngẫu nhiên (6 chữ số)
string generateOTP() {
    srand(time(0)); // Khởi tạo seed ngẫu nhiên dựa vào thời gian thực
    string otp;
    for (int i = 0; i < 6; i++) {
        otp += to_string(rand() % 10); // Tạo từng chữ số ngẫu nhiên
    }
    return otp;
}

string hashPassword(const std::string& password) {
    // Tạo salt ngẫu nhiên bằng AutoSeededRandomPool
    CryptoPP::AutoSeededRandomPool rng;
    byte salt[CryptoPP::SHA256::DIGESTSIZE]; // Salt có kích thước bằng kích thước của SHA-256 hash
    rng.GenerateBlock(salt, sizeof(salt));

    // Kết hợp password và salt
    std::string salted_password = password + std::string(reinterpret_cast<char*>(salt), sizeof(salt));

    // Khai báo đối tượng SHA-256
    CryptoPP::SHA256 hash;

    // Mảng để lưu kết quả băm
    byte digest[CryptoPP::SHA256::DIGESTSIZE];

    // Băm dữ liệu
    hash.CalculateDigest(digest, reinterpret_cast<const byte*>(salted_password.data()), salted_password.size());

    // Chuyển đổi kết quả băm sang dạng hex
    CryptoPP::HexEncoder encoder;
    std::string hashed_password;
    encoder.Attach(new CryptoPP::StringSink(hashed_password));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    // In kết quả
    std::cout << "Password: " << password << std::endl;
    std::cout << "Salt (hex): ";
    for (int i = 0; i < sizeof(salt); i++) {
        std::cout << std::hex << (int)salt[i];
    }
    std::cout << std::endl;
    std::cout << "SHA-256 Hashed password with salt: " << hashed_password << std::endl;
    return hashed_password;
}

// Hàm đối chiếu mật khẩu
/*bool VerifyPassword(const std::string& input_password, const std::string& stored_hash, const byte* salt, size_t saltSize) {
    // Tạo mã hash từ mật khẩu nhập vào và salt đã lưu trữ
    std::string input_hash = HashPassword(input_password, salt, saltSize);

    // So sánh mã hash nhập vào với mã hash đã lưu trữ
    return input_hash == stored_hash;
}*/

// ========== 3. Lớp Wallet: Quản lý giao dịch và ví ==========

class Wallet {
private:
    string walletID; // ID của ví
    double balance;  // Số dư trong ví

public:
    // Constructor khởi tạo ví
    Wallet(string id, double initialBalance = 0.0)
        : walletID(id), balance(initialBalance) {}

    // Lấy ID ví
    string getWalletID() const {
        return walletID;
    }

    // Lấy số dư trong ví
    double getBalance() const {
        return balance;
    }

    // Thực hiện giao dịch chuyển điểm
    bool transferTo(Wallet& targetWallet, double amount, const string& otp) {
        // Xác nhận OTP trước khi giao dịch
        string inputOtp;
        cout << "Nhập mã OTP để xác nhận giao dịch: ";
        cin >> inputOtp;

        if (inputOtp != otp) {
            cout << "Mã OTP không hợp lệ. Giao dịch bị hủy." << endl;
            return false;
        }

        if (balance >= amount) {
            balance -= amount;                    // Trừ tiền ví gửi
            targetWallet.balance += amount;       // Cộng tiền ví nhận
            logTransaction(targetWallet.getWalletID(), amount);
            cout << "Giao dịch thành công!" << endl;
            return true;
        }
        else {
            cout << "Số dư không đủ. Giao dịch thất bại." << endl;
            return false;
        }
    }

    // Hiển thị số dư ví
    void displayBalance() const {
        cout << "Wallet ID: " << walletID << ", Số dư: " << balance << endl;
    }

    // Ghi lại lịch sử giao dịch
    void logTransaction(const string& targetWalletID, double amount) const {
        ofstream file("transaction_log.txt", ios::app);
        if (file.is_open()) {
            file << "From: " << walletID << ", To: " << targetWalletID
                << ", Amount: " << amount << ", Time: " << time(0) << endl;
            file.close();
        }
    }
};

// ========== 4. Lớp LoginManager: Quản lý đăng nhập và OTP ==========

class LoginManager {
private:
    unordered_map<string, User> users; // Danh sách người dùng (nạp từ tệp)

public:
    // Constructor: Tải tất cả người dùng từ tệp
    LoginManager() {
        users = User::loadAllUsers();
    }

    // Đăng nhập tài khoản
    bool login(const string& username, const string& password) {
        if (users.find(username) != users.end()) {
            if (users[username].verifyPassword(password)) {
                cout << "Đăng nhập thành công!" << endl;
                return true;
            }
            else {
                cout << "Sai mật khẩu." << endl;
            }
        }
        else {
            cout << "Tài khoản không tồn tại." << endl;
        }
        return false;
    }

    // Gửi yêu cầu OTP
    void requestOTP(const string& username) {
        if (users.find(username) != users.end()) {
            string otp = generateOTP();
            cout << "Mã OTP của bạn: " << otp << endl;
            // TODO: Tích hợp gửi OTP qua email hoặc SMS
        }
        else {
            cout << "Người dùng không tồn tại." << endl;
        }
    }
};

// ========== 5. Hàm main: Chương trình chính ==========

int main() {
    LoginManager loginManager;

    // Tạo người dùng mới
    cout << "Tạo tài khoản người dùng mới:" << endl;
    string newUsername, newPassword, newEmail;
    cout << "Tên đăng nhập: ";
    cin >> newUsername;
    cout << "Mật khẩu: ";
    cin >> newPassword;
    cout << "Email: ";
    cin >> newEmail;

    User newUser(newUsername, newPassword, newEmail);
    newUser.saveToFile();
    cout << "Đã tạo tài khoản thành công!" << endl;

    // Đăng nhập
    string username, password;
    cout << "Đăng nhập hệ thống:" << endl;
    cout << "Tên đăng nhập: ";
    cin >> username;
    cout << "Mật khẩu: ";
    cin >> password;

    if (loginManager.login(username, password)) {
        // Yêu cầu OTP nếu đăng nhập thành công
        cout << "Yêu cầu mã OTP để tiếp tục." << endl;
        loginManager.requestOTP(username);
    }

    return 0;
}
