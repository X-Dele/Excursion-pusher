#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>


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


void MainWindow::on_pushButton_clicked()
{
    system("ffmpeg -thread_queue_size 128 -f x11grab -video_size 1366x768 -framerate 30 -i :0.0 -f video4linux2 -video_size 400x300 -framerate 30 -i /dev/video0 -f alsa -ac 2  -i pulse -filter_complex '[0:v][1:v]overlay=x=main_w-overlay_w-10:y=main_h-overlay_h-10[out]' -map '[out]' -map 2:a  -vcodec libx264 -vprofile baseline -acodec aac -strict -2 -maxrate 3000k -b:a 128k -f flv rtmp://192.168.43.250:1935/live/1");
}

