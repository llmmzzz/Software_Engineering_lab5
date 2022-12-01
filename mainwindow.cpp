#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QString>

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


void MainWindow::on_pushButton_clicked()
{
    int flag=-1;
    int count= StringVector1.size();
    qDebug()<<count;
    for(int i=0;i<count;i++)
    {
        if(filename1==StringVector1[i]&&filename2==StringVector2[i])
        {
            flag=i;
            break;
        }
    }
    qDebug()<<flag;
    qDebug()<<StringVector1[flag];
    qDebug()<<StringVector2[flag];
    StringVector1.erase(StringVector1.begin()+flag);
    StringVector2.erase(StringVector2.begin()+flag);
    count = StringVector1.size();
    qDebug()<<count;
}


void MainWindow::on_pushButton_4_clicked()
{
    int count = StringVector1.size();
    int flag1=-1;
    int flag2=-1;

    if(count==0)
    {
        return;
    }
    for(int i=0;i<count;i++)
    {
        if(StringVector1[i]==filename1)
        {
            flag1=i;
            break;
        }
    }


    for(int i=0;i<count;i++)
    {
        if(StringVector2[i]==filename2)
        {
            flag2=i;
            break;
        }
    }

    if(flag1==-1&&flag2==-1)
    {
        filename1=StringVector1[0];
        filename2=StringVector2[0];
    }
    else if(flag1!=-1&&flag2==-1)
    {
        filename1=StringVector1[flag1];
        filename2=StringVector2[flag1];
    }
    else if(flag1==-1&&flag2!=-1)
    {
        filename1=StringVector1[flag2];
        filename2=StringVector2[flag2];
    }
    else if(flag1!=-1&&flag2!=-1)
    {
        filename1=StringVector1[flag1];
        filename2=StringVector2[flag1];
    }
    qDebug()<<flag1;
    qDebug()<<flag2;
    qDebug()<<StringVector1[0];
    qDebug()<<StringVector2[0];

    qDebug()<<filename1;
    qDebug()<<filename2;
    ui->lineEdit->setText(filename1);
    ui->lineEdit_2->setText(filename2);


    QString path1 = "D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/"+filename1;

    QString path2 = "D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/"+filename2;

    QFile file1(path1);
    if(file1.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }

    file1.open(QIODevice::ReadOnly);
    QByteArray array1;
    while(!file1.atEnd())
    {
        array1+=file1.readLine();
    }
    ui->textEdit->setText(array1);
    file1.close();

    QFile file2(path2);
    if(file2.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }
    file2.open(QIODevice::ReadOnly);
    QByteArray array2;
    while(!file2.atEnd())
    {
        array2+=file2.readLine();
    }
    ui->textEdit_2->setText(array2);
    file2.close();

}


void MainWindow::on_pushButton_2_clicked()
{
    int flag=-1;
    int count= StringVector1.size();
    qDebug()<<count;
    for(int i=0;i<count;i++)
    {
        if(filename1==StringVector1[i]&&filename2==StringVector2[i])
        {
            flag=i;
            break;
        }
    }
    StringVector1.erase(StringVector1.begin()+flag);
    StringVector2.erase(StringVector2.begin()+flag);

    QFile file_csv1("D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/inequal.csv");
    if(file_csv1.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }

    if(!file_csv1.open(QIODevice::Append|QIODevice::Text))
    {
        qDebug()<<"open failure";
        return;
    }
    QString str = filename1+","+filename2+"\n";
    file_csv1.write(str.toUtf8());
    file_csv1.close();

}



void MainWindow::on_pushButton_3_clicked()
{
    QFile file_csv("D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/equal.csv");
    if(file_csv.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }

    if(!file_csv.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open failure";
        return;
    }

    QStringList list;
    QTextStream in(&file_csv);

    /*QString fileLine = in.readLine();
    list = fileLine.split(",");
    int count = list.size();
    for(int j=0;j<count;j++)
    {
        StringVector.append(list.at(j));
    }*/


    for(int i=0;!in.atEnd();i++)
    {
        QString fileLine = in.readLine();
        list = fileLine.split(",");
        int count = list.size();
        StringVector1.append(list.at(0));
        StringVector2.append(list.at(1));
        list.clear();
    }
    filename1 = StringVector1[0];
    filename2 = StringVector2[0];
    ui->lineEdit->setText(filename1);
    ui->lineEdit_2->setText(filename2);

    QString path1 = "D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/"+filename1;

    QString path2 = "D:/QtProjects/SoftwareEngineerCode/SoftwareEngineer/"+filename2;

    QFile file1(path1);
    if(file1.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }

    file1.open(QIODevice::ReadOnly);
    QByteArray array1;
    while(!file1.atEnd())
    {
        array1+=file1.readLine();
    }
    ui->textEdit->setText(array1);
    file1.close();

    QFile file2(path2);
    if(file2.exists()){
           qDebug()<<"文件已存在";
       }else{
           qDebug()<<"文件不存在";
       }
    file2.open(QIODevice::ReadOnly);
    QByteArray array2;
    while(!file2.atEnd())
    {
        array2+=file2.readLine();
    }
    ui->textEdit_2->setText(array2);
    file2.close();

}

