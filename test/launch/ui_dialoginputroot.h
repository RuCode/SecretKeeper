/********************************************************************************
** Form generated from reading UI file 'dialoginputroot.ui'
**
** Created: Sun Oct 12 22:33:32 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINPUTROOT_H
#define UI_DIALOGINPUTROOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogInputRoot
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogInputRoot)
    {
        if (DialogInputRoot->objectName().isEmpty())
            DialogInputRoot->setObjectName(QString::fromUtf8("DialogInputRoot"));
        DialogInputRoot->resize(377, 83);
        horizontalLayout_2 = new QHBoxLayout(DialogInputRoot);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogInputRoot);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(DialogInputRoot);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(DialogInputRoot);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DialogInputRoot);

        QMetaObject::connectSlotsByName(DialogInputRoot);
    } // setupUi

    void retranslateUi(QDialog *DialogInputRoot)
    {
        DialogInputRoot->setWindowTitle(QApplication::translate("DialogInputRoot", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogInputRoot", "\320\230\320\274\321\217 \321\200\320\260\320\267\320\264\320\265\320\273\320\260:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DialogInputRoot", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogInputRoot: public Ui_DialogInputRoot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINPUTROOT_H
