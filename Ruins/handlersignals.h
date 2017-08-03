#ifndef HANDLERSIGNALS_H
#define HANDLERSIGNALS_H

#include <QObject>
#include <QVariant>
#include <QDebug>
#include <cstdlib>
#include <time.h>

class HandlerSignals : public QObject
{
    Q_OBJECT
public:
    explicit HandlerSignals(QObject *parent = 0);

signals:

public slots:
    void changeField(const QString &msg, const QString &pos);
    void generation();

private:
    int field [32][18];
};

#endif // HANDLERSIGNALS_H
