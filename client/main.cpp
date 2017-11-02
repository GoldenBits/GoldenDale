#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow();
    window->setFixedSize(800, 600);
    window->show();
    return app.exec();
}
