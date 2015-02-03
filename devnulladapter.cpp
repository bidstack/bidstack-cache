#include "devnulladapter.hpp"

using namespace Bidstack::Cache;

DevNullAdapter::DevNullAdapter(QObject *parent) : AbstractAdapter(parent) {

}

bool DevNullAdapter::store(QString key, QString data) {
    Q_UNUSED(key);
    Q_UNUSED(data);
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
