#pragma once 

#include <memory>

#include <QtWidgets/QApplication>

class Application {
public:
    Application();

    int run();
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
