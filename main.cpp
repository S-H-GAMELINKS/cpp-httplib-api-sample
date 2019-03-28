#include <iostream>
#include "cpp-httplib/httplib.h"
#include <sstream>
#include <string>
#include <vector>

int main() {

    std::cout << "C++ API is UP!" << std::endl;

    std::vector<std::string> talks;

    httplib::Server svr;

    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hi! Welcome to C++ API!", "text/plain");
    });


    svr.Get("/talks", [&](const httplib::Request& req, httplib::Response& res) {

        std::ostringstream content;

        for(auto&& t : talks)
            content << "{ " << t.c_str() << " }," ;
        
        res.set_content(content.str(), "text/plain");
    });

    svr.Post("/talks", [&](const httplib::Request& req, httplib::Response& res){
        talks.emplace_back(std::move(req.body));

        res.set_content("Create Talks!", "text/plain");
    });

    svr.listen("localhost", 3000);

    return 0;
}