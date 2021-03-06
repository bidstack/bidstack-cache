# bidstack-cache

Easy to use cache library written in Qt/C++

## Usage

```c++
#include <QCoreApplication>
#include <QDebug>

#include "sqlitecacheadapter.hpp"

using namespace Bidstack::Cache;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    SqliteCacheAdapter *cache = new SqliteCacheAdapter("cache.sqlite");

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

    cache->store("key_c", "a special value", 1);

    qDebug() << "Has 'key_c' before sleep? -" << (cache->has("key_c") ? "yes" : "no");

    sleep(2);

    qDebug() << "Has 'key_c' after sleep? -" << (cache->has("key_c") ? "yes" : "no");

    return 0;
}
```
