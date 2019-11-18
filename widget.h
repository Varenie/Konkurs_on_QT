#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

struct play_data
{
    QString name;
    int score;

    int getScore()
    {
        return score;
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QVector<play_data> players;
};

#endif // WIDGET_H
