#ifndef TELA_PRINCIPAL_H
#define TELA_PRINCIPAL_H

#include <QMainWindow>
#include<QTimer>
#include <windows.h>
#include<QMessageBox>
#include <QPixmap>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class Tela_principal;
}

class Tela_principal : public QMainWindow{
    Q_OBJECT

public:
    explicit Tela_principal(QWidget *parent = nullptr);
    ~Tela_principal();   
    void friend passa_est();
    void friend volta_est();

private slots:
    void on_Iniciar_clicked();

    void on_Info_soft_clicked();

    void on_Audio_clicked();

    void on_Configuraes_clicked();

    void on_Informacoes_clicked();

    void on_Waring_clicked();

    void on_Travas_clicked();

    void on_Voltar_audio_clicked();

    void on_pushButton_clicked();

    void on_Voltar_info_clicked();

    void on_passar_sit_travas_clicked();

    void on_Voltar_sit_travas_clicked();

    void on_Voltar_config_clicked();

    void on_voltar_conf_vel_clicked();

    void on_passar_conf_vel_clicked();

    void nivel_bat();

    void nivel_agua();

    void nivel_oleo();

    void on_sair_clicked();

    void on_passar_est_clicked();

    void on_voltar_est_clicked();


    void on_siminui_vol_clicked();

    void on_aumenta_vol_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_vidros_clicked();

    void on_capo_clicked();

    void on_portas_dian_clicked();

    void on_portas_tras_clicked();

    void on_mala_clicked();

    void on_liga_ar_clicked();

    void on_desliga_ar_clicked();

    void on_altera_temp_clicked();

    void on_modo_via_clicked();

    void on_pil_auto_clicked();

    void beep_seguranca();

    void data_hora();
private:

    int click=0;
    QString consumo="";
    QString estacao_atual="";
    QString temperatura="";
    QString ar="";
    QString modo_v="";
    Ui::Tela_principal *ui;
    QTimer *Tempo;
    QTimer *Tempo2;
    QTimer *Tempo3;
    QTimer *Tempo4;
    QTimer *Tempo5;

    int t;
    int t1;
    int t2;
    //AUDIO *Radio;
};
struct AUDIO{

    int n;
    QString estacao[5];
    int volume;

   AUDIO();
   void  passa_est();
   void  volta_est();


};
struct TRAVA{

    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
    TRAVA();



};

struct VELOCIDADE{

    int cont_mv;
    int cont_pa;
    VELOCIDADE();

};

#endif // TELA_PRINCIPAL_H
