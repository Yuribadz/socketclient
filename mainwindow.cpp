#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "HTTPClient.hpp"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _propertiesSingleton(PropertiesSingleton::getInstance())
{
    ui->setupUi(this);
    menuBarGroup = new QActionGroup(this);
    menuBarGroup->addAction(ui->actionTCP);
    menuBarGroup->addAction(ui->actionHTTP);
    menuBarGroup->setExclusive(true);
}

MainWindow::~MainWindow()
{
    delete menuBarGroup;
    delete ui;
}

void MainWindow::setActivePropertiesTrue()
{
    _propertiesSingleton.actionTCPActive = true;
    _propertiesSingleton.actionHTTPActive = true;
    _propertiesSingleton.createRadioButtonActive = true;
    _propertiesSingleton.updateRadioButtonActive = true;
    _propertiesSingleton.deleteRadioButtonActive = true;
    _propertiesSingleton.userNameLabelActive = true;
    _propertiesSingleton.firstNameLabelActive = true;
    _propertiesSingleton.lastNameLabelActive = true;
    _propertiesSingleton.phoneLabelActive = true;
    _propertiesSingleton.companyLabelActive = true;
    _propertiesSingleton.userNamelineEditActive = true;
    _propertiesSingleton.lastNamelineEditActive = true;
    _propertiesSingleton.phonelineEditActive = true;
    _propertiesSingleton.companyLineEditActive = true;
    _propertiesSingleton.commitPushButtonActive = true;
    // We set mainwindow active true only if all ui is active
    _propertiesSingleton.mainwindowActive = true;
}

void MainWindow::setActivePropertiesFalse()
{
    _propertiesSingleton.actionTCPActive = false;
    _propertiesSingleton.actionHTTPActive = false;
    _propertiesSingleton.createRadioButtonActive = false;
    _propertiesSingleton.updateRadioButtonActive = false;
    _propertiesSingleton.deleteRadioButtonActive = false;
    _propertiesSingleton.userNameLabelActive = false;
    _propertiesSingleton.firstNameLabelActive = false;
    _propertiesSingleton.lastNameLabelActive = false;
    _propertiesSingleton.phoneLabelActive = false;
    _propertiesSingleton.companyLabelActive = false;
    _propertiesSingleton.userNamelineEditActive = false;
    _propertiesSingleton.lastNamelineEditActive = false;
    _propertiesSingleton.phonelineEditActive = false;
    _propertiesSingleton.companyLineEditActive = false;
    _propertiesSingleton.commitPushButtonActive = false;
    // We set mainwindow active false only if all ui isn't active
    _propertiesSingleton.mainwindowActive = false;
}

void MainWindow::on_actionExit_Program_triggered()
{
    close();
}

void MainWindow::on_actionCreate_triggered()
{
    ui->actionTCP->setEnabled(true);
    ui->actionHTTP->setEnabled(true);
    ui->createRadioButton->setEnabled(true);
    ui->updateRadioButton->setEnabled(true);
    ui->deleteRadioButton->setEnabled(true);
    ui->userNameLabel->setEnabled(true);
    ui->firstNameLabel->setEnabled(true);
    ui->lastNameLabel->setEnabled(true);
    ui->phoneLabel->setEnabled(true);
    ui->companyLabel->setEnabled(true);
    ui->userNamelineEdit->setEnabled(true);
    ui->firstNamelineEdit->setEnabled(true);
    ui->lastNamelineEdit->setEnabled(true);
    ui->phonelineEdit->setEnabled(true);
    ui->companyLineEdit->setEnabled(true);
    ui->commitPushButton->setEnabled(true);
    setActivePropertiesTrue();
}

void MainWindow::on_actionClose_triggered()
{
    ui->userNamelineEdit->clear();
    ui->firstNamelineEdit->clear();
    ui->lastNamelineEdit->clear();
    ui->phonelineEdit->clear();
    ui->companyLineEdit->clear();
    ui->actionTCP->setEnabled(false);
    ui->actionHTTP->setEnabled(false);
    ui->createRadioButton->setEnabled(false);
    ui->updateRadioButton->setEnabled(false);
    ui->deleteRadioButton->setEnabled(false);
    ui->userNameLabel->setEnabled(false);
    ui->firstNameLabel->setEnabled(false);
    ui->lastNameLabel->setEnabled(false);
    ui->phoneLabel->setEnabled(false);
    ui->companyLabel->setEnabled(false);
    ui->userNamelineEdit->setEnabled(false);
    ui->firstNamelineEdit->setEnabled(false);
    ui->lastNamelineEdit->setEnabled(false);
    ui->phonelineEdit->setEnabled(false);
    ui->companyLineEdit->setEnabled(false);
    ui->commitPushButton->setEnabled(false);
    setActivePropertiesFalse();
}

void MainWindow::on_createRadioButton_toggled(bool checked)
{
    _propertiesSingleton.createRadioButtonToggled = checked;
}

void MainWindow::on_updateRadioButton_toggled(bool checked)
{
    _propertiesSingleton.updateRadioButtonToggled = checked;
}

void MainWindow::on_deleteRadioButton_toggled(bool checked)
{
    _propertiesSingleton.deleteRadioButtonToggled = checked;
}

void MainWindow::on_actionHTTP_toggled()
{
    _propertiesSingleton.actionTCPToggled = false;
    _propertiesSingleton.actionHTTPToggled = true;
}

void MainWindow::on_actionTCP_toggled()
{
    _propertiesSingleton.actionHTTPToggled = false;
    _propertiesSingleton.actionTCPToggled = true;
}

void MainWindow::on_commitPushButton_pressed()
{
    if(_propertiesSingleton.actionTCPToggled == false &&
            _propertiesSingleton.actionHTTPToggled == false)
    {
        QMessageBox::information(
            this,
            tr("Commit information"),
            tr("Commit failed. No Connection type chosen.") );
    }
    HTTPClient client;
    QMessageBox::information(
        this,
        tr("Commit information"),
        tr(client.postRequest("test info").c_str()) );
}
