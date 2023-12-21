#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>

struct Position {
    int x;
    int y;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Слоты действий
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_Plain_Text_triggered();
    void on_actionSave_Encrypted_Text_triggered();
    void on_actionExit_triggered();

    void on_actionReset_Fields_triggered();
    void on_actionClear_Plain_Text_triggered();
    void on_actionClear_Encrypted_Text_triggered();

    // Слоты кнопок
    void on_pushButton_encrypt_clicked();
    void on_pushButton_decrypt_clicked();

private:
    Ui::MainWindow *ui;
    QString file_path;

    // Вспомогательные переменные
    std::vector< std::string > keyPreparation(std::string key);
    QString DESEncryption(std::string dataBlock, std::vector< std::string > keys);
    std::string apply_xor(std::string str1, std::string str2);
    std::string apply_func_F(std::string str1, std::string str2);
    std::string apply_func_E(std::string str);
    char binaryAsciiToChar(std::string binaryAscii);
    std::string charToBinaryAscii(char ch);
    std::string binaryAsciiToText(std::string str);
    std::vector< std::string > textToBinaryAscii(std::string str);

    //Л огика шифрования и дешифрования
    QString ewDES(QString plainText, std::string key);
    QString dwDES(QString encryptedText, std::string key);
};

#endif // MAINWINDOW_H
