#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include "PropertiesSingleton.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setActivePropertiesTrue();
    void setActivePropertiesFalse();


private slots:
    void on_actionExit_Program_triggered();

    void on_actionCreate_triggered();

    void on_actionClose_triggered();

    void on_createRadioButton_toggled(bool checked);

    void on_updateRadioButton_toggled(bool checked);

    void on_deleteRadioButton_toggled(bool checked);

    void on_actionHTTP_toggled();

    void on_actionTCP_toggled();

    void on_commitPushButton_pressed();

private:
    Ui::MainWindow *ui;
    QActionGroup* menuBarGroup;
    PropertiesSingleton& _propertiesSingleton;
};

#endif // MAINWINDOW_H
