#include "interface.h"
#include "ui_interface.h"
#include "globals.h"
#include "gameloop.h"
#include "mytimer.h"
#include <QProcess>
#include <QMessageBox>
#include <qfile.h>
#include <QIODevice>
#include <QPalette>
#include <QColor>
#include <QTime>

std::atomic<bool> signal { false };

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    //Initialize Difficulty
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->health->display(Globals::health);
    //ensure all buttons turn black when pressed
    ui->pushButton_2->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_3->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_4->setStyleSheet( QString("QPushButton {background-color: rgb(75,0,150);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_5->setStyleSheet( QString("QPushButton {background-color: rgb(200,128,0);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_6->setStyleSheet( QString("QPushButton {background-color: rgb(128,200,0);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_7->setStyleSheet( QString("QPushButton {background-color: rgb(200,200,200);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_8->setStyleSheet( QString("QPushButton {background-color: rgb(200,0,200);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
    ui->pushButton_9->setStyleSheet( QString("QPushButton {background-color: rgb(200,200,0);} QPushButton:pressed {background-color: rgb(0,0,0);}"));
}

Interface::~Interface()
{
    delete ui;
}

//passes the difficulty from the silder to the difficulty controller
void Interface::on_difficulty_slider_sliderMoved(int position)
{
    this->change_difficulty(position);
}

//Toggles the difficulty between on and off
void Interface::on_difficulty_slider_valueChanged(int value)
{
    this->change_difficulty(value);
}

//difficulty slider controlls
void Interface::change_difficulty(int difficulty)
{
    //Change The number of Rows visible
    //change the value for the random yield value
    switch (difficulty)
    {

    case 1:
       ui->pushButton_4->hide();
       ui->pushButton_5->hide();
       ui->pushButton_6->hide();
       ui->pushButton_7->hide();
       ui->pushButton_8->hide();
       ui->pushButton_9->hide();
       Globals::difficulty = 1;
       break;
    case 2:
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        Globals::difficulty = 2;
        break;
    case 3:
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        ui->pushButton_7->show();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        Globals::difficulty = 3;
        break;
    case 4:
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
        Globals::difficulty = 4;
        break;
    };
    qDebug() << Globals::difficulty;
}

//starts the game, disables start button and difficulty slider
void Interface::on_start_button_clicked()
{
    ui->start_button->setEnabled(false);
    ui->difficulty_slider->setEnabled(false);
    ui->progressBar->setEnabled(true);
    //run the simulation
    Globals::simon->run(this);
}

//Passes the simulation to the game loop
void Interface::turn_processing()
{
    //computer turn processing
    if(!Globals::player_turn)
    {
        //this->pattern_flasher();
        //begin computer turn processing logic
        Globals::simon->proc_com_turn(this);
    }
}

//set's progress bar size then iterates through entire pattern and passes each button to index flasher
void Interface::pattern_flasher()
{
    ui->progressBar->setMaximum(Globals::pattern.size());
    //vector<int>::iterator it;
    for (int i = (int)Globals::pattern.size()-1; i >= 0; --i)
    {
        index_flasher(i);
    }
    return;
}

//Flashes an individual button based on given index by changing the background color black
void Interface::index_flasher(int button_idx)
{
    //temporarily change the color for the button referenced
    switch (button_idx)
    {
    case 0: //start at button 2
        ui->pushButton_2->setStyleSheet( QString("background-color: #000000;"));
        ui->pushButton_2->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_2->setStyleSheet( QString("background-color: rgb(200,50,50);"));
        ui->pushButton_2->repaint();
        return;
        break;
    case 1:
        ui->pushButton_3->setStyleSheet( QString("background-color: #000000;"));
        ui->pushButton_3->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_3->setStyleSheet( QString("background-color: rgb(50,50,200)"));
        ui->pushButton_3->repaint();
        return;
        break;
    case 2:
        ui->pushButton_4->setStyleSheet( QString("background-color: rgb(0,0,0);"));
        ui->pushButton_4->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_4->setStyleSheet( QString("background-color: rgb(75,0,150);"));
        ui->pushButton_4->repaint();
        break;
    case 3:
        ui->pushButton_5->setStyleSheet( QString("background-color: rgb(0,0,0);"));
        ui->pushButton_5->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_5->setStyleSheet( QString("background-color: rgb(200,128,0);"));
        ui->pushButton_5->repaint();
        break;
    case 4:
        ui->pushButton_6->setStyleSheet( QString("background-color: rgb(0,0,0);"));
        ui->pushButton_6->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_6->setStyleSheet( QString("background-color: rgb(128,200,0);"));
        ui->pushButton_6->repaint();
        break;
    case 5:
        ui->pushButton_7->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,0);}"));
        ui->pushButton_7->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_7->setStyleSheet( QString("QPushButton {background-color: rgb(200,200,200);}"));
        ui->pushButton_7->repaint();
        break;
    case 6:
        ui->pushButton_8->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,0);}"));
        ui->pushButton_8->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_8->setStyleSheet( QString("QPushButton {background-color: rgb(200,0,200);}"));
        ui->pushButton_3->repaint();
        break;
    case 7:
        ui->pushButton_9->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,0);}"));
        ui->pushButton_9->repaint();
        this->delay(Globals::countdown);
        ui->pushButton_9->setStyleSheet( QString("QPushButton {background-color: rgb(200,200,0);}"));
        ui->pushButton_9->repaint();
        break;
    }//end switch
    return;
}

//restarts the window and resets all global variables except high score
void Interface::reset_game()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

//handles toolbar option for restarting (always enabled)
void Interface::on_actionRestart_triggered()
{
    this->reset_game();
}

//Process Game over
void Interface::show_game_over()
{
    QMessageBox::StandardButton game_over;
    game_over = QMessageBox::question(this, "Game Over", "Game Over, Play Again? ", QMessageBox::Yes | QMessageBox::No);
    if(game_over == QMessageBox::Yes)
    {
        this->reset_game();
    } else
    {
        qApp->quit();
    }
}

//process standard input button pressed
void Interface::pressed(int idx)
{
    if(Globals::player_turn)
    {
        ui->progressBar->setMaximum(Globals::level);
        //check for gameover
        if (Globals::health <  1 )
        {
            this->show_game_over();
        }
        //check to see if player input correct button
        if( Globals::pattern[Globals::player_input_count] == idx )
        {
            if( ui->progressBar->value() < ui->progressBar->maximum()-1 ) //check if button is correct and wait for next input
            {
                Globals::player_input_count++;
                ui->progressBar->setValue(ui->progressBar->value()+1);
            } else // if all buttons correct end player turn
            {
                Globals::level++;
                Globals::player_turn = false;
                Globals::player_input_count = 0;
                ui->progressBar->setValue(ui->progressBar->value()+1);
                Globals::clock.timer->start(500);
                while(Globals::clock.timer->remainingTime()>0){}
                ui->progressBar->setValue(0);
                ui->score->display(Globals::level);
                this->turn_processing();
                this->pattern_flasher();
                Globals::countdown -= 10;// make the clock a little faster each round
            }
        } else //if not G.O. and not correct input play pattern again and have player try again
        {
            Globals::health--;
            Globals::player_turn = false;
            Globals::player_input_count = 0;
            ui->progressBar->setValue(0);
            ui->health->display(Globals::health);
            //this->pattern_flasher();
            Globals::player_turn = true;
            this->pressed(idx);
        }
    }
}

void Interface::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

/*when player presses a button*/
void Interface::on_pushButton_2_clicked()
{
    this->pressed(0);
}

void Interface::on_pushButton_3_clicked()
{
    this->pressed(1);
}


void Interface::on_pushButton_4_clicked()
{
    this->pressed(2);
}


void Interface::on_pushButton_5_clicked()
{
    this->pressed(3);
}


void Interface::on_pushButton_6_clicked()
{
    this->pressed(4);
}


void Interface::on_pushButton_7_clicked()
{
    this->pressed(5);
}


void Interface::on_pushButton_8_clicked()
{
    this->pressed(6);
}


void Interface::on_pushButton_9_clicked()
{
    this->pressed(7);
}

