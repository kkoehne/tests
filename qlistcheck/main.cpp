#include <QUrl>
#include <QMetaType>
#include <QTypeInfo>

template <typename T>
struct Tester {
    struct MemoryLayout
        : QtPrivate::if_<
            QTypeInfo<T>::isStatic || QTypeInfo<T>::isLarge,
            QListData::IndirectLayout,
            typename QtPrivate::if_<
                sizeof(T) == sizeof(void*),
                QListData::ArrayCompatibleLayout,
                QListData::InlineWithPaddingLayout
             >::type>::type {};

    static bool heapAlloc () { MemoryLayout t; return heapAlloc(t); }
    static bool heapAlloc(QListData::ArrayCompatibleLayout) { return false; }
    static bool heapAlloc(QListData::InlineWithPaddingLayout) { return false; }
    static bool heapAlloc(QListData::IndirectLayout) { return true; }
};

#define STR(x)   #x
#define CHECKTYPE(T) \
    qDebug("QList<%s> uses %s allocation, and %s when reallocating", STR(T), \
    Tester<T>::heapAlloc() ? "indirect" : "inline", \
    QTypeInfo<T>::isComplex ? "constructs/destructs" : "memcpy'ies");

struct X{
    long a;
    long b;
};

int main(int argc, char *argv[])
{
    CHECKTYPE(QUrl);
    CHECKTYPE(QUrl*);
    CHECKTYPE(X);
}

