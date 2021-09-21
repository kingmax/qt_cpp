#include "textfinder.h"
#include "stdafx.h"

#include <QFile>
#include <QTextStream>


TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    loadTextFile();
}

void TextFinder::on_btnFind_clicked()
{
    QString keyword = ui.leKeyword->text();

    QMessageBox::critical(this, u8"¹Ø¼ü×Ö", keyword);

    ui.textEdit->find(keyword, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream txt(&inputFile);
    QString line = txt.readAll();
    inputFile.close();

    ui.textEdit->setPlainText(line);
    QTextCursor cursor = ui.textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
