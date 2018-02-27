#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QmessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Close");
    ui->pushButton_2->setText("About")
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 QMessageBox::information(this,"XD","Thank you!");
 close();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
  QString wholenumber = ("0"); // String for whole number output of our sensor value
  QString in = QString::number(value); // Converts slider bar to string to display in line text
  int wbcalc = (value/50*15+735); // Calculation to convert a 0-5V input to the sensor output and stay within a 16 bit integer
  QString wbCalcStr = QString::number(wbcalc); // Converts calculation to string to parse
  QString deci = wbCalcStr.right(2); // Pulls the last 2 characters of the string for our decimal place data

  // checks the calculated sensor value so we can decide how far from the left we need to parse the string
  // could have also checked the length of the string for validation
  if (wbcalc > 999){
      wholenumber = wbCalcStr.left(2);
  }
  else if (wbcalc < 999 || wbcalc > 99){
      wholenumber = wbCalcStr.left(1);
  }
  else {
      wholenumber = ("0");
  }


  ui->line->setText(in); // prints analog input to text line
  QString toast = QString::number(wbcalc);
  ui->wbmathint->setText(toast); // prints the calculated sensor value integer to text line
  ui->wbDecimal->setText(wholenumber + "." + deci); //
}


void MainWindow::on_pushButton_2_clicked()
{
  QMessageBox::information(this,"About","This is a quick example in order to demonstrate how to convert 0-5v analog input counts into sensor data with decimals without using float or double. This was a thought experiment in order to speed up the amount of cycles per second an arduino can print an analog input.")
}
