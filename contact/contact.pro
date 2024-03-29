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
    main.cpp \
    mainwindow.cpp \
    src/controller/dataController.cpp \
    src/controller/companyController.cpp \
    src/controller/internshipController.cpp \
    src/controller/studentController.cpp \
    src/controller/mdsController.cpp \
    src/view/formulaireAjoutEntreprise.cpp \
    src/view/formulaireajoutcontact.cpp \
    src/view/formulaireajoutetudiant.cpp \
    src/view/mainview.cpp \

HEADERS += \
    src/models/company.h \
    src/models/internship.h \
    src/models/mds.h \
    src/models/student.h \
    mainwindow.h \
    src/controller/dataController.h \
    src/controller/companyController.h \
    src/controller/internshipController.h \
    src/controller/studentController.h \
    src/controller/mdsController.h \
    src/view/formulaireAjoutEntreprise.h \
    src/view/formulaireajoutcontact.h \
    src/view/formulaireajoutetudiant.h \
    src/view/mainview.h \

FORMS += \
    mainwindow.ui \

DISTFILES += \
    ressources/Entreprise.csv \
    ressources/Etudiant.csv \
    ressources/MDS.csv \
    ressources/Stage.csv \
    ressources/TableEtuSta.csv \
    ressources/TableMDSSta.csv \
    ressources/image/LOGO_ESEO.jpg \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
