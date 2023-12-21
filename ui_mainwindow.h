/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReset_Fields;
    QAction *actionClear_Plain_Text;
    QAction *actionClear_Encrypted_Text;
    QAction *actionAbout_Qt;
    QAction *actionExit;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave_Plain_Text;
    QAction *actionSave_Encrypted_Text;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_encrypt;
    QPushButton *pushButton_decrypt;
    QStackedWidget *stackedWidget;
    QWidget *AES;
    QLineEdit *AES_lineEdit_key;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_plain;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_encrypted;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(602, 410);
        actionReset_Fields = new QAction(MainWindow);
        actionReset_Fields->setObjectName(QString::fromUtf8("actionReset_Fields"));
        actionClear_Plain_Text = new QAction(MainWindow);
        actionClear_Plain_Text->setObjectName(QString::fromUtf8("actionClear_Plain_Text"));
        actionClear_Encrypted_Text = new QAction(MainWindow);
        actionClear_Encrypted_Text->setObjectName(QString::fromUtf8("actionClear_Encrypted_Text"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave_Plain_Text = new QAction(MainWindow);
        actionSave_Plain_Text->setObjectName(QString::fromUtf8("actionSave_Plain_Text"));
        actionSave_Encrypted_Text = new QAction(MainWindow);
        actionSave_Encrypted_Text->setObjectName(QString::fromUtf8("actionSave_Encrypted_Text"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton_encrypt = new QPushButton(centralWidget);
        pushButton_encrypt->setObjectName(QString::fromUtf8("pushButton_encrypt"));
        pushButton_encrypt->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_encrypt->sizePolicy().hasHeightForWidth());
        pushButton_encrypt->setSizePolicy(sizePolicy);
        pushButton_encrypt->setMinimumSize(QSize(200, 0));
        pushButton_encrypt->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_encrypt->setStyleSheet(QString::fromUtf8(""));
        pushButton_encrypt->setCheckable(true);
        pushButton_encrypt->setChecked(false);
        pushButton_encrypt->setAutoDefault(false);
        pushButton_encrypt->setFlat(false);

        horizontalLayout->addWidget(pushButton_encrypt);

        pushButton_decrypt = new QPushButton(centralWidget);
        pushButton_decrypt->setObjectName(QString::fromUtf8("pushButton_decrypt"));
        sizePolicy.setHeightForWidth(pushButton_decrypt->sizePolicy().hasHeightForWidth());
        pushButton_decrypt->setSizePolicy(sizePolicy);
        pushButton_decrypt->setMinimumSize(QSize(200, 0));
        pushButton_decrypt->setCheckable(false);
        pushButton_decrypt->setChecked(false);

        horizontalLayout->addWidget(pushButton_decrypt);


        verticalLayout_3->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShadow(QFrame::Plain);
        AES = new QWidget();
        AES->setObjectName(QString::fromUtf8("AES"));
        AES_lineEdit_key = new QLineEdit(AES);
        AES_lineEdit_key->setObjectName(QString::fromUtf8("AES_lineEdit_key"));
        AES_lineEdit_key->setGeometry(QRect(109, 20, 461, 31));
        label_7 = new QLabel(AES);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 20, 101, 30));
        stackedWidget->addWidget(AES);

        verticalLayout_3->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        plainTextEdit_plain = new QPlainTextEdit(centralWidget);
        plainTextEdit_plain->setObjectName(QString::fromUtf8("plainTextEdit_plain"));

        verticalLayout->addWidget(plainTextEdit_plain);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        plainTextEdit_encrypted = new QPlainTextEdit(centralWidget);
        plainTextEdit_encrypted->setObjectName(QString::fromUtf8("plainTextEdit_encrypted"));

        verticalLayout_2->addWidget(plainTextEdit_encrypted);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Plain_Text);
        menuFile->addAction(actionSave_Encrypted_Text);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionReset_Fields);
        menuEdit->addSeparator();
        menuEdit->addAction(actionClear_Plain_Text);
        menuEdit->addAction(actionClear_Encrypted_Text);

        retranslateUi(MainWindow);

        pushButton_encrypt->setDefault(false);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Encryption Algorithms", nullptr));
        actionReset_Fields->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        actionClear_Plain_Text->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\236\320\261\321\213\321\207\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        actionClear_Encrypted_Text->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        actionSave_Plain_Text->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272 \320\236\320\261\321\213\321\207\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        actionSave_Encrypted_Text->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272 \320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "DES", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "AES", nullptr));

#if QT_CONFIG(tooltip)
        comboBox->setToolTip(QCoreApplication::translate("MainWindow", "Choose Encryption Algorithm", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        comboBox->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(tooltip)
        pushButton_encrypt->setToolTip(QCoreApplication::translate("MainWindow", "Encrypt Input Text", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_encrypt->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_encrypt->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_encrypt->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_decrypt->setToolTip(QCoreApplication::translate("MainWindow", "Decrypt input text", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_decrypt->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(whatsthis)
        label_7->setWhatsThis(QCoreApplication::translate("MainWindow", "<html>\n"
"<head/>\n"
"<body>\n"
"<p><br/></p>\n"
"</body>\n"
"</html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\272\321\200\320\265\321\202\320\275\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\213\321\207\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
