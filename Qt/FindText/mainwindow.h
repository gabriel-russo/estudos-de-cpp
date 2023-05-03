#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QPalette>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void findText();

private:
    Ui::MainWindow *ui;
    void loadTextFile();

};

#endif // MAINWINDOW_H
