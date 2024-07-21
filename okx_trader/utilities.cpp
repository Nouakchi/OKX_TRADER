#include "headers.h"

bool isNumber(std::string str)
{
    std::regex reg ("^-?\\d+");
    return (std::regex_match (str, reg));
}

std::string hmac_sha256(const std::string &key, const std::string &data)
{
    unsigned char* digest;
    digest = HMAC(EVP_sha256(), key.c_str(), key.length(), (unsigned char*)data.c_str(), data.length(), NULL, NULL);
    char mdString[SHA256_DIGEST_LENGTH*2+1];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    return std::string(mdString);
}

std::string get_timestamp()
{
    time_t now = time(0);
    char buf[sizeof "2021-01-01T00:00:00Z"];
    strftime(buf, sizeof buf, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
    return std::string(buf);
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to read a string from stdin with validation
bool readString(const std::string& prompt, std::string& value) 
{
    std::cout << prompt;
    std::getline(std::cin, value);
    return !value.empty();
}

// Function to read a float from stdin with validation
bool readFloat(const std::string& prompt, float& value) 
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    if (ss >> value && ss.eof()) {
        return true;
    }
    return false;
}