#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "threadControl.h"
#include "qcustomplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum tipoOnda { degrau, senoidal, quadrada, serra, aleatorio };
    threadControl *theThread;
    void setupPlot1(QCustomPlot *customPlot);
    void setupPlot2(QCustomPlot *customPlot2);
    void updatePlot1(double timeStamp, double redPlot, double bluePlot);
    void updatePlot2(double timeStamp, double redPlot, double bluePlot, double greenPlot, double orangePlot);



public slots:

     void onPlotValues(double timeStamp, double sinalCalculado, double sinalSaturado, double nivelTanque1, double nivelTanque2, double setPoint, double erro);

private slots:

    void on_tempo_valueChanged(double arg1);

    void on_amplitude_valueChanged(double arg1);

    void on_offset_valueChanged(double arg1);

    void on_duracao_max_valueChanged(double arg1);
    void on_duracao_min_valueChanged(double arg1);

    void on_basico_nivel1_valueChanged(double arg1);
    void on_basico_slider1_valueChanged(int value);

    void on_basico_nivel2_valueChanged(double arg1);
    void on_basico_slider2_valueChanged(int value);

    void on_conectar_clicked(bool checked);

    void on_atualizar_clicked();

    void on_tempo_Hz_s_currentIndexChanged(int index);

    void on_sinal_dregrau_clicked();
    void on_sinal_quadrada_clicked();
    void on_sinal_senoidal_clicked();
    void on_sinal_serra_clicked();
    void on_sinal_aleatorio_clicked();

    void on_zerar_clicked();

    void on_pushButton_default_clicked();


    void on_malhaAberta_clicked(bool checked);
    void on_malhaFechada_clicked(bool checked);

    void setTickStep();
    void on_verticalSlider_escalaY_valueChanged(int value);
    void on_spinBox_escalaY_valueChanged(int arg1);
    void on_spinBox_escalaX_valueChanged(int arg1);
    void on_horizontalSlider_escalaX_valueChanged(int value);
private:
    Ui::MainWindow *ui;
    QString demoName;
    QTimer dataTimer;

    bool malhaFechada; // malha aberta ou fechada
    bool segundoOuFrequencia; // true = s ; false= hz
    bool conectado;
    bool plot1Enable[2], plot2Enable[4];

    int tipoOnda;//selecionador de tipo de onda
    int proxtipoOnda;
    int plotRangeX, plotRangeY;

    double basicoNivel1; // nivel tanque 1
    double basicoNivel2; // nivel tanque 2
    double leituraTanque1;
    double leituraTanque2;
    double tempo; // sempre convertido para hz em atualizar
    double amplitude;
    double offset;
    double duracaoMax;
    double duracaoMin;
    double sinalCalculado, sinalSaturado;
    double erro;
    double lastTimeStamp, timeToNextRandomNumber; // medidas de tempo
    double lastLoopTimeStamp; // medidas de tempo

};

#endif // MAINWINDOW_H
