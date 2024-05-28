#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <regex>
#include <vector>
#include <iomanip>

// Funkcija, kuri ištrina skyrybos ženklus iš žodžio, išskyrus '.' ir '/' ir ':'
std::string Filtruojame_zodzius(const std::string &zodis) {
    std::string isfiltruotas;
    for (char ch : zodis) {
        if (std::isalnum(ch) || ch == '.' || ch == '/' || ch == ':') {
            isfiltruotas += ch;
        }
    }
    return isfiltruotas;
}

// Funkcija, kuri tikrina ar žodis yra URL, naudojant regex
bool Tikriname_url(const std::string &zodis) {
    const std::regex url_struktura(R"((http://|https://|www\.|[a-zA-Z0-9.-]+\.(com|org|net|edu|gov|io|co|lt|uk|us|ca)))");
    return std::regex_search(zodis, url_struktura);
}

// Funkcija failo nuskaitymui ir žodžių ir URL masyvų pildymui
void Nuskaitymas(const std::string &filename, 
                 std::map<std::string, std::pair<int, std::set<int>>> &word_map,
                 std::map<std::string, std::pair<int, std::set<int>>> &url_map,
                 std::vector<std::string> &urls) {
    std::ifstream fd(filename);
    if (!fd) {
        std::cerr << "Nepavyksta atidaryti failo" << std::endl;
        exit(1);
    }

    std::string eilute;
    int eiluciu_sk = 0;

    while (std::getline(fd, eilute)) {
        ++eiluciu_sk;
        std::istringstream iss(eilute);
        std::string zodis;

        while (iss >> zodis) {
            std::string isfiltruoti_zodziai = Filtruojame_zodzius(zodis);
            if (!isfiltruoti_zodziai.empty()) {
                if (Tikriname_url(isfiltruoti_zodziai)) {
                    url_map[isfiltruoti_zodziai].first++;
                    url_map[isfiltruoti_zodziai].second.insert(eiluciu_sk);
                    urls.push_back(isfiltruoti_zodziai);
                } else {
                    word_map[isfiltruoti_zodziai].first++;
                    word_map[isfiltruoti_zodziai].second.insert(eiluciu_sk);
                }
            }
        }
    }

    fd.close();
}

// Funkcija rezultatų įrašymui į failą
void Isvedimas(const std::string &filename, 
                        const std::map<std::string, std::pair<int, std::set<int>>> &word_map, 
                        const std::map<std::string, std::pair<int, std::set<int>>> &url_map,
                        const std::vector<std::string> &urls) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failo nepavyko sukurti." << std::endl;
        return;
    }

    out << "URLS skaičius: " << urls.size() << std::endl;
    for (const auto& url : urls)
        out << url << std::endl;

    out << std::endl;

    if (!word_map.empty()) {
        out << std::left << std::setw(30) << "ŽODIS" << std::setw(10) << "KIEKIS" << "EILUČIŲ NR." << std::endl;

        for (const auto& i : word_map) {
            if (i.second.first > 1) {
                out << std::left << std::setw(30) << i.first << std::setw(10) << i.second.first;

                for (int j : i.second.second) {
                    out << std::setw(4) << j;
                }

                out << std::endl;
            }
        }
    }

    out.close();
}

int main() {
    std::map<std::string, std::pair<int, std::set<int>>> word_map;
    std::map<std::string, std::pair<int, std::set<int>>> url_map;
    std::vector<std::string> urls;

    // Nuskaitome failą KevinHart.txt ir pildome žodžių ir URL masyvus
    Nuskaitymas("KevinHart.txt", word_map, url_map, urls);

    // Rezultatus matysime faile rezultatai.txt
    Isvedimas("rezultatai.txt", word_map, url_map, urls);

    return 0;
}
