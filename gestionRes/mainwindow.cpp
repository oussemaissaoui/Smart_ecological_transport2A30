#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateEdit>
#include <QTabWidget>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
int id_c=ui->numres->text().toInt();
}
