#include <QApplication>
#include <QDebug>
#include <QPlainTextEdit>

static QPlainTextEdit *edit = 0;

const char literal[] = "Россия - самая большая страна в мире.";

QtMessageHandler oldMessageHandler;
void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message)
{
    if (edit)
        edit->appendPlainText(message);
    if (oldMessageHandler)
        (*oldMessageHandler)(type, context, message);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    oldMessageHandler = qInstallMessageHandler(myMessageHandler);

    QString string = QString::fromUtf8(literal);

    edit = new QPlainTextEdit;
    qDebug() << "QDebug - Stream Operator";
    qDebug() << "literal:" << literal;
    qDebug() << "QString:" << string;
    qDebug() << "toLocal8Bit:" << string.toLocal8Bit().constData();
    qDebug() << "toUtf8:" << string.toUtf8().constData();

    qDebug("QDebug - printf style");
    qDebug("literal: %s", literal);
    qDebug("toLocal8Bit: %s", string.toLocal8Bit().constData());
    qDebug("toUtf8: %s", string.toUtf8().constData());

    printf("%s\n", "printf");
    printf("literal: %s\n", literal);
    printf("toLocal8Bit: %s\n", string.toLocal8Bit().constData());
    printf("toUtf8: %s\n", string.toUtf8().constData());

    edit->show();
    app.exec();
}
