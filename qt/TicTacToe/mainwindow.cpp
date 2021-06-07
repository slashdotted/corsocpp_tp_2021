#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msgdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_celle[0][0] = ui->cella_00;
    m_celle[0][1] = ui->cella_01;
    m_celle[0][2] = ui->cella_02;
    m_celle[1][0] = ui->cella_10;
    m_celle[1][1] = ui->cella_11;
    m_celle[1][2] = ui->cella_12;
    m_celle[2][0] = ui->cella_20;
    m_celle[2][1] = ui->cella_21;
    m_celle[2][2] = ui->cella_22;

    for(auto i{0}; i<3; ++i) {
        for(auto j{0}; j<3; ++j) {
            connect(m_celle[i][j], SIGNAL(clicked(bool)), this, SLOT(onCellClicked()));
        }
    }
    m_messaggio_stato = new QLabel{""};
    ui->statusBar->addWidget(m_messaggio_stato);
    aggiornaGiocatore();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fineTurno()
{
    /* Controlla vittoria */
    if (vittoria()) {
        for(auto i{0}; i<3; ++i) {
            for(auto j{0}; j<3; ++j) {
                m_celle[i][j]->setEnabled(false);
            }
        }
        MsgDialog m{m_giocatore+" ha vinto"};
        m.setVisible(true);
        m.exec();

    }

    m_turni++;
    /* Celle piene? */
    if (m_turni == 9) {
        MsgDialog m("Fine partita");
        m.setVisible(true);
        m.exec();
    }

    /* Passa al giocatore successivo */
    if (m_giocatore == "O") {
        m_giocatore = "X";
    } else {
        m_giocatore = "O";
    }

    aggiornaGiocatore();
}

void MainWindow::aggiornaGiocatore()
{
    m_messaggio_stato->setText("È il turno di "+ m_giocatore);
}

bool MainWindow::vittoria()
{
/*Controlla condizioni di vittoria*/
return (stato(0,0)==stato(0,1)&&stato(0,1)==stato(0,2)&&stato(0,2)!=""
||stato(1,0)==stato(1,1)&&stato(1,1)==stato(1,2)&&stato(1,2)!=""
||stato(2,0)==stato(2,1)&&stato(2,1)==stato(2,2)&&stato(2,2)!=""
||stato(0,0)==stato(1,0)&&stato(1,0)==stato(2,0)&&stato(2,0)!=""
||stato(0,1)==stato(1,1)&&stato(1,1)==stato(2,1)&&stato(2,1)!=""
||stato(0,2)==stato(1,2)&&stato(1,2)==stato(2,2)&&stato(2,2)!=""
||stato(0,0)==stato(1,1)&&stato(1,1)==stato(2,2)&&stato(2,2)!=""
||stato(2,0)==stato(1,1)&&stato(1,1)==stato(0,2)&&stato(0,2)!="");
}

QString MainWindow::stato(int riga, int colonna)
{
    return m_celle[riga][colonna]->property("stato").toString();
}


void MainWindow::onCellClicked()
{
    auto bottone{dynamic_cast<QPushButton*>(sender())};
    bottone->setProperty("stato", m_giocatore);
    QPixmap pixmap{":/immagini/"+m_giocatore.toLower()+".png"};
    QIcon icona{pixmap};
    bottone->setIcon(icona);
    bottone->setEnabled(false);
    fineTurno();
}



void MainWindow::on_actionNuova_triggered()
{
    for(auto i{0}; i<3; ++i) {
        for(auto j{0}; j<3; ++j) {
            m_celle[i][j]->setProperty("stato", QVariant::Invalid);
            m_celle[i][j]->setIcon(QIcon{});
            m_celle[i][j]->setEnabled(true);
        }
    }
    m_giocatore = "O";
    m_turni=0;
    aggiornaGiocatore();
}

