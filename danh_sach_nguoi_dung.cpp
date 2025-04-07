#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <set>

// Tạo tên ngẫu nhiên
std::string RandomName() {
    const std::string firstNames[] = {"Nguyen", "Tran", "Le", "Pham", "Hoang", "Vu", "Bui", "Mai", "Hoang", "Dinh"};
    const std::string lastNames[] = {"An", "Binh", "Chi", "Duy", "Hieu", "Khanh", "Linh", "My", "Quyen", "Thao"};
    const std::string middleNames[] = {"Thi", "Ngoc", "Thanh", "Quoc", "Hoang", "Minh", "Tu", "Thanh", "Tuan"};

    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> firstName(0, 9);
    std::uniform_int_distribution<> middleName(0, 8);
    std::uniform_int_distribution<> lastName(0, 9);
    std::uniform_int_distribution<> namePartsDist(2, 4);

    int nameParts = namePartsDist(gen); // Chọn số lượng từ (2, 3, hoặc 4)

    std::string name = firstNames[firstName(gen)];  // Chọn họ đầu tiên

    if (nameParts > 1) {
        name += " " + middleNames[middleName(gen)];  // Chọn tên đệm nếu cần
    }
    if (nameParts > 2) {
        name += " " + middleNames[middleName(gen)];  // Thêm tên đệm nếu cần
    }
    if (nameParts > 3) {
        name += " " + lastNames[lastName(gen)];  // Thêm họ cuối cùng nếu cần
    }
    
    return name;
}

// Tạo một ngày sinh ngẫu nhiên (giới hạn từ 1980 đến 2010)
std::string RandomBirthDate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> yearDist(1980, 2010);
    std::uniform_int_distribution<> monthDist(1, 12);
    std::uniform_int_distribution<> dayDist(1, 31);
    
    int year = yearDist(gen);
    int month = monthDist(gen);
    int day = dayDist(gen);
    
    // Điều chỉnh ngày nếu vượt quá số ngày trong tháng
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        day = 30;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                day = 29;
            }
        } else {
            if (day > 28) {
                day = 28;
            }
        }
    }
    
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "/"
       << std::setfill('0') << std::setw(2) << month << "/"
       << year;
    
    return ss.str();
}

// Tạo số điện thoại ngẫu nhiên
std::string RandomPhoneNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> dist(100000000, 999999999);
    int phone = dist(gen);
    
    return "0" + std::to_string(phone);
}

// Tạo số CCCD ngẫu nhiên và đảm bảo tính duy nhất
std::string UniqueCCCD(std::set<std::string>& cccdSet) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100000000, 999999999);
    
    std::string cccd;
    do {
        cccd = std::to_string(dist(gen));
    } while (cccdSet.find(cccd) != cccdSet.end()); // Kiểm tra số CCCD đã có chưa
    
    cccdSet.insert(cccd); // Thêm số CCCD vào tập hợp đã kiểm tra
    return cccd;
}

// Tạo email ngẫu nhiên
std::string RandomEmail(const std::string& name, const std::string& phone) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> lengthDist(2, 4);  // Số chữ số ngẫu nhiên từ số điện thoại
    
    // Tách tên thành các phần (họ, tên đệm, tên)
    std::string emailName = name;
    std::string firstName = emailName.substr(0, emailName.find(" "));  // Lấy phần họ hoặc tên đầu tiên
    emailName = emailName.substr(emailName.find(" ") + 1);
    std::string middleName = (emailName.find(" ") != std::string::npos) ? emailName.substr(0, emailName.find(" ")) : "";  // Tên đệm (nếu có)
    
    // Chọn số ngẫu nhiên từ số điện thoại
    int length = lengthDist(gen);  // Chọn số lượng chữ số ngẫu nhiên (2 đến 4)
    std::string phoneDigits = phone.substr(1); // Loại bỏ ký tự '0'
    std::string emailNumber = phoneDigits.substr(0, length);  // Lấy một số ngẫu nhiên từ số điện thoại
    
    // Tạo email
    std::string email = firstName;  // Bắt đầu với tên (họ hoặc tên đầu tiên)
    if (!middleName.empty()) {
        email += middleName;  // Thêm tên đệm nếu có
    }
    email += emailNumber;  // Thêm số ngẫu nhiên từ số điện thoại
    email += "@gmail.com";  // Định dạng email
    
    return email;
}

int main() {
    int numUsers = 10; // Số lượng người dùng muốn tạo
    std::set<std::string> cccdSet; // Set lưu trữ các số CCCD đã được tạo
    
    for (int i = 0; i < numUsers; i++) {
        std::string name = RandomName();
        std::string birthDate = RandomBirthDate();
        std::string phone = RandomPhoneNumber();
        std::string cccd = UniqueCCCD(cccdSet);
        std::string email = RandomEmail(name, phone);
        
        std::cout << "User " << i + 1 << ":\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Birth Date: " << birthDate << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "CCCD: " << cccd << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "\n";
    }

    return 0;
}
