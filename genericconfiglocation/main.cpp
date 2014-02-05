#include <QCoreApplication>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << "QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation):";
    qDebug() << QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation);
}
