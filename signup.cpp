#include "signup.h"
#include "ui_signup.h"
#include <QDebug>
#include "finger.h"


Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);




    ui->stackedWidget->setCurrentWidget(ui->signup1);
    {//error label set invisible as default 
        ui->label_pass_err1->setVisible(false);
        ui->label_pass_err2->setVisible(false);
        ui->label_pass_err3->setVisible(false);
    }

    connect(findChild<QLineEdit*>("lineEdit_email"),&QLineEdit::textChanged,this,&Signup::isEmailValid);
    connect(findChild<QLineEdit*>("lineEdit_password"),&QLineEdit::textChanged,this,&Signup::isPasswordConditionValid);
    connect(findChild<QLineEdit*>("lineEdit_confirmpass"),&QLineEdit::textChanged,this,&Signup::isPasswordConfirmValid);

    
}

Signup::~Signup()
{
    delete ui;
}

//the push button on first page of the stackedwidget
void Signup::on_pushButton_clicked()
{
    if(isEmailValid(findChild<QLineEdit*>("lineEdit_email")->text())==true)
    {
        ui->stackedWidget->setCurrentWidget(ui->signup2);
        usertmp.set_email(ui->lineEdit_email->text());
    }


}

//the push button on second page of the stackedwidget
void Signup::on_pushButton_next_clicked()
{
    cout<<"URG "<<usertmp.get_email().toStdString()<<endl;
    usertmp.set_username(ui->lineEdit_username->text());
    if(isPasswordConfirmValid() && isPasswordConditionValid() )
    {
        
        try
        {

            if(usertmp.get_username() == "")
                 throw "Username can't be empty";
        }
        catch(const char* msg)
        {
            
            

            QMessageBox::critical(nullptr,"Error",msg);
            return;
        }

        usertmp.set_password(ui->lineEdit_password->text());
        
        ui->stackedWidget->setCurrentWidget(ui->signup3);
    }
    else
    {

            ui->pushButton_next->setStyleSheet("QPushButton{\
                        color: rgb(204, 170, 103);\
                        	background-color: rgb(17, 17, 17);\
                        border: 1px solid black;\
                        border-bottom-color: rgb(255 ,0 , 0);\
                        border-top-color: rgb(255 ,0 , 0);\
                        border-right-color: rgb(255 ,0 , 0);\
                        border-left-color: rgb(255 ,0 , 0);\
                        }QPushButton:hover{\
                        	color: rgb(255, 234, 183);\
                        	background-color: rgb(17, 17, 17);\
                        border: 1px solid black;\
                        border-bottom-color: rgb(255, 0, 0);\
                        border-top-color: rgb(255, 0, 0);\
                        border-right-color: rgb(255, 0, 0);\
                        border-left-color: rgb(255, 0, 0);\
                        }");



    }
    
}


bool Signup::isEmailValid(QString email) {
    // Regular expression pattern for email validation
    QRegularExpression emailPattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    
    
    if(emailPattern.match(email).hasMatch())
    {
        ui->lineEdit_email->setStyleSheet("QLineEdit {\
            background-color: rgba(0, 0, 0, 0);\
 	        border: 2px solid black;\
            border-bottom-color: rgb(204, 170, 103);\
	        border-top-color: rgba(0, 0, 0, 0);\
            border-right-color: rgba(0, 0, 0, 0);\
            border-left-color: rgba(0, 0, 0, 0);\
	        color: rgb(255, 255, 255);\
        }");


        return true;


        
    }
    else
    {
        ui->lineEdit_email->setStyleSheet("QLineEdit {\
                background-color: rgba(0, 0, 0, 0);\
 	            border: 2px solid black;\
                border-bottom-color: rgb(255, 0, 0);\
	            border-top-color: rgba(0, 0, 0, 0);\
                border-right-color: rgba(0, 0, 0, 0);\
                border-left-color: rgba(0, 0, 0, 0);\
	            color: rgb(255, 255, 255);\
        }");
        return false;

    }
}

bool Signup::isPasswordConditionValid()
{
    QRegularExpression passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%*?&#]{8,}$");
    if(passwordPattern.match(findChild<QLineEdit*>("lineEdit_password")->text()).hasMatch())
    {
        ui->lineEdit_password->setStyleSheet("QLineEdit {\
            background-color: rgba(0, 0, 0, 0);\
            border: 2px solid black;\
            border-bottom-color: rgb(204, 170, 103);\
            border-top-color: rgba(0, 0, 0, 0);\
            border-right-color: rgba(0, 0, 0, 0);\
            border-left-color: rgba(0, 0, 0, 0);\
            color: rgb(255, 255, 255);\
        }");

        ui->label_pass_err1->setVisible(false);
        ui->label_pass_err2->setVisible(false);
        
        ui->lineEdit_confirmpass->move(ui->lineEdit_confirmpass->x() , 240);
        ui->pushButton_next->move(ui->pushButton_next->x() , 311);
        ui->groupBox_step123->move(ui->groupBox_step123->x() , 330);
        ui->label_pass_err3->move(ui->label_pass_err3->x() , ui->lineEdit_confirmpass->y()+40);


        return true;
    }
    else
    {
        ui->lineEdit_password->setStyleSheet("QLineEdit {\
                background-color: rgba(0, 0, 0, 0);\
 	            border: 2px solid black;\
                border-bottom-color: rgb(255, 0, 0);\
	            border-top-color: rgba(0, 0, 0, 0);\
                border-right-color: rgba(0, 0, 0, 0);\
                border-left-color: rgba(0, 0, 0, 0);\
	            color: rgb(255, 255, 255);\
        }");
        ui->label_pass_err1->setVisible(true);
        ui->label_pass_err2->setVisible(true);

        ui->lineEdit_confirmpass->move(ui->lineEdit_confirmpass->x() , 270);
        ui->pushButton_next->move(ui->pushButton_next->x() , 341);
        ui->groupBox_step123->move(ui->groupBox_step123->x() , 360);
        ui->label_pass_err3->move(ui->label_pass_err3->x() , ui->lineEdit_confirmpass->y()+40);

        return false;
    }

}


bool Signup::isPasswordConfirmValid()
{
    QRegularExpression passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%*?&#]{8,}$");

    if(ui->lineEdit_confirmpass->text() == ui->lineEdit_password->text())
    {
        ui->lineEdit_confirmpass->setStyleSheet("QLineEdit {\
            background-color: rgba(0, 0, 0, 0);\
            border: 2px solid black;\
            border-bottom-color: rgb(204, 170, 103);\
            border-top-color: rgba(0, 0, 0, 0);\
            border-right-color: rgba(0, 0, 0, 0);\
            border-left-color: rgba(0, 0, 0, 0);\
            color: rgb(255, 255, 255);\
        }");

        ui->label_pass_err3->setVisible(false);
        ui->label_pass_err3->move(ui->label_pass_err3->x() , ui->lineEdit_confirmpass->y()+40);
        


        return true;
    }
    else
    {
        ui->lineEdit_confirmpass->setStyleSheet("QLineEdit {\
                background-color: rgba(0, 0, 0, 0);\
 	            border: 2px solid black;\
                border-bottom-color: rgb(255, 0, 0);\
	            border-top-color: rgba(0, 0, 0, 0);\
                border-right-color: rgba(0, 0, 0, 0);\
                border-left-color: rgba(0, 0, 0, 0);\
	            color: rgb(255, 255, 255);\
        }");
        ui->label_pass_err3->setVisible(true);
        
        ui->label_pass_err3->move(ui->label_pass_err3->x() , ui->lineEdit_confirmpass->y()+40);
        
        return false;
    }

}





void Signup::on_pushButton_signup_clicked()
{
    usertmp.set_id_user(ui->lineEdit_cin->text());
    usertmp.set_cin(ui->lineEdit_cin->text());
    usertmp.set_nom(ui->lineEdit_nom->text());
    usertmp.set_prenom(ui->lineEdit_prenom->text());
    usertmp.set_telephone(ui->lineEdit_tel->text());
    usertmp.set_date_naiss(ui->date_naissance->date());
    usertmp.set_sexe(ui->comboBox_sexe->currentText());
    emptmp.set_status(ui->comboBox_status->currentText());
    usertmp.set_role("User");

    /*try{
        if(emptmp.get_cin()=="")
            throw "Cin can't be empty";
        if(emptmp.get_cin()=="")
            throw "Cin can't be empty";
        
    }*/


    



    bool test= usertmp.ajouter_user();

            if (test )
            {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                                         QObject::tr("SignUp effectué.\nClick Cancel to exit."), QMessageBox::Cancel);

                    Finger f(usertmp);
                    f.setModal(true);
                    f.show();
                    f.exec();
                this->close();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                       QObject::tr("SignUp non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);

            }


   
}
