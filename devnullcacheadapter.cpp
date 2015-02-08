#include "devnullcacheadapter.hpp"

using namespace Bidstack::Cache;

DevNullCacheAdapter::DevNullCacheAdapter(QObject *parent) : AbstractCacheAdapter(parent) {

}

bool DevNullCacheAdapter::store(QString key, QString data) {
    return store(key, data, 0);
}

bool DevNullCacheAdapter::store(QString key, QString data, int ttl) {
    Q_UNUSED(key);
    Q_UNUSED(data);
    Q_UNUSED(ttl);
    return true;
}

bool DevNullCacheAdapter::has(QString key) {
    Q_UNUSED(key);
    return false;
}

bool DevNullCacheAdapter::remove(QString key) {
    Q_UNUSED(key);
    return true;
}

bool DevNullCacheAdapter::clear() {
    return true;
}

QString DevNullCacheAdapter::fetch(QString key) {
    Q_UNUSED(key);
    return "";
}

QString DevNullCacheAdapter::fetch(QString key, QString defaultValue) {
    Q_UNUSED(key);
    Q_UNUSED(defaultValue);
    return defaultValue;
}
