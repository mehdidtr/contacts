QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/models/company.cpp \
    src/models/internship.cpp \
    src/models/mds.cpp \
    src/models/student.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
	src/controller/dataController.cpp \

HEADERS += \
    src/models/company.h \
    src/models/internship.h \
    src/models/mds.h \
    src/models/student.h \
    src/mainwindow.h \
	src/controller/dataController.h \

FORMS += \
    mainwindow.ui

DISTFILES += \
    ressources/Entreprise.csv \
    ressources/Etudiant.csv \
    ressources/MDS.csv \
    ressources/Stage.csv \
    ressources/TableEtuSta.csv \
    ressources/TableMDSSta.csv \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
