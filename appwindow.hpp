#ifndef APPWINDOW_HPP
#define APPWINDOW_HPP
#include <gtkmm.h>
#include "viewer.hpp"

class AppWindow : public Gtk::Window{
public:
  AppWindow();

protected:
  virtual bool on_configure_event(GdkEventConfigure* e);
  virtual bool on_key_press_event(GdkEventKey *e);
  virtual bool on_key_release_event(GdkEventKey *e);

private:
  Gtk::VBox m_vbox;
  Gtk::MenuBar m_menubar;
  Viewer m_viewer;
  
  sigc::slot0<bool> tick;
};

#endif
