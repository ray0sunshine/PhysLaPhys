#include <gtkmm.h>
#include <gtkglmm.h>
#include "appwindow.hpp"

int main(int argc, char** argv){
  Gtk::Main kit(argc, argv);
  Gtk::GL::init(argc, argv);
  AppWindow window;
  Gtk::Main::run(window);
}
