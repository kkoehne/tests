#include "systemicons_win_p.h"

#include <qt_windows.h>
#include <QIcon>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
Q_GUI_EXPORT QPixmap qt_pixmapFromWinHICON(HICON icon);
#endif


QIcon winIcon(SystemIcons::IconType type)
{
    QIcon icon;

    HICON iconLarge;
    HICON iconSmall;

    int index;
    switch(type) {
    case SystemIcons::WarningIcon: index = 1; break;
    case SystemIcons::ErrorIcon: index = 3; break;
    case SystemIcons::InformationIcon: index = 2; break;
    }

    ExtractIconEx(L"user32.dll", index, &iconLarge, &iconSmall, 1);


#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    QPixmap pixmapSmall = qt_pixmapFromWinHICON(iconSmall);
    QPixmap pixmapLarge = qt_pixmapFromWinHICON(iconLarge);
#else
    QPixmap pixmapSmall = QPixmap::fromWinHICON(iconSmall);
    QPixmap pixmapLarge = QPixmap::fromWinHICON(iconLarge);
#endif
    DestroyIcon(iconLarge);
    DestroyIcon(iconSmall);

    if (!pixmapSmall.isNull())
        icon.addPixmap(pixmapSmall);
    if (!pixmapLarge.isNull())
        icon.addPixmap(pixmapLarge);

    return icon;
}
