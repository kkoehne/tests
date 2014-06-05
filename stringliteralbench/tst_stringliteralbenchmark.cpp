#include <QString>
#include <QtTest>

class StringLiteralBenchmark : public QObject
{
    Q_OBJECT

public:
    StringLiteralBenchmark();

private Q_SLOTS:
    void stringBuilder1();
    void stringBuilder2();
};

StringLiteralBenchmark::StringLiteralBenchmark()
{
}

void StringLiteralBenchmark::stringBuilder1()
{
    const QString world = QLatin1String("world");
    QBENCHMARK {
        QString str = QLatin1String("Hello ") + world;
    }
}

void StringLiteralBenchmark::stringBuilder2()
{
    const QString world = QLatin1String("world");
    QBENCHMARK {
        QString str = QStringLiteral("Hello ") + world;
    }
}

QTEST_APPLESS_MAIN(StringLiteralBenchmark)

#include "tst_stringliteralbenchmark.moc"
