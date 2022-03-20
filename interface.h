#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    QVector<int> player_input;

    Interface(QWidget *parent = nullptr);
    ~Interface();
    void turn_processing();

    void pattern_flasher();

    void reset_game();

    void show_game_over();

private slots:
    void on_difficulty_slider_sliderMoved(int position);

    void on_difficulty_slider_valueChanged(int value);

    void on_start_button_clicked();

    void on_actionRestart_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Interface *ui;
    void index_flasher(int idx);
    void pressed(int idx);
    void change_difficulty(int difficulty);
    void delay(int ms);
};
#endif // INTERFACE_H
