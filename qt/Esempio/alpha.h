#ifndef ALPHA_H
#define ALPHA_H

#include <QObject>

class Alpha : public QObject
{
    Q_OBJECT
public:
    explicit Alpha(const QString& nome, QObject *parent = nullptr);
    virtual ~Alpha() noexcept;

signals:


public slots:

};

#endif // ALPHA_H
