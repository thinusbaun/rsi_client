#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T16:16:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filmaster-client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
#    GenericRegistry.cpp \
    IdentifiedObject.cpp \
    Actor.cpp \
    SexObj.cpp \
    Director.cpp \
    Movie.cpp \
    FilmasterClient.cpp \
    FilmasterStaticClient.cpp \
    MovieListModel.cpp \
    MovieDetailsDialog.cpp \
    ScreeningListDialog.cpp \
    ScreeningListModel.cpp \
    Screening.cpp \
    ReservationDialog.cpp \
    Reservation.cpp \
    AllReservationsDialog.cpp \
    AllReservationsModel.cpp

HEADERS += \
        MainWindow.h \
    GenericRegistry.h \
    IdentifiedObject.h \
    Actor.h \
    SexObj.h \
    Director.h \
    Movie.h \
    FilmasterClient.h \
    FilmasterStaticClient.h \
    MovieListModel.h \
    MovieDetailsDialog.h \
    ScreeningListDialog.h \
    ScreeningListModel.h \
    Screening.h \
    ReservationDialog.h \
    Reservation.h \
    AllReservationsDialog.h \
    AllReservationsModel.h

FORMS += \
        MainWindow.ui \
    MovieDetailsDialog.ui \
    ScreeningListDialog.ui \
    ReservationDialog.ui \
    AllReservationsDialog.ui

RESOURCES += \
    resources.qrc
