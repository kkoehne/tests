#include <QString>
#include <QtTest>
#include <QThreadStorage>


class ThreadStorageBenchmark: public QObject
{
    Q_OBJECT

public:
private Q_SLOTS:
    void no_check();
    void thread_local_();
    void threadStorage();

private:
    volatile int i;
};

void ThreadStorageBenchmark::no_check()
{
    QBENCHMARK {
        i++;
    }
}


#if defined(Q_COMPILER_THREAD_LOCAL)
# define Q_DECL_THREAD_LOCAL thread_local
#elif defined(Q_CC_GNU)
# define Q_DECL_THREAD_LOCAL __thread
#else
Q_STATIC_ASSERT_X(0, "thread_storage not supported")
#endif

void ThreadStorageBenchmark::thread_local_()
{
    QBENCHMARK {
        Q_DECL_THREAD_LOCAL static int lock = 0;

        if (lock++ > 0)
            return;

        i++;

        --lock;
    }
}

void ThreadStorageBenchmark::threadStorage()
{
    QBENCHMARK {
        QThreadStorage<int> store;
        if (store.localData())
            return;
        store.setLocalData(1);

        i++;

        store.setLocalData(0);
    }
}


QTEST_APPLESS_MAIN(ThreadStorageBenchmark)

#include "tst_threadstoragebench.moc"
