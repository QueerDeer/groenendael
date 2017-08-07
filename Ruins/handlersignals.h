#ifndef HANDLERSIGNALS_H
#define HANDLERSIGNALS_H

#include <QObject>
#include <QVariant>
#include <QDebug>
#include <cstdlib>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class HandlerSignals : public QObject
{
    Q_OBJECT
public:
    explicit HandlerSignals(QObject *parent = 0);

signals:

public slots:
    void changeField(const QString &msg, const QString &pos);
    void generation();
    void engine();
    void createSoldier(const QString &pos);

private:
    int field [32][18];

};

#endif // HANDLERSIGNALS_H
