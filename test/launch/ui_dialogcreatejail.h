/********************************************************************************
** Form generated from reading UI file 'dialogcreatejail.ui'
**
** Created: Sun Oct 19 14:22:28 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCREATEJAIL_H
#define UI_DIALOGCREATEJAIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCreateJail
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_PassFirst;
    QPushButton *pushButton_Gen;
    QPushButton *pushButton_hide;
    QLabel *label_2;
    QLineEdit *lineEdit_PassLast;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Path;
    QPushButton *pushButton_Path;
    QCheckBox *checkBox_AutoOpen;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Save;

    void setupUi(QDialog *DialogCreateJail)
    {
        if (DialogCreateJail->objectName().isEmpty())
            DialogCreateJail->setObjectName(QString::fromUtf8("DialogCreateJail"));
        DialogCreateJail->resize(424, 246);
        horizontalLayout_2 = new QHBoxLayout(DialogCreateJail);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DialogCreateJail);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_PassFirst = new QLineEdit(DialogCreateJail);
        lineEdit_PassFirst->setObjectName(QString::fromUtf8("lineEdit_PassFirst"));

        horizontalLayout_4->addWidget(lineEdit_PassFirst);

        pushButton_Gen = new QPushButton(DialogCreateJail);
        pushButton_Gen->setObjectName(QString::fromUtf8("pushButton_Gen"));

        horizontalLayout_4->addWidget(pushButton_Gen);

        pushButton_hide = new QPushButton(DialogCreateJail);
        pushButton_hide->setObjectName(QString::fromUtf8("pushButton_hide"));

        horizontalLayout_4->addWidget(pushButton_hide);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(DialogCreateJail);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_PassLast = new QLineEdit(DialogCreateJail);
        lineEdit_PassLast->setObjectName(QString::fromUtf8("lineEdit_PassLast"));

        verticalLayout->addWidget(lineEdit_PassLast);

        label_3 = new QLabel(DialogCreateJail);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_Path = new QLineEdit(DialogCreateJail);
        lineEdit_Path->setObjectName(QString::fromUtf8("lineEdit_Path"));

        horizontalLayout_3->addWidget(lineEdit_Path);

        pushButton_Path = new QPushButton(DialogCreateJail);
        pushButton_Path->setObjectName(QString::fromUtf8("pushButton_Path"));

        horizontalLayout_3->addWidget(pushButton_Path);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        checkBox_AutoOpen = new QCheckBox(DialogCreateJail);
        checkBox_AutoOpen->setObjectName(QString::fromUtf8("checkBox_AutoOpen"));

        verticalLayout_2->addWidget(checkBox_AutoOpen);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Cancel = new QPushButton(DialogCreateJail);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_Save = new QPushButton(DialogCreateJail);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        horizontalLayout->addWidget(pushButton_Save);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(DialogCreateJail);

        QMetaObject::connectSlotsByName(DialogCreateJail);
    } // setupUi

    void retranslateUi(QDialog *DialogCreateJail)
    {
        DialogCreateJail->setWindowTitle(QApplication::translate("DialogCreateJail", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogCreateJail", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        pushButton_Gen->setText(QApplication::translate("DialogCreateJail", "...", 0, QApplication::UnicodeUTF8));
        pushButton_hide->setText(QApplication::translate("DialogCreateJail", "\320\245", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogCreateJail", "<html><head/><body><p>\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogCreateJail", "<html><head/><body><p>\320\237\321\203\321\202\321\214 \320\272 \321\205\321\200\320\260\320\275\320\270\320\273\320\270\321\211\321\203:</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_Path->setText(QApplication::translate("DialogCreateJail", "...", 0, QApplication::UnicodeUTF8));
        checkBox_AutoOpen->setText(QApplication::translate("DialogCreateJail", "\320\236\321\202\320\272\321\200\321\213\320\262\320\260\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270 \320\277\321\200\320\270 \320\267\320\260\320\277\321\203\321\201\320\272\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("DialogCreateJail", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("DialogCreateJail", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogCreateJail: public Ui_DialogCreateJail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCREATEJAIL_H
