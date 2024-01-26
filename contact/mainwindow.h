#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

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
    QVBoxLayout* mainLayout;

    QLabel* TitleCompany;
    QLabel* TitleSubject;
    QLabel* TitleMDSInfo;
    QLabel* TitleStudentInfo;

    QLabel* SubTitleCompany_Name;
    QLabel* SubTitleCompany_domain;

    QLabel* SubTitleMDS_Name;
    QLabel* SubTitleMDS_Surname;
    QLabel* SubTitleMDS_Contact;

    QLabel* SubTitleStudent_Name;
    QLabel* SubTitleStudent_Surname;
    QLabel* SubTitleStudent_Mail;

    QPushButton* push_button;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init_components(void);
    void init_layout(void);
    void init_pDroite(void);
};
#endif // MAINWINDOW_H
