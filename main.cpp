#include <QApplication>
#include "Actor.h"
#include "FilmasterStaticClient.h"
#include "GenericRegistry.h"
#include "MainWindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  FilmasterClient* clientInstance = new FilmasterStaticClient();
  MainWindow w(clientInstance);
  w.show();
  return a.exec();
}
