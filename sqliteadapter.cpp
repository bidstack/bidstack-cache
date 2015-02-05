#include "sqliteadapter.hpp"

#include <QDateTime>

using namespace Bidstack::Cache;

SqliteAdapter::SqliteAdapter(QString filename, QObject *parent) : AbstractAdapter(parent) {
    if (!init(filename)) {
      throw "Could not initialize database connection!";
    }
}

bool SqliteAdapter::init(QString filename) {
    m_connection = QSqlDatabase::addDatabase("QSQLITE", "bidstack-cache");
    m_connection.setDatabaseName(filename);

    if (!m_connection.isValid() || !m_connection.open()) {
        return false;
    }

    const QString sql =
        "CREATE TABLE IF NOT EXISTS cache ("
            "key CHAR(32) PRIMARY KEY NOT NULL,"
            "data TEXT NOT NULL,"
            "expires_at INTEGER"
        ")";

    QSqlQuery stmt(sql, m_connection);
    stmt.exec();

    return !stmt.lastError().isValid();
}

bool SqliteAdapter::store(QString key, QString data) {
    return store(key, data, 0);
}

bool SqliteAdapter::store(QString key, QString data, int ttl) {
    const QString sql =
      "INSERT OR REPLACE INTO cache (key, data, expires_at) "
      "VALUES (:key, :data, :expires_at)";

    QSqlQuery stmt(m_connection);
    stmt.prepare(sql);
    stmt.bindValue(":key", key);
    stmt.bindValue(":data", data);
    stmt.bindValue(":expires_at", now() + ttl);
    stmt.exec();

    return !stmt.lastError().isValid();
}

bool SqliteAdapter::has(QString key) {
    return !fetch(key).isEmpty();
}

bool SqliteAdapter::remove(QString key) {
    const QString sql = "DELETE FROM cache WHERE key = :key";

    QSqlQuery stmt(m_connection);
    stmt.prepare(sql);
    stmt.bindValue(":key", key);
    stmt.exec();

    return !stmt.lastError().isValid();
}

bool SqliteAdapter::clear() {
    const QString sql = "DELETE FROM cache";

    QSqlQuery stmt(m_connection);
    stmt.prepare(sql);
    stmt.exec();

    return !stmt.lastError().isValid();
}

QString SqliteAdapter::fetch(QString key) {
    const QString sql = "SELECT expires_at, data FROM cache WHERE key = :key";

    QSqlQuery stmt(m_connection);
    stmt.prepare(sql);
    stmt.bindValue(":key", key);
    stmt.exec();

    if (!stmt.lastError().isValid() && stmt.next()) {
        uint expires_at = stmt.value(0).toUInt();

        if ((expires_at == 0) || (expires_at >= now())) {
            return stmt.value(1).toString();
        }

        if (!remove(key)) {
            throw "Could not expire key '" + key + "'";
        }
    }

    return "";
}

QString SqliteAdapter::fetch(QString key, QString defaultValue) {
    return has(key) ? fetch(key) : defaultValue;
}

uint SqliteAdapter::now() {
    return QDateTime::currentDateTime().toTime_t();
}
