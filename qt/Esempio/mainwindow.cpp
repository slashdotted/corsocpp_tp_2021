#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alpha.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->mioBottone->setText("Ciao mondo");

    // Accesso al widget tramite campo della classe ui::MainWindow
    auto btn = ui->mioBottone;
    // Accesso al widget tramite relazione "padre figlio"
    auto btn2 = ui->centralwidget->findChild<QPushButton*>("mioBottone");
    btn2->setText("Prova");
    // Riassegnamento del parent
    btn->setParent(ui->widget);
    btn->show();

    new Alpha{"uno", this};

    // std::string non riconosce unicode
    std::string msg{"Oggi è bello"};
    qDebug() << msg.size();
    // QString riconosce unicode
    QString msg2{"Oggi è bello"};
    qDebug() << msg2.size();


    ui->attenzione->setVisible(false);

    // Collegamento segnali slot
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(onValoreCambiato(int)));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(onResetCliccato()));

    // Gli slot posso essere usati come metodi "normali"
    onResetCliccato();
}

MainWindow::~MainWindow()
{
    auto uno = this->findChild<Alpha*>("uno");
    delete ui;
}

void MainWindow::onValoreCambiato(int valore)
{
    ui->attenzione->setVisible(valore > 50);
}

void MainWindow::onResetCliccato()
{
    // Con sender posso recuperare l'origine del segnale
    auto btn = dynamic_cast<QPushButton*>(sender());
    ui->dial->setValue(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->dial->setValue(100);
}

