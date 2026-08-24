#include "window.h"


struct Window::Impl {
    QMainWindow win;
};

QMainWindow *Window::qtNativeHandle() {
    return &impl->win;
}

Window::Window(int width, int height, std::string title) 
    : impl(std::make_unique<Impl>()) 
{
    //
    // Set all vars
    this->width = width;
    this->height = height;
    this->title = title;

    //
    // Resize window to set sizes and check if user asked for default sizes
    if (width == CW_USEDEFAULT) {
        this->width = 640;
    } else if (height == CW_USEDEFAULT) {
        this->height = 480;
    }

    impl->win.resize(this->width, this->height);
    
    //
    // Set the window title 
    impl->win.setWindowTitle(QString::fromStdString(this->title));
}

Window::~Window() = default;

void Window::close() {
    impl->win.close();
}

void Window::resize(int width, int height) {
    this->width = width;
    this->height = height;

    impl->win.resize(width, height);
}

void Window::show() {
    impl->win.show();
}

void Window::setCentral(Widget& central) {
    impl->win.setCentralWidget(central.qtNativeHandle());
}
