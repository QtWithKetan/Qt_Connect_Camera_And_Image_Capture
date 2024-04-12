#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtMultimedia>
#include <QtMultimediaWidgets>

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
    void on_pushButton_Start_Camera_clicked();

    void on_pushButton_Stop_Camera_clicked();

    void imageCaptured(int reqid, const QImage &img);

    void on_pushButton_Image_Capture_clicked();

private:
    void start_Camera();
    void stop_Camera();

private:
    Ui::MainWindow *ui;
    QScopedPointer<QCamera> M_Camera;
    QScopedPointer<QCameraImageCapture> M_Camera_Image;
    int Counter = 0;
    QImage ImageFromCamera;
    QMediaPlayer *player;
    QVideoWidget *videowidget;
    QMediaRecorder *recorder;
};

#endif // MAINWINDOW_H
