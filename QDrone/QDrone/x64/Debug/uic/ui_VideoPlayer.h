/********************************************************************************
** Form generated from reading UI file 'VideoPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayerClass
{
public:

    void setupUi(QWidget *VideoPlayerClass)
    {
        if (VideoPlayerClass->objectName().isEmpty())
            VideoPlayerClass->setObjectName(QString::fromUtf8("VideoPlayerClass"));
        VideoPlayerClass->resize(600, 400);

        retranslateUi(VideoPlayerClass);

        QMetaObject::connectSlotsByName(VideoPlayerClass);
    } // setupUi

    void retranslateUi(QWidget *VideoPlayerClass)
    {
        VideoPlayerClass->setWindowTitle(QCoreApplication::translate("VideoPlayerClass", "VideoPlayer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayerClass: public Ui_VideoPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
