#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_startButon_clicked();

    void on_basicButton_clicked();

    void on_targetButton_clicked();

    void on_scriptButton_clicked();

    void on_outputButton_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    QString basicPakcageName;
    QString targetPakcageName;
    QString scriptFileName;
    QString outputPackageName;
};

#endif // MAINWINDOW_H
