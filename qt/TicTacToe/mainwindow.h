#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    // Ritorna lo stato della cella: "" (vuota), "O", "X"
    QString stato(int riga, int colonna);

    // Ritorna vero se le condizioni di vittoria sono soddisfatte
    bool vittoria();

    // Segnala la fine del turno
    void fineTurno();

    // Aggiorna la barra di stato
    void aggiornaGiocatore();

    // Array con puntatori ai widget dell'interfaccia grafica
    QPushButton* m_celle[3][3];

    // Puntatore alla classe "duale"
    Ui::MainWindow *ui;

    // Giocatore corrente
    QString m_giocatore{"O"};

    // Turno corrente
    int m_turni{0};

    // Etichetta della barra di stato
    QLabel* m_messaggio_stato;

private slots:
    // Click su cella
    void onCellClicked();

    // Gestore nuova partita
    void on_actionNuova_triggered();
};

#endif // MAINWINDOW_H
