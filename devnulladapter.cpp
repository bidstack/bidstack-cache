#include "devnulladapter.hpp"

using namespace Bidstack::Cache;

DevNullAdapter::DevNullAdapter(QObject *parent) : AbstractAdapter(parent) {

}

bool DevNullAdapter::store(QString key, QString data) {
    return store(key, data, 0);
}

bool DevNullAdapter::store(QString key, QString data, int ttl) {
    Q_UNUSED(key);
    Q_UNUSED(data);
    Q_UNUSED(ttl);
    return true;
}

bool DevNullAdapter::has(QString key) {
    Q_UNUSED(key);
    return false;
}

bool DevNullAdapter::remove(QString key) {
    Q_UNUSED(key);
    return true;
}

bool DevNullAdapter::clear() {
    return true;
}

QString DevNullAdapter::fetch(QString key) {
    Q_UNUSED(key);
    return "";
}

QString DevNullAdapter::fetch(QString key, QString defaultValue) {
    Q_UNUSED(key);
    Q_UNUSED(defaultValue);
    return defaultValue;
}
