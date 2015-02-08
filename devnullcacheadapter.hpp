#ifndef BIDSTACK_CACHE_DEVNULLCACHEADAPTER_HPP
#define BIDSTACK_CACHE_DEVNULLCACHEADAPTER_HPP

#include <QObject>

#include "abstractcacheadapter.hpp"

namespace Bidstack {
    namespace Cache {

        class DevNullCacheAdapter : public AbstractCacheAdapter {
            Q_OBJECT

        public:
            DevNullCacheAdapter(QObject *parent = 0);

        public:
            bool store(QString key, QString data);
            bool store(QString key, QString data, int ttl);
            bool has(QString key);
            bool remove(QString key);
            bool clear();
            QString fetch(QString key);
            QString fetch(QString key, QString defaultValue);
        };

    };
};

#endif
