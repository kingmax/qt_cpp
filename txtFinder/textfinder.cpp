#include "textfinder.h"
#include "ui_textfinder.h"

#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::on_btnFind_clicked()
{
    QString keyword = ui->lineEdit->text();
    ui->textEdit->find(keyword, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFile()
{
    QFile input(":/input.txt");
    input.open(QIODevice::ReadOnly);

    QTextStream ts(&input);
    QString line = ts.readAll();
    input.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

