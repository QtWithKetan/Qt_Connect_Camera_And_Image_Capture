#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (const QCameraInfo &infor : QCameraInfo::availableCameras())
    {
        qDebug() << infor.description();
    }

    M_Camera.reset(new QCamera(QCameraInfo::defaultCamera()));

    M_Camera->setViewfinder(ui->widget_Camera_View);

    M_Camera_Image.reset(new QCameraImageCapture(M_Camera.data()));
    M_Camera_Image->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    connect(M_Camera_Image.data(), &QCameraImageCapture::imageCaptured, this, &MainWindow::imageCaptured);

    player = new QMediaPlayer(this);//3
    videowidget = new QVideoWidget;//4
    player->setVideoOutput(videowidget);
    recorder = new QMediaRecorder(M_Camera.data(),this);//5
    auto&& settings = recorder->videoSettings();//6
    settings.setResolution(ui->widget_Camera_View->size());
    settings.setQuality(QMultimedia::VeryHighQuality);
    settings.setFrameRate(30.0);
    recorder->setVideoSettings(settings);
    M_Camera->setCaptureMode(QCamera::CaptureVideo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_Camera()
{
    M_Camera->start();
}

void MainWindow::stop_Camera()
{
    M_Camera->stop();
}

void MainWindow::on_pushButton_Start_Camera_clicked()
{
    start_Camera();

    QString name = QCoreApplication::applicationDirPath() + "/Testing.mp4";
    recorder->setOutputLocation(QUrl::fromLocalFile(name));
    recorder->record();//4
}

void MainWindow::on_pushButton_Stop_Camera_clicked()
{
    recorder->stop();
    player->stop();

    stop_Camera();
}

void MainWindow::imageCaptured(int reqid, const QImage &img)
{
    Q_UNUSED(reqid);
    ImageFromCamera = img.scaled(ui->widget_Camera_View->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    Counter = Counter + 1;
    QString ImagePath = QCoreApplication::applicationDirPath() + "/Image_"+ QString::number(Counter) + ".bmp";
    QPixmap::fromImage(ImageFromCamera).save(ImagePath);
}

void MainWindow::on_pushButton_Image_Capture_clicked()
{
    M_Camera_Image->capture();
}
