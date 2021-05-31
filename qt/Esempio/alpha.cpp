#include "alpha.h"
#include <QDebug>

Alpha::Alpha(const QString &nome, QObject *parent) : QObject(parent)
{
    setObjectName(nome);
    qDebug() << "Construzione di Alpha" << this << objectName();
}

Alpha::~Alpha() noexcept
{
    qDebug() << "Distruzione di Alpha" << this << objectName();
}
