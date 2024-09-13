TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.6.1/include"
LIBS += -L"C:/SFML-2.6.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
SOURCES += \
        enemyship.cpp \
        game.cpp \
        laser.cpp \
        main.cpp \
        playership.cpp

HEADERS += \
    enemyship.h \
    game.h \
    laser.h \
    playership.h
