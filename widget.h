#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "Play_data.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_actionTriggered(int action);

private:
    Ui::Widget *ui;
    QVector<Play_data> players;
    QVector<Play_data> players2;
    int t = 1;
};

#endif // WIDGET_H
