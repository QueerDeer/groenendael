#include "handlersignals.h"

int field [32][18];

HandlerSignals::HandlerSignals(QObject *parent) : QObject(parent)
{

}

void HandlerSignals::changeField(const QString &msg, const QString &pos) {
    qDebug() << msg;
    QObject* mmm = this->parent()->findChild<QObject*>("mmm");
    QMetaObject::invokeMethod(mmm, "changecolor", Q_ARG(QVariant, pos), Q_ARG(QVariant, msg));
}

void HandlerSignals::createSoldier(const QString &pos) {
    if (field[pos.toInt() / 18][pos.toInt() % 18] != 1)
    {
        qDebug() << pos;
        if (pos < 288)
        {
            sorc1.append(sorcIDMaker);
            QObject* mmm = this->parent()->findChild<QObject*>("mmm");
            QMetaObject::invokeMethod(mmm, "createsoldier", Q_ARG(QVariant, pos), Q_ARG(QVariant, "f"+ QString::number(sorcIDMaker)));
            sorcIDMaker++;
        }
        else
        {
            sorc2.append(sorcIDMaker);
            QObject* mmm = this->parent()->findChild<QObject*>("mmm");
            QMetaObject::invokeMethod(mmm, "createsoldier", Q_ARG(QVariant, pos), Q_ARG(QVariant, "f" + QString::number(sorcIDMaker)));
            sorcIDMaker++;
        }
    }
}

void HandlerSignals::engine() {

}

void HandlerSignals::generation() {

    //deleteAllSoldiers();
    for (int s1 = 0; s1 < sorc1.size(); ++s1) {
        QObject* sold1 = this->parent()->findChild<QObject*>("f" + QString::number(sorc1.at(s1)));
        QMetaObject::invokeMethod(sold1, "hello");
    }
    for (int s2 = 0; s2 < sorc2.size(); ++s2) {
        QObject* sold2 = this->parent()->findChild<QObject*>("f" + QString::number(sorc2.at(s2)));
        QMetaObject::invokeMethod(sold2, "hello");
    }
    sorc1.clear();
    sorc2.clear();

    for (auto i = 0; i < 32; i+=2)
    {
        for (auto j = 0; j < 18; j+=2)
        {
            if (rand() % 4)
            {
                int pixcolor = rand() % 2; //0 - пустота, 1 - кирпич
                int doublepixcolor = (pixcolor + (rand() % 2)) * pixcolor; //0 - пустота, 1 - кирпич, 2 - трава
                field[i][j] = doublepixcolor;
                field[i][j+1] = doublepixcolor;
                field[i+1][j] = doublepixcolor;
                field[i+1][j+1] = doublepixcolor;
            }
            else
            {
                field[i][j] = field[i-1][j];
                field[i+1][j] = field[i-1][j];
                field[i][j+1] = field[i-1][j+1];
                field[i+1][j+1] = field[i-1][j+1];
            }
        }
    }

    for (auto m = 0; m < 32; ++m)
        for (auto n = 0; n < 18; ++n)
        {
            if (field[m][n] == 0)
                changeField("road1", QString::number(m*18 + n));

            if (field[m][n] == 1)
                changeField("firebrick5", QString::number(m*18 + n));

            if (field[m][n] == 1 && field[m-1][n] != 1)
                changeField("firebrick2", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m+1][n] != 1)
                changeField("firebrick8", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m][n-1] != 1)
                changeField("firebrick4", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m][n+1] != 1)
                changeField("firebrick6", QString::number(m*18 + n));

            if (field[m][n] == 1 && field[m-1][n] != 1 && field[m][n-1] != 1)
                changeField("firebrick1", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m+1][n] != 1 && field[m][n+1] != 1)
                changeField("firebrick9", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m][n-1] != 1 && field[m+1][n] != 1)
                changeField("firebrick7", QString::number(m*18 + n));
            if (field[m][n] == 1 && field[m][n+1] != 1 && field[m-1][n] != 1)
                changeField("firebrick3", QString::number(m*18 + n));

            if (field[m][n] == 2)
                changeField("darkolivegreen5", QString::number(m*18 + n));

            if (field[m][n] == 2 && field[m-1][n] != 2)
                changeField("darkolivegreen8", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m+1][n] != 2)
                changeField("darkolivegreen2", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m][n-1] != 2)
                changeField("darkolivegreen6", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m][n+1] != 2)
                changeField("darkolivegreen4", QString::number(m*18 + n));

            if (field[m][n] == 2 && field[m-1][n] != 2 && field[m][n-1] != 2)
                changeField("darkolivegreen9", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m+1][n] != 2 && field[m][n+1] != 2)
                changeField("darkolivegreen1", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m][n-1] != 2 && field[m+1][n] != 2)
                changeField("darkolivegreen3", QString::number(m*18 + n));
            if (field[m][n] == 2 && field[m][n+1] != 2 && field[m-1][n] != 2)
                changeField("darkolivegreen7", QString::number(m*18 + n));
        }
}
