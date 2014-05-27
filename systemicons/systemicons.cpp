#include "systemicons.h"

#ifdef Q_OS_WIN
# include "systemicons_win_p.h"
#endif

#ifdef Q_OS_MAC
# include "systemicons_mac_p.h"
#endif

/**
    SystemIcons provide access to system Error, Warning, and Information icons.

    On all platforms 16x16 and 32x32 resolutions are provided.
 */
QIcon SystemIcons::icon(SystemIcons::IconType iconType)
{
    QIcon icon;
#if defined(Q_OS_WIN)
    icon = winIcon(iconType);
#elif defined(Q_OS_MAC)
    if (iconType == WarningIcon)
        icon = macWarningIcon();
#endif

    if (icon.isNull()) {
        switch(iconType) {
        case ErrorIcon:
            if (QIcon::hasThemeIcon(QLatin1String("dialog-error"))) {
                icon = QIcon::fromTheme(QLatin1String("dialog-error"));
            } else {
                icon.addPixmap(QPixmap(QLatin1String(":/images/error_16.png")));
                icon.addPixmap(QPixmap(QLatin1String(":/images/error_32.png")));
            }
            break;
        case WarningIcon:
            if (QIcon::hasThemeIcon(QLatin1String("dialog-warning"))) {
                icon = QIcon::fromTheme(QLatin1String("dialog-warning"));
            } else {
                icon.addPixmap(QPixmap(QLatin1String(":/images/warning_16.png")));
                icon.addPixmap(QPixmap(QLatin1String(":/images/warning_32.png")));
            }
            break;
        case InformationIcon:
            if (QIcon::hasThemeIcon(QLatin1String("dialog-information"))) {
                icon = QIcon::fromTheme(QLatin1String("dialog-information"));
            } else {
                icon.addPixmap(QPixmap(QLatin1String(":/images/information_16.png")));
                icon.addPixmap(QPixmap(QLatin1String(":/images/information_32.png")));
            }
            break;
        }
    }

    return icon;
}
