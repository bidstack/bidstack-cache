# bidstack-cache

Easy to use cache library written in Qt/C++

## Usage

```c++
#include <QCoreApplication>
#include <QDebug>

#include "sqliteadapter.hpp"

using namespace Bidstack;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Cache::SqliteAdapter *cache = new Cache::SqliteAdapter("cache.sqlite");

    qDebug() << "Has 'key_a'? -" << (cache->has("key_a") ? "yes" : "no");
    qDebug() << "Has 'key_b'? -" << (cache->has("key_b") ? "yes" : "no");

    cache->store("key_a", "Hello World");
    cache->store("key_b", "Hello Universe");

    qDebug() << "Has 'key_a'? -" << (cache->has("key_a") ? "yes" : "no");
    qDebug() << "Has 'key_b'? -" << (cache->has("key_b") ? "yes" : "no");

    qDebug() << "Value for 'key_a':" << cache->fetch("key_a");
    qDebug() << "Value for 'key_b':" << cache->fetch("key_b");

    cache->remove("key_a");

    qDebug() << "Has 'key_a'? -" << (cache->has("key_a") ? "yes" : "no");
    qDebug() << "Has 'key_b'? -" << (cache->has("key_b") ? "yes" : "no");

    qDebug() << "Value for 'key_a':" << cache->fetch("key_a", "default value for 'key_a'");
    qDebug() << "Value for 'key_b':" << cache->fetch("key_b", "default value for 'key_b'");

    cache->clear();

    qDebug() << "Has 'key_a'? -" << (cache->has("key_a") ? "yes" : "no");
    qDebug() << "Has 'key_b'? -" << (cache->has("key_b") ? "yes" : "no");

    qDebug() << "Value for 'key_a':" << cache->fetch("key_a");
    qDebug() << "Value for 'key_b':" << cache->fetch("key_b");

    return 0;
}
```
