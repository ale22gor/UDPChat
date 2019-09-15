#ifndef UDPBACK_GLOBAL_H
#define UDPBACK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UDPBACK_LIBRARY)
#  define UDPBACKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define UDPBACKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UDPBACK_GLOBAL_H
