/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Oct 12 23:10:34 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewKeeper;
    QAction *actionOpenKeeper;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionClose;
    QAction *actionNewRoot;
    QAction *actionNewKey;
    QAction *actionEditKey;
    QAction *actionDeleteKey;
    QAction *actionGenerateKey;
    QAction *action_QPasswordKeeper;
    QAction *action_QSafeFileJail;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Name;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Pass;
    QPushButton *pushButton;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_Sha1;
    QLabel *label_4;
    QLineEdit *lineEdit_md5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(563, 336);
        actionNewKeeper = new QAction(MainWindow);
        actionNewKeeper->setObjectName(QString::fromUtf8("actionNewKeeper"));
        actionOpenKeeper = new QAction(MainWindow);
        actionOpenKeeper->setObjectName(QString::fromUtf8("actionOpenKeeper"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionNewRoot = new QAction(MainWindow);
        actionNewRoot->setObjectName(QString::fromUtf8("actionNewRoot"));
        actionNewKey = new QAction(MainWindow);
        actionNewKey->setObjectName(QString::fromUtf8("actionNewKey"));
        actionEditKey = new QAction(MainWindow);
        actionEditKey->setObjectName(QString::fromUtf8("actionEditKey"));
        actionDeleteKey = new QAction(MainWindow);
        actionDeleteKey->setObjectName(QString::fromUtf8("actionDeleteKey"));
        actionGenerateKey = new QAction(MainWindow);
        actionGenerateKey->setObjectName(QString::fromUtf8("actionGenerateKey"));
        action_QPasswordKeeper = new QAction(MainWindow);
        action_QPasswordKeeper->setObjectName(QString::fromUtf8("action_QPasswordKeeper"));
        action_QSafeFileJail = new QAction(MainWindow);
        action_QSafeFileJail->setObjectName(QString::fromUtf8("action_QSafeFileJail"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEditTriggers(QAbstractItemView::EditKeyPressed);
        treeWidget->setTabKeyNavigation(false);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeWidget->setTextElideMode(Qt::ElideRight);
        treeWidget->header()->setVisible(false);

        horizontalLayout->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_Name = new QLineEdit(centralWidget);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        horizontalLayout_2->addWidget(lineEdit_Name);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        lineEdit_Pass = new QLineEdit(centralWidget);
        lineEdit_Pass->setObjectName(QString::fromUtf8("lineEdit_Pass"));

        horizontalLayout_3->addWidget(lineEdit_Pass);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(48, 16777215));
        pushButton->setFlat(false);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_Sha1 = new QLineEdit(centralWidget);
        lineEdit_Sha1->setObjectName(QString::fromUtf8("lineEdit_Sha1"));

        horizontalLayout_4->addWidget(lineEdit_Sha1);


        verticalLayout->addLayout(horizontalLayout_4);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        lineEdit_md5 = new QLineEdit(centralWidget);
        lineEdit_md5->setObjectName(QString::fromUtf8("lineEdit_md5"));

        verticalLayout->addWidget(lineEdit_md5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 563, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(actionNewKeeper);
        menu->addSeparator();
        menu->addAction(actionOpenKeeper);
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu->addAction(actionClose);
        menu_3->addAction(actionNewRoot);
        menu_3->addSeparator();
        menu_3->addAction(actionNewKey);
        menu_3->addAction(actionEditKey);
        menu_3->addAction(actionDeleteKey);
        menu_3->addSeparator();
        menu_3->addAction(actionGenerateKey);
        menu_4->addAction(action_QPasswordKeeper);
        menu_4->addSeparator();
        menu_4->addAction(action_QSafeFileJail);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PasswordKeeper", 0, QApplication::UnicodeUTF8));
        actionNewKeeper->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\205\321\200\320\260\320\275\320\270\320\273\320\270\321\211\320\265", 0, QApplication::UnicodeUTF8));
        actionOpenKeeper->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\205\321\200\320\260\320\275\320\270\320\273\320\270\321\211\320\265", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        actionNewRoot->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\200\320\260\320\267\320\264\320\265\320\273", 0, QApplication::UnicodeUTF8));
        actionNewKey->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        actionEditKey->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        actionDeleteKey->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        actionGenerateKey->setText(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\320\265\320\271", 0, QApplication::UnicodeUTF8));
        action_QPasswordKeeper->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202 QPasswordKeeper", 0, QApplication::UnicodeUTF8));
        action_QSafeFileJail->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202 QSafeFileJail", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Sha1:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "MD5:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\245\321\200\320\260\320\275\320\270\320\273\320\270\321\211\320\265", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\273\320\260\320\264\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
