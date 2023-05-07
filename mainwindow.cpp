
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QFileInfo>
#include <QDir>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function To Determine Which Animation Is Played
QMovie* playAnimation(bool penetrated){
    //Set File Info
    QFileInfo fileInfo;
    //If the shot penetrates set animation equal to that.
    if (penetrated){
        fileInfo = QString("images/Shot_Penetrated.gif");
    //If the shot does not penetrate set the animation equal to that.
    }else{
        fileInfo = QString("images/Shot_Bounced.gif");
    }

    //Get File Name From File Info
    QString fileName = fileInfo.fileName();
    //Get File Path From File Info
    QString path = fileInfo.path();
    //Obtain Relative Path By Getting Directory, Path, and File Name
    QString relativePath = QDir::currentPath() + "/" + path + "/" + fileName;

    //Set Animated Gif By Using Relative Path
    QMovie *movie = new QMovie(relativePath);
    movie->loopCount();

    return movie;
}

void MainWindow::on_pushButton2_clicked(){
    //Signal That PushButton Has Been Called
    ui->label->setText("Shell Penetrated Button Pressed");


    //true means that the animation to penetrate the tank should be played
    QMovie *movie = playAnimation(true);

    //Set Gif Container To Visible
    ui->video->setVisible(true);

    //Assign Gif To Label
    ui->video->setMovie(movie);

    //Play Movie
    movie->start();

    //Show Label
    ui->video->show();

}

void MainWindow::on_pushButton_clicked()
{
    //Signal That PushButton Has Been Called
    ui->label->setText("Shell Bounced Button Pressed");

    //false means that the animation to not penetrate the tank should be played
    QMovie *movie = playAnimation(false);

    //Set Gif Container To Visible
    ui->video->setVisible(true);

    //Assign Gif To Label
    ui->video->setMovie(movie);

    //Play Movie
    movie->start();

    //Show Label
    ui->video->show();

}



void MainWindow::on_video_linkActivated(const QString &link)
{

}

