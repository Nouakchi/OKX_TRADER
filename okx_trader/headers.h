# ifndef HEADERS_H
# define HEADERS_H

#include <string>
#include <regex>
#include <limits> 
#include <iostream>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <curl/curl.h>
#include <ctime>
#include <cstdlib> 

/*################## -*- actions.cpp -*- ##################*/

void        placeOrder();
void        cancelOrder();
void        modifyOrder();
void        getOrderBook();
void        currentPosition();

/*################## -*- utilities.cpp -*- ##################*/

bool        isNumber(std::string str);
std::string get_timestamp();
std::string hmac_sha256(const std::string &key, const std::string &data);
size_t      WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
bool        readString(const std::string& prompt, std::string& value);
bool        readFloat(const std::string& prompt, float& value);

/*################## -*- consumer.cpp -*- ##################*/

std::string send_request(const std::string &method, const std::string &endpoint, const std::string &body);


# endif