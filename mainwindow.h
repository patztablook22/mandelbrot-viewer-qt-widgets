#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

protected:
    bool eventFilter(QObject*, QEvent*);

private:
    Ui::MainWindow *ui;
    QImage qi;
    QGraphicsPixmapItem* qpi;
    QGraphicsScene* scene;

    void render();
    double scale = 1;
    void setScale(double);
};
#endif // MAINWINDOW_H
