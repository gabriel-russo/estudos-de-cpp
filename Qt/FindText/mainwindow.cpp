#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->searchBarButton, &QPushButton::clicked, this, &MainWindow::findText);

    this->loadTextFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTextFile()
{

    QFile textFile(":/text.txt");

    textFile.open(QIODevice::ReadOnly);

    QTextStream text(&textFile);

    QString line = text.readAll();

    textFile.close();

    ui->sourceTextField->setPlainText(line);

}

void MainWindow::findText()
{
    QString keyword = ui->searchBarInput->text();

    bool keywordExists = ui->sourceTextField->find(keyword, QTextDocument::FindWholeWords);

    if(keywordExists)
    {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::green);
        ui->searchBarInput->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::darkRed);
        ui->searchBarInput->setPalette(palette);
    }

}