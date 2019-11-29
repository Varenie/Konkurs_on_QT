#include "widget.h"
#include "ui_widget.h"
#include "Play_data.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIntValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    ui->spinBox->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->horizontalSlider->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int m = 1;
    int id = ui->spinBox->value();

    Play_data b = players[id - 1];
    Play_data a;
    a.name = b.name;
    a.id = b.id;
    a.score = ui->horizontalSlider->value();
    players2.push_back(a);
    m++;

    ui->spinBox->clear();
    ui->label_2->setText("Баллы:");
    ui->label_3->clear();
    ui->label_3->setText("Участник:");

}

void Widget::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
    QVector<Play_data>::iterator i;
    int m = 0;

    std::sort(players2.begin(), players2.end(), [] (Play_data lh, Play_data rh)
    {return lh.getScore() > rh.getScore();});
    for(i = players.begin(); i < players.end(); i++)
    {
        Play_data b = players2[m];
        QString sc = QString::number(b.score);
        QString str = b.name;
        m++;
        QString place = QString::number(m);
        ui->plainTextEdit->insertPlainText(place + " место занял  участник: " + str +
                                           " с количеством баллов: " + sc + "\n");
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


void Widget::on_pushButton_3_clicked()
{
    Play_data a;
    a.id = t;
    QString num = QString::number(t);
    t++;
    a.name = ui->lineEdit->text();
    players.push_back(a);
    ui->lineEdit->clear();

}

void Widget::on_pushButton_4_clicked()
{
    ui->plainTextEdit->clear();
    QVector<Play_data>::iterator i;
    int m = 0;

    for(i = players.begin(); i < players.end(); i++)
    {
        Play_data b = players[m];
        QString id = QString::number(b.id);
        QString str = b.name;
        m++;
        ui->plainTextEdit->insertPlainText("Номер: " + id + " " + str + "\n");
    }
    ui->label->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->lineEdit->setVisible(false);

    ui->spinBox->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->horizontalSlider->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
    ui->spinBox->setMaximum(t - 1);
    ui->spinBox->setMinimum(0);
}

void Widget::on_spinBox_valueChanged(int arg1)
{
    QVector<Play_data>::iterator i;
    int id;
    int m = 0;

    id = ui->spinBox->value();
    for(i = players.begin(); i < players.end(); i++)
    {
        Play_data b = players[m];
        if(id == b.id){
            ui->label_3->setText("Участник: " + b.name);
        }
        m++;
    }
}

void Widget::on_horizontalSlider_actionTriggered(int action)
{
    t = ui->horizontalSlider->value();
    QString num = QString::number(t);
    ui->label_2->setText("Баллы: " + num);
}
