#ifndef BIDSTACK_CACHE_SQLITECACHEADAPTER_HPP
#define BIDSTACK_CACHE_SQLITECACHEADAPTER_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "abstractcacheadapter.hpp"

namespace Bidstack {
    namespace Cache {

        class SqliteCacheAdapter : public AbstractCacheAdapter {
            Q_OBJECT

        public:
            SqliteCacheAdapter(QString filename, QObject *parent = 0);

        public:
            bool store(QString key, QString data);
            bool store(QString key, QString data, int ttl);
            bool has(QString key);
            bool remove(QString key);
            bool clear();
            QString fetch(QString key);
            QString fetch(QString key, QString defaultValue);

        private:
            bool init(QString filename);
            uint now();

        private:
            QSqlDatabase m_connection;
        };

    };
};

#endif
