#include "headers.h"

std::string send_request(const std::string &method, const std::string &endpoint, const std::string &body = "") 
{
    std::string api_key = std::getenv("API_KEY") ? std::getenv("API_KEY") : "f7db8d7a-b05e-458a-8cc7-b10252f60f30";
    std::string secret_key = std::getenv("SECRET_KEY") ? std::getenv("SECRET_KEY") : "315579F51BC76893B614B795675E5637";
    std::string passphrase = std::getenv("PASSPHRASE") ? std::getenv("PASSPHRASE") : "GoQuant1$";
    std::string base_url = "https://www.okx.com";

    std::string timestamp = get_timestamp();
    std::string message = timestamp + method + endpoint + body;
    std::string signature = hmac_sha256(secret_key, message);

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        std::string url = base_url + endpoint;

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, ("OK-ACCESS-KEY: " + api_key).c_str());
        headers = curl_slist_append(headers, ("OK-ACCESS-SIGN: " + signature).c_str());
        headers = curl_slist_append(headers, ("OK-ACCESS-TIMESTAMP: " + timestamp).c_str());
        headers = curl_slist_append(headers, ("OK-ACCESS-PASSPHRASE: " + passphrase).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        if(method == "POST") {
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        }

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return readBuffer;
}