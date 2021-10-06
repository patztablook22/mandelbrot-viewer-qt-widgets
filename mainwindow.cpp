#include "mainwindow.h"
#include "mandelbrot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene(this);
    // QGraphicsView* v = ui->graphicsView;
    qi = QImage(500, 500, QImage::Format_RGB888);
    qpi = scene->addPixmap(QPixmap::fromImage(qi));
    ui->graphicsView->setScene(scene);
    ui->centralwidget->installEventFilter(this);
    render();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* key = (QKeyEvent*) event;
        switch (key->key()) {
        case '=':
            // scale up
            setScale(scale + 0.1);
            break;
        case '-':
            // scale down
            setScale(scale - 0.1);
            break;
        }
        return true;
    }
    return false;
}


void MainWindow::render() {
    ui->label->setText(
                QStringLiteral("scale = %1").arg(scale)
    );
    for (int col = 0; col < qi.width(); col++) {
        for (int row = 0; row < qi.height(); row++) {
            // this will be costly a.f., there will be a better way of doing it
            int threshold = 14 * scale;
            if (threshold > 30)
                threshold = 30;
            int m = mandelbrot(
                        (Scalar)(col - qi.width()  / 2  ) / 100 / scale,
                        (Scalar)(row - qi.height() / 2 ) / 100  / scale,
                        threshold
            );
            qi.setPixelColor(
                        col, row,
                        qRgb(m, m, m)

            );
        }
    }
    qpi->setPixmap(QPixmap::fromImage(qi));
}

void MainWindow::setScale(double s) {
    if (s <= 0.1)
        s = 0.1;
    scale = s;
    render();
}
