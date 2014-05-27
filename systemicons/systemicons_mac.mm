#include "systemicons_mac_p.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#  include <qmacfunctions.h>
#endif

#include <Cocoa/Cocoa.h>

QIcon macWarningIcon()
{
    NSImage *image = [NSImage imageNamed:NSImageNameCaution];
    NSData *imageData = [image TIFFRepresentation];
    if (!imageData)
        return QPixmap();
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef cgimage = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);

    QIcon icon;
    // defaule size is 32x32
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    QPixmap bigPixmap = QtMac::fromCGImageRef(cgimage);
#else
    QPixmap bigPixmap = QPixmap::fromMacCGImageRef(cgimage);
#endif
    icon.addPixmap(bigPixmap);
    icon.addPixmap(bigPixmap.scaled(16, 16, Qt::KeepAspectRatio));
    return icon;
}
