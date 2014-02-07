#include <QString>
#include <QtTest>

class QcdebugvariantsbenchTest : public QObject
{
    Q_OBJECT

public:
    QcdebugvariantsbenchTest();

private Q_SLOTS:
    void forloop();
    void ifelse();

private:
    volatile int i;
};



QcdebugvariantsbenchTest::QcdebugvariantsbenchTest()
{

}

void QcdebugvariantsbenchTest::forloop()
{
    QLoggingCategory cat("Hi there");
    cat.setEnabled(QtDebugMsg, true);
    QBENCHMARK {
        for (bool enabled = cat.isDebugEnabled(); enabled; enabled = false)
            i = !i;
    }
}

void QcdebugvariantsbenchTest::ifelse()
{
    QLoggingCategory cat("Hi there");
    cat.setEnabled(QtDebugMsg, true);
    QBENCHMARK {
        if (!cat.isDebugEnabled()) {} else i = !i;
    }
}

QTEST_APPLESS_MAIN(QcdebugvariantsbenchTest)

#include "tst_qcdebugvariantsbenchtest.moc"
