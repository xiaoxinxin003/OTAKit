#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_basicButton_clicked()
{
    basicPakcageName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "",
                                                      tr("*.zip"));
    qDebug() << ("basicPackageName == " + basicPakcageName).toStdString().c_str();
}

void MainWindow::on_targetButton_clicked()
{
    targetPakcageName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "",
                                                      tr("*.zip"));
    qDebug() << ("targetPakcageName == " + targetPakcageName).toStdString().c_str();
}

void MainWindow::on_scriptButton_clicked()
{
    scriptFileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "",
                                                      tr("*.sh"));
    qDebug() << ("scriptFileName == " + scriptFileName).toStdString().c_str();
}

void MainWindow::on_outputButton_clicked()
{
    outputPackageName = QFileDialog::getSaveFileName(this, tr("Save File Dir"),
                                                      "",
                                                      tr("*.zip"));
    qDebug() << ("outputPackageName == " + outputPackageName).toStdString().c_str();
}

void MainWindow::on_startButon_clicked()
{
    QString cmd = (scriptFileName + " -i " + basicPakcageName + " " + targetPakcageName + " " + outputPackageName).toStdString().c_str();
//    process->startDetached(cmd);
    process->start("git log", QStringList() << "E:\\code\files");
    QByteArray output = process->readAllStandardOutput();

    QString str_output = output;
    ui->textEdit->setText(str_output);
    process->waitForFinished();
    process->close();
}


