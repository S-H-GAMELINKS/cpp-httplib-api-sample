#include <iostream>
#include "cpp-httplib/httplib.h"

int main() {

    std::cout << "C++ API is UP!" << std::endl;

    httplib::Server svr;

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hi! Welcome to C++ API!", "text/plain");
    });

    return 0;
}