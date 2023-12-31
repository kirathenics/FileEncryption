#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <openssl/aes.h>
#include <openssl/rand.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Применение стилей к кнопке
    QString buttonStyle = "\
        QPushButton {\
            background-color: #31d62f;\
            border-style: outset;\
            border-width: 2px;\
            border-radius: 10px;\
            border-color: beige;\
            min-width: 10em;\
            padding: 6px;\
    }";

    ui->pushButton_encrypt->setStyleSheet(buttonStyle);
    ui->pushButton_decrypt->setStyleSheet(buttonStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionReset_Fields_triggered()
{
    // Очистить оба текстовых поля
    ui->plainTextEdit_plain->clear();
    ui->plainTextEdit_encrypted->clear();
}
void MainWindow::on_actionClear_Plain_Text_triggered()
{
    // Очистить поле для ввода обычного текста
    ui->plainTextEdit_plain->clear();
}

void MainWindow::on_actionClear_Encrypted_Text_triggered()
{
    // Очистить поле для ввода зашифрованного текста
    ui->plainTextEdit_encrypted->clear();
}

void MainWindow::on_actionNew_triggered()
{
    file_path ="";
    ui->plainTextEdit_plain->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());
    QMessageBox::information(this, "..", file_name);

    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile ::Text)) {
        QMessageBox::warning(this, "title", "file not opened");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit_plain->setPlainText(text);

    file.close();
}

void MainWindow::on_actionSave_Plain_Text_triggered()
{
    // Открытие файла
    QString file_name = QFileDialog::getSaveFileName(this, "Open a file", QDir::homePath());
    QFile file(file_name);
    file_path = file_name;

    if(!file.open(QFile::WriteOnly| QFile::Text)) {
        QMessageBox::warning(this,"..","file not opened");
        return;
    }
    QTextStream out(&file);
    QString text = ui-> plainTextEdit_plain->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_Encrypted_Text_triggered()
{
    // Сохранение обычного текста в файл
    QString file_name = QFileDialog::getSaveFileName(this, "Open a file", QDir::homePath());
    QFile file(file_name);
    file_path = file_name;

    if(!file.open(QFile::WriteOnly| QFile::Text)) {
        QMessageBox::warning(this,"..","file not opened");
        return;
    }
    QTextStream out(&file);
    QString text = ui-> plainTextEdit_encrypted->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    // Выход из программы
    exit(0);
}

void MainWindow::on_pushButton_encrypt_clicked()
{
    // Получаем текст из plainTextEdit_plain
    QString plainText = ui->plainTextEdit_plain->toPlainText();
    QString encryptedText = "Insert a File";

    if(ui->comboBox->currentIndex() == 0) // DES
    {
        QString key = ui->AES_lineEdit_key->text();
        encryptedText = ewDES(plainText, key.toStdString());
    }
    else if (ui->comboBox->currentIndex() == 1)  // AES
    {
        // Получение ключа
        QString key = ui->AES_lineEdit_key->text();
        QByteArray keyBytes = key.toUtf8();
        const unsigned char *aesKey = reinterpret_cast<const unsigned char*>(keyBytes.constData());

        // Генерация случайного IV
        unsigned char iv[AES_BLOCK_SIZE];
        //RAND_bytes(iv, AES_BLOCK_SIZE);

        // Зашифрование
        QByteArray plainBytes = plainText.toUtf8();
        const unsigned char *inputData = reinterpret_cast<const unsigned char*>(plainBytes.constData());

        unsigned char encryptedData[plainBytes.size() + AES_BLOCK_SIZE];
        AES_KEY encryptKey;
        //AES_set_encrypt_key(aesKey, 128, &encryptKey);
        //AES_cbc_encrypt(inputData, encryptedData, plainBytes.size(), &encryptKey, iv, AES_ENCRYPT);

        // Преобразование в строку шестнадцатеричных значений
        QString hexEncryptedText = QByteArray(reinterpret_cast<char*>(encryptedData), plainBytes.size() + AES_BLOCK_SIZE).toHex();

        encryptedText = hexEncryptedText;

        encryptedText = ewDES(plainText, key.toStdString());
    }

    // Устанавливаем зашифрованный текст в plainTextEdit_encrypted
    ui->plainTextEdit_encrypted->document()->setPlainText(encryptedText);
}

void MainWindow::on_pushButton_decrypt_clicked()
{
    // Получаем текст из plainTextEdit_encrypted
    QString encryptedText = ui->plainTextEdit_encrypted->toPlainText();
    QString plainText = "Insert a File";

    if(ui->comboBox->currentIndex() == 0) // DES
    {
        QString key = ui->AES_lineEdit_key->text();
        plainText = dwDES(encryptedText, key.toStdString());
    }
    else if (ui->comboBox->currentIndex() == 1)  // AES
    {
        // Получение ключа
        QString key = ui->AES_lineEdit_key->text();
        QByteArray keyBytes = key.toUtf8();
        const unsigned char *aesKey = reinterpret_cast<const unsigned char*>(keyBytes.constData());

        // Получение IV (первые 16 символов зашифрованного текста)
        QByteArray encryptedBytes = QByteArray::fromHex(encryptedText.toUtf8());
        unsigned char iv[AES_BLOCK_SIZE];
        memcpy(iv, encryptedBytes.constData(), AES_BLOCK_SIZE);

        // Расшифрование
        const unsigned char *inputData = reinterpret_cast<const unsigned char*>(encryptedBytes.constData() + AES_BLOCK_SIZE);

        unsigned char decryptedData[encryptedBytes.size() - AES_BLOCK_SIZE];
        AES_KEY decryptKey;
        //AES_set_decrypt_key(aesKey, 128, &decryptKey);
        //AES_cbc_encrypt(inputData, decryptedData, encryptedBytes.size() - AES_BLOCK_SIZE, &decryptKey, iv, AES_DECRYPT);

        // Преобразование в строку
        plainText = dwDES(encryptedText, key.toStdString());
    }

    // Устанавливаем расшифрованный текст в plainTextEdit_plain
    ui->plainTextEdit_plain->document()->setPlainText(plainText);
}

std::vector< std::string > MainWindow::keyPreparation(std::string key)
{
    // Подготовка ключа DES
    std::string permutedKey = "";
    int PC1_permutations[56] = {
        57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
    };

    for(int i=0;i<56; ++i)
    {
        permutedKey += key[PC1_permutations[i]-1];
    }

    int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    std::vector< std::pair<std::string, std::string> > keys;

    std::string C0 = permutedKey.substr(0,28);
    std::string D0 = permutedKey.substr(28,56);

    keys.push_back(std::make_pair(C0, D0));

    for(int i=1 ; i<17 ; ++i)
    {
        std::string C = keys[i-1].first;
        std::string D = keys[i-1].second;

        C = C.substr(shifts[i-1], C.length()) + C.substr(0, shifts[i-1]);
        D = D.substr(shifts[i-1], D.length()) + D.substr(0, shifts[i-1]);

        keys.push_back(std::make_pair(C, D));
    }


    int PC2_permutations[48] = {

        14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
    };

    std::vector<std::string> finalKeys;

    for(int i=0;i<16;++i)
    {
        std::string k = keys[i+1].first + keys[i+1].second;
        std::string fk = "";

        for(int j=0;j<48;++j)
        {
            fk += k[PC2_permutations[j]-1];
        }
        finalKeys.push_back(fk);
    }

    std::cout << std::endl << ">[BEGIN] Keys generated Successfully" << std::endl << std:: endl;

    for(int i=0; i<finalKeys.size(); ++i)
    {
        std::cout << "Key " << i+1 << ": " << finalKeys[i] << std::endl;
    }

    std::cout << std::endl << ">[END] Keys generated Successfully" << std::endl << std:: endl;

    return finalKeys;
}

QString MainWindow::DESEncryption(std::string dataBlock, std::vector< std::string > keys)
{
    // Шифрование блока данных DES
    std::string permutedBlock = "";

    int initPermutation[64] = {
        58,    50,   42,    34,    26,   18,    10,    2,
        60,    52,   44,    36,    28,   20,    12,    4,
        62,    54,   46,    38,    30,   22,    14,    6,
        64,    56,   48,    40,    32,   24,    16,    8,
        57,    49,   41,    33,    25,   17,     9,    1,
        59,    51,   43,    35,    27,   19,    11,    3,
        61,    53,   45,    37,    29,   21,    13,    5,
        63,    55,   47,    39,    31,   23,    15,    7
    };

    for(int i=0 ; i<64 ; ++i)
    {
        permutedBlock += dataBlock[initPermutation[i]-1];
    }

    std::string L0 = permutedBlock.substr(0, 32);
    std::string R0 = permutedBlock.substr(32, 64);


    std::cout << "L0 : " << L0 << std::endl;
    std::cout << "R0 : " << R0 << std::endl;

    std::vector< std::pair<std::string, std::string> > data;
    data.push_back(std::make_pair(L0, R0));

    for(int i=1;i<17;++i)
    {
        std::string L = data[i-1].second;

        std::string R = apply_xor(
            data[i-1].first,
            apply_func_F(apply_func_E(data[i-1].second), keys[i-1])
        );

        data.push_back(std::make_pair(L, R));

        std::cout << "L" << i << " : " << L << std::endl;
        std::cout << "R" << i << " : " << R << std::endl;
    }

    std::string encryptedDataReversedKey = "";
    encryptedDataReversedKey += data[data.size()-1].second;
    encryptedDataReversedKey += data[data.size()-1].first;

    std::string finalPermutedBlock = "";

    int finalPermutation[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41,  9, 49, 17, 57, 25
    };

    for(int i=0 ; i<64 ; ++i)
    {
        finalPermutedBlock += encryptedDataReversedKey[finalPermutation[i]-1];
    }

    return QString(finalPermutedBlock.c_str());
}

std::string MainWindow::apply_xor(std::string str1, std::string str2)
{
    // Применение операции XOR к двум строкам бит
    if(str1.length() != str2.length())
        std::cout << "Error in XORed Strings, Length Not Equal" << std::endl;

    std::string result = "";
    for(int i=0;i<str1.length();++i)
    {
        if(str1[i] == str2[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

std::string MainWindow::apply_func_F(std::string str1, std::string str2)
{
    // Применение функции F в DES
    std::string result = apply_xor(str1, str2);

    int sboxes[8][4][16] =
    {
        {
            { 14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7 },
            {  0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8 },
            {  4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0 },
            { 15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13 }
        },
        {
            { 15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10 },
            {  3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5 },
            {  0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15 },
            { 13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9 }
        },
        {
            { 10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8 },
            { 13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1 },
            { 13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7 },
            {  1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12 }
        },
        {
            {  7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15 },
            { 13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9 },
            { 10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4 },
            {  3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14 }
        },
        {
            {  2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9 },
            { 14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6 },
            {  4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14 },
            { 11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3 }
        },
        {
            { 12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11 },
            { 10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8 },
            {  9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6 },
            {  4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13 }
        },
        {
            {  4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1 },
            { 13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6 },
            {  1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2 },
            {  6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12 }
        },
        {
            { 13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7 },
            {  1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2 },
            {  7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8 },
            {  2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11 }
        }
    };

    std::string output = "";
    std::string outerBits = "";
    std::string innerBits = "";

    for(int i=0, s=0 ; i<48 ; i+=6, s++)
    {
        outerBits += result[i];
        outerBits += result[i+5];

        innerBits += result[i+1];
        innerBits += result[i+2];
        innerBits += result[i+3];
        innerBits += result[i+4];

        int row = std::stoi(outerBits, nullptr, 2);
        int column = std::stoi(innerBits, nullptr, 2);

        int valInSBox = sboxes[s][row][column];

        output += std::bitset<4>(valInSBox).to_string();

        outerBits = "";
        innerBits = "";
    }

    std::string permutedOutput = "";

    int permutations[32] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
    };

    for(int i=0; i<32; ++i)
    {
        permutedOutput += output[permutations[i]-1];
    }

    return permutedOutput;
}

std::string MainWindow::apply_func_E(std::string str)
{
    // Применение функции E в DES
    std::string result = "";

    int ePermutations[48] = {
         32,     1,    2,     3,     4,    5,
          4,     5,    6,     7,     8,    9,
          8,     9,   10,    11,    12,   13,
         12,    13,   14,    15,    16,   17,
         16,    17,   18,    19,    20,   21,
         20,    21,   22,    23,    24,   25,
         24,    25,   26,    27,    28,   29,
         28,    29,   30,    31,    32,    1
    };

    for(int i=0;i<48;++i)
    {
        result += str[ePermutations[i]-1];
    }

    return result;
}

std::vector< std::string > MainWindow::textToBinaryAscii(std::string str)
{
    // Преобразование текста в бинарный ASCII формат
    std::vector< std::string > blocksOfData;

    for(int i=0; i<str.size()/8; ++i)
    {
        std::string blockStr = str.substr(i*8, 8);
        std::string block = "";

        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);

        blocksOfData.push_back(block);
    }

    if(str.size()%8 != 0)
    {
        int start = ((int)str.size()/8)*8;
        int length = (int)str.size()- start;

        std::string blockStr = str.substr(start, length);
        for(int i=0; i<(8-length); ++i)
            blockStr += " ";

        std::string block = "";
        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);
        blocksOfData.push_back(block);
    }

    return blocksOfData;
}

std::string MainWindow::binaryAsciiToText(std::string str)
{
    // Преобразование бинарного ASCII формата в текст
    std::string blocksOfData = "";

    for(int i=0; i<str.size()/64; ++i)
    {
        std::string blockStr = str.substr(i*64, 64);
        std::string block = "";

        for(int i=0; i<8; ++i)
        {
           std::string ascii = blockStr.substr(i*8, 8);
           block += binaryAsciiToChar(ascii);
        }
        blocksOfData += block;
    }

    return blocksOfData;
}

std::string MainWindow::charToBinaryAscii(char ch)
{
    // Преобразование символа в бинарный ASCII формат
    return std::bitset<8>(int(ch)).to_string();
}

char MainWindow::binaryAsciiToChar(std::string binaryAscii)
{
    // Преобразование бинарного ASCII формата в символ
    return char(std::bitset<8>(binaryAscii).to_ulong());
}

QString MainWindow::ewDES(QString plainText, std::string key)
{
    // Зашифрование DES
    std::vector< std::string > keys = keyPreparation(key);
    std::vector< std::string > blocks = textToBinaryAscii(plainText.toStdString());

    QString encryptedText;

    for(int i=0; i<blocks.size(); ++i)
        encryptedText += DESEncryption(blocks[i], keys);

    return encryptedText;
}

QString MainWindow::dwDES(QString encryptedText, std::string key)
{
    // Расшифрование DES
    std::vector< std::string > keys = keyPreparation(key);
    std::reverse(keys.begin(), keys.end());

    std::string stdPlainText = encryptedText.toStdString();
    std::string allPlainText = "";

    for(int i=0; i<encryptedText.size()/64; ++i)
    {
        allPlainText += DESEncryption(stdPlainText.substr(i*64, 64), keys).toStdString();
    }

    return QString::fromStdString(binaryAsciiToText(allPlainText));
}

