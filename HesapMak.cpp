#include <iostream>
#include <cmath>
//iostreaminizde zaten cmath eklentisi varsa bu satırı silebilirsiniz fakat silmesenizde hata vermez.

//PI sayısı normalde tam olarak 3,14 e eşit değildir.
//fakat üniversitelerde genelde 3,14  den hesaplama yapılır.
//EGER ISTERSENIZ ALTTAKI CONS DOUBLE PI = xxx İ İSTEDİĞİNİZ SAYI YAPABİLİRSİNİZ. 

const double PI = 3.14;

// Fonksiyonlar
void calculate_basic_operations();
void calculate_scientific_functions();
void calculate_si_units();

// Terminalde Gösterilecek seçim ekranı 

int main() {
    int choice;
    do {
        std::cout << "\n--- SI BIRIM SISTEMINE UYGUN SCIENTIFIC CALCULATOR ---\n";
        std::cout << "1. Basit Matematiksel Hesaplamalar\n";
        std::cout << "2. Trigonometrik Hesaplamalar\n";
        std::cout << "3. Bileşke kuvvet Hesaplama\n";
        std::cout << "4. Cıkıs\n";
        std::cout << "Lütfen birini seçiniz: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                calculate_basic_operations();
                break;
            case 2:
                calculate_scientific_functions();
                break;
            case 3:
                calculate_si_units();
                break;
            case 4:
                std::cout << "Cıkış yapılıyor\n";
                break;
            default:
                std::cout << "Hatalı giriş dah sonra tekrar deneyin.\n";
        }
    } while (choice != 4);

    return 0;
}

// Dereceden radyana dönüşüm formülü.
// pi(bu orjinal kodda 3,14)

double degrees_to_radians(double degrees) {
    return degrees * (PI / 180.0);
}

// Temel Matematiksel İşlemler
// Toplama, Cıkarma, Carpma, Bolme 

void calculate_basic_operations() {
    double num1, num2;
    char operation;
    std::cout << "\n---Basit Matematiksel İşlemler---\n";
    std::cout << "İlk sayıyı giriniz.: ";
    std::cin >> num1;
    std::cout << "İşlemlerden birini seçiniz (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "İkinci sayıyı giriniz.: ";
    std::cin >> num2;

    switch (operation) {
        case '+':
            std::cout << "Sonuç: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Sonuç: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Sonuç: " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Sonuç: " << num1 / num2 << "\n";
            else
                std::cout << "HATA: BOLME ISLEMINDE 0 ETKISIZ ELEMANDIR...\n";
            break;
        default:
            std::cout << "Hatalı Seçim.\n";
    }
}

// Geometrik işlemler ve Cebirsel işlemler...
// Sin, Cos, Tan, Log, Exp, Sqrt 
void calculate_scientific_functions() {
    int choice;
    double num;
    std::cout << "\n---  ---\n";
    std::cout << "1. Sin (sin)\n";
    std::cout << "2. Cos (cos)\n";
    std::cout << "3. Tan (tan)\n";
    std::cout << "4. Log (log)\n";
    std::cout << "5. Exp (exp)\n";
    std::cout << "6. Karekok (sqrt)\n";
    std::cout << "Seçiminizi giriniz: ";
    std::cin >> choice;

    if (choice == 1 || choice == 2 || choice == 3) {  std::cout << "Açıyı giriniz.: ";
        std::cin >> num;

        // Dereceyi radyana çevirme işlemi

        num = degrees_to_radians(num);
    } else {
        std::cout << "Sayı Girin: ";
        std::cin >> num;
    }

    switch (choice) {
        case 1:
            std::cout << "Sin: " << std::sin(num) << "\n";
            break;
        case 2:
            std::cout << "Cos: " << std::cos(num) << "\n";
            break;
        case 3:
            std::cout << "Tan: " << std::tan(num) << "\n";
            break;
        case 4:
            if (num > 0)
                std::cout << "Log: " << std::log(num) << "\n";
            else
                std::cout << "HATA: Logaritma sıfır veya negatif olamaz.\n";
            break;
        case 5:
            std::cout << "Exp: " << std::exp(num) << "\n";
            break;
        case 6:
            if (num >= 0)
                std::cout << "Karekok: " << std::sqrt(num) << "\n";
            else
                std::cout << "HATA: Karekok negatif veya sıfır olamaz.\n";
            break;
        default:
            std::cout << "Hatalı giriş.\n";
    }
}

// SI birim sistemi hesaplamaları
// Türetilmiş Birim sistemleri asagıda oldugu gibidir.
// Güncel olarak kullandığımız ve AB de kullanılan birim SI sistemidir.
// Bulduğumuz bu sonuçları SI birim sistemine göre düzenlemimiz gerek.

void calculate_si_units() {
    int choice;
    std::cout << "\n--- SI Birim Hesaplaması ---\n";
    std::cout << "1. Enerji (Joule = N·m)\n";
    std::cout << "2. Power (Watt = J/s)\n";
    std::cout << "3. Basınç (Pascal = N/m²)\n";
    std::cout << "4. Newton (Newton = kg·m/s²)\n";
    std::cout << "Seçiminizi giriniz.: ";
    std::cin >> choice;

    double param1, param2, result;

    switch (choice) {
        case 1: // Energy = Force × Distance
            std::cout << "Newton cinsinden Force u giriniz. (Newton): ";
            std::cin >> param1;
            std::cout << "Metre cinsinden Mesafeyi giriniz (Metre): ";
            std::cin >> param2;
            result = param1 * param2;
            std::cout << "Enerji: " << result << " Joul\n";
            break;
        case 2: // Power = Energy / Time
            std::cout << "Joul cinsinden Enerjiyi giriniz (Joul): ";
            std::cin >> param1;
            std::cout << "Saniye cinsinden Zamanı girin (Saniye)): ";
            std::cin >> param2;
            if (param2 != 0) {
                result = param1 / param2;
                std::cout << "Power: " << result << " Watt\n";
            } else {
                std::cout << "HATA: Zaman sıfır olamaz.\n";
            }
            break;
        case 3: // Pressure = Force / Area 
            std::cout << "Newton cinsinden Force u giriniz. (Newton): ";
            std::cin >> param1;
            std::cout << "Metrekare cinsinden Alanı giriniz (M^2): ";
            std::cin >> param2;
            if (param2 != 0) {
                result = param1 / param2;
                std::cout << "Basınç: " << result << " Pascal\n";
            } else {
                std::cout << "Alan sıfır olamaz.\n";
            }
            break;
        case 4: // Force = Mass × Acceleration
            std::cout << "Kilogram cinsinden ağırlığı giriniz (KG): ";
            std::cin >> param1;
            std::cout << "m/s^2 cinsinden ivmeyi giriniz (in m/s²): ";
            std::cin >> param2;
            result = param1 * param2;
            std::cout << "Force: " << result << " Newton\n";
            break;
        default:
            std::cout << "Geçersiz seçim.\n";
    }
}