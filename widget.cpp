#include "widget.h"
#include "ui_widget.h"
#include <random>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    random_num = random_number(0, 10);

    ui->start_over_button->setDisabled(true);
    ui->game_info_label->setText("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guess_button_clicked()
{
    your_guess = ui->spinBox->value();
    if(your_guess > random_num)
    {
        ui->game_info_label->setText("the number is less than "+QString::number(your_guess));
    }
    else if (your_guess < random_num)
    {
        ui->game_info_label->setText("the number is greater than "+QString::number(your_guess));
    }
    else if(your_guess == random_num){
        ui->game_info_label->setText("CONGRATS YOU GUESSED IT RIGHT!");

        ui->guess_button->setDisabled(true);
        ui->start_over_button->setDisabled(false);
    }
}


void Widget::on_start_over_button_clicked()
{
    ui->guess_button->setDisabled(false);
    ui->start_over_button->setDisabled(true);
    ui->spinBox->setValue(0);
    random_num = random_number(0, 10);
    ui->game_info_label->setText("");

}

