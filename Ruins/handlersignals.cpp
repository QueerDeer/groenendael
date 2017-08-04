#include "handlersignals.h"

int field [32][18];

HandlerSignals::HandlerSignals(QObject *parent) : QObject(parent)
{

}

void HandlerSignals::changeField(const QString &msg, const QString &pos) {
    //спавн то сейчас изобразится, но надо бы предварительный чек на то, не занято ли место, да и создать обьект солдата надо
    qDebug() << msg;
    QObject* mmm = this->parent()->findChild<QObject*>("mmm");
    QMetaObject::invokeMethod(mmm, "changecolor", Q_ARG(QVariant, pos), Q_ARG(QVariant, msg));
}

void HandlerSignals::createSoldier(const QString &pos) {
    //спавн то сейчас изобразится, но надо бы предварительный чек на то, не занято ли место, да и создать обьект солдата надо
    qDebug() << pos;
    QObject* mmm = this->parent()->findChild<QObject*>("mmm");
    QMetaObject::invokeMethod(mmm, "createsoldier", Q_ARG(QVariant, pos));
}

void HandlerSignals::engine() {

}

void HandlerSignals::generation() {
    //deleteAllSoldiers();

    srand (time(NULL));

    for (auto i = 0; i < 32; ++i)
    {
        for (auto j = 0; j < 18; ++j)
        {
            if (!(rand() % 5))
            {
                int pixcolor = rand() % 2; //0 - пустота, 1 - кирпич
                field[i][j] = (pixcolor + (rand() % 2)) * pixcolor; //0 - пустота, 1 - кирпич, 2 - трава
            }
            else field[i][j] = field[i-1][j];
        }
    }

    for (auto k = 0; k < 32; ++k)
    {
        if (!(rand() % 3))
            for (auto l = 0; l < 18; ++l)
            {
                field[k][l] = 0;
            }
    }

    for (auto m = 0; m < 32; ++m)
        for (auto n = 0; n < 18; ++n)
        {
            if (field[m][n] == 0)
                changeField("#FFCC80", QString::number(m*18 + n));
            if (field[m][n] == 1)
                changeField("firebrick", QString::number(m*18 + n));
            if (field[m][n] == 2)
                changeField("darkolivegreen", QString::number(m*18 + n));
        }
}
