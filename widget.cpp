#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    play_data a;
    a.name = ui->lineEdit->text();
    a.score = ui->lineEdit_2->text().toInt();
    if(!isdigit(a.score))
        ui->lineEdit_2->setText("Неправильный ввод");
    players.push_back(a);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Widget::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
    QVector<play_data>::iterator i;
    int m = 0;

    std::sort(players.begin(), players.end(), [] (play_data lh, play_data rh)
    {return lh.getScore() > rh.getScore();});
    for(i = players.begin(); i < players.end(); i++)
    {
        play_data b = players[m];
        QString str = b.name;
        QString sc = QString::number(b.score);
        m++;
        QString place = QString::number(m);
        ui->plainTextEdit->insertPlainText(place + ": " + str + " баллы:" + sc + "\n");
    }

    QFile file("C:\\Konkurs\\DATA.txt");
    QTextStream in(&file);
    if (file.open(QIODevice::WriteOnly))
    {
        QString str = ui->plainTextEdit->toPlainText();
        in << str;
        file.flush();
        file.close();
    }
}
