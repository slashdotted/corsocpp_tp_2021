#include "msgdialog.h"
#include "ui_msgdialog.h"

MsgDialog::MsgDialog(const QString& messaggio, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MsgDialog)
{
    ui->setupUi(this);
    ui->messaggio->setText(messaggio);
    connect(ui->bottoneOk, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MsgDialog::~MsgDialog()
{
    delete ui;
}
