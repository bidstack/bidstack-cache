#ifndef BIDSTACK_CACHE_SQLITEADAPTER_HPP
#define BIDSTACK_CACHE_SQLITEADAPTER_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "abstractadapter.hpp"

namespace Bidstack {
    namespace Cache {

        class SqliteAdapter : public AbstractAdapter {
            Q_OBJECT

        public:
            SqliteAdapter(QString filename, QObject *parent = 0);

        public:
            bool store(QString key, QString data);
            bool has(QString key);
            bool remove(QString key);
            bool clear();
            QString fetch(QString key);
            QString fetch(QString key, QString defaultValue);

        private:
            bool init(QString filename);

        private:
            QSqlDatabase m_connection;
        };

    };
};

#endif
