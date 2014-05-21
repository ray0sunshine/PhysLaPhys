#include "appwindow.hpp"
#include <iostream>

AppWindow::AppWindow(){
  set_title("Shameful Dispray!!");
  using Gtk::Menu_Helpers::MenuElem;
  using Gtk::Menu_Helpers::RadioMenuElem;

  //update at > 60fps
  tick = sigc::mem_fun(m_viewer, &Viewer::update);
  Glib::signal_timeout().connect(tick, 16);

  // Pack in widgets:
  add(m_vbox);
  m_vbox.pack_start(m_menubar, Gtk::PACK_SHRINK);

  // Put the viewer below the menubar. pack_start "grows" the widget by default, so it'll take up the rest of the window.
  m_viewer.set_size_request(1200,650);
  m_vbox.pack_start(m_viewer);
  show_all();
}

bool AppWindow::on_key_press_event(GdkEventKey *e){
  m_viewer.keyHandle(e);
  return true;
}

bool AppWindow::on_key_release_event(GdkEventKey *e){
  m_viewer.keyHandleup(e);
  return true;
}

bool AppWindow::on_configure_event(GdkEventConfigure* e){
  m_viewer.scrX = e->x;
  m_viewer.scrY = e->y;
  return true;
}
