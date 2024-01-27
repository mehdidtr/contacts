#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include "src/controller/dataController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget* centre;
    QLabel* label;
    QVBoxLayout* vboxlayout;

    QWidget* pDroiteWidget;
    QVBoxLayout* pDroiteLayout;
    QWidget* pDroiteModifyWidget;
    QVBoxLayout* pDroiteModifyLayout;
    QVBoxLayout* mainLayout;

    QLabel* TitleCompany;
    QLabel* TitleSubject;
    QLabel* TitleMDSInfo;
    QLabel* TitleStudentInfo;

    QLabel* SubTitleCompany_Name;
    QLabel* SubTitleCompany_domain;

    QLabel* SubjectDetails;

    QLabel* SubTitleMDS_Name;
    QLabel* SubTitleMDS_Surname;
    QLabel* SubTitleMDS_Contact;

    QLabel* SubTitleStudent_Name;
    QLabel* SubTitleStudent_Surname;
    QLabel* SubTitleStudent_Mail;
    QLabel* SubTitleStudent_Promotion;

    QPushButton* push_button_modify;
    QPushButton* push_button_save;

    QLineEdit* lineEditCompanyName;
    QLineEdit* lineEditCompanyDomain;
    QLineEdit* lineEditSubject;
    QLineEdit* lineEditMDSName;
    QLineEdit* lineEditMDSSurname;
    QLineEdit* lineEditMDSContact;
    QLineEdit* lineEditStudentName;
    QLineEdit* lineEditStudentSurname;
    QLineEdit* lineEditStudentMail;
    QLineEdit* lineEditStudentPromotion;

    QFont fontTitle;
    QFont fontSubTitle;

    dataController* dataCtrl;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init_components(void);
    void init_layout(void);
    void init_pDroite(void);   
    void clear_pDroite(void);
    void dataFromController();

private slots:
    void init_pDroite_Modify(void);

};
#endif // MAINWINDOW_H
