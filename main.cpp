#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "rh.h"
#include <iostream>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "finger.h"


using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Connection c;
    bool test=c.createconnect();
    if(test)
    {Finger f;
    f.show();
    f.exec();}*/
    Connection c;
    bool test=c.createconnect();
    
    


   MainWindow w_login;


    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            return 0;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM LOGS");
    if(query.exec() && query.next())
    {
        int rowcount=query.value(0).toInt();
        if(rowcount !=0)
        {
            //w_login.set_login_status(true);
            w_login.set_login_status(true);
            emit w_login.login_status_changed();
            w_login.set_stackedwidget_page(1);

        }
        else
        {
            w_login.set_login_status(false);
            w_login.set_stackedwidget_page(0);

        }

    }
    else cout<<"erooororooror"<<endl;
    cout<<"test0"<<endl;

    w_login.show();
    a.exec();






    /*if(w_login.get_login_status())
    {
    rh w_rh;
    w_rh.show();
    a.exec();
    }*/









    cout<<"application exec"<<endl;
    return 0;
}
