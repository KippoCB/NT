#include "app.h"

struct Application::Impl {
    QApplication app();
};

Application::Application()
    : impl(std::make_unique<Impl>())
{
    
}

int Application::run() {
    
}
