#ifndef SYSTEMICONS_H
#define SYSTEMICONS_H

#include <QIcon>

class SystemIcons {
public:
    enum IconType {
        ErrorIcon,
        WarningIcon,
        InformationIcon
    };

    static QIcon icon(IconType iconType);
};

#endif // SYSTEMICONS_H
