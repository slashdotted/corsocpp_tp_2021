#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alpha.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onValoreCambiato(int);
    void onResetCliccato();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Alpha m_a{"due"};
};
#endif // MAINWINDOW_H
