#include "tela_principal.h"
#include "ui_tela_principal.h"

static QString local = "C:/Users/joaov/OneDrive/Documentos/João/Programação - C++/Projeto_tp_prog";
static QString nome = "arquivo.txt";
static QFile arquivo(local + nome);
static QTextStream entrada(&arquivo);
static AUDIO Radio;
static TRAVA Travas;
static VELOCIDADE Vel;


Tela_principal::Tela_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tela_principal)
{

    ui->setupUi(this);
    // Abrindo arquivo
    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"ERRO","Erro ao abrir o arquivo");
    }

    Tempo= new QTimer(this);
    connect(Tempo, SIGNAL(timeout()), this,SLOT(nivel_bat()));
    Tempo->start(180000);

    Tempo2= new QTimer(this);
    connect(Tempo2, SIGNAL(timeout()), this,SLOT(beep_seguranca()));
    Tempo2->start(20000);

    Tempo3= new QTimer(this);
    connect(Tempo3, SIGNAL(timeout()), this,SLOT(data_hora()));
    Tempo3->start(1000);

    Tempo4= new QTimer(this);
    connect(Tempo4, SIGNAL(timeout()), this,SLOT(nivel_agua()));
    Tempo4->start(120000);

    Tempo5= new QTimer(this);
    connect(Tempo5, SIGNAL(timeout()), this,SLOT(nivel_oleo()));
    Tempo5->start(150000);

    t=0;
    t1=0;
    t2=0;

    consumo="Consumo padrão: 9Km/L.";
    ar="Desligado";
    estacao_atual="     93.1 FM";
    modo_v="Off";
    temperatura="27 °C";

    ui->nome_est->setText(estacao_atual);

    QPixmap icone(":/Projeto_design/green_circle.png");
    ui->trv_vidro->setPixmap(icone);
    ui->info_t_vidros->setPixmap(icone);
    ui->trv_capo->setPixmap(icone);
    ui->info_t_capo->setPixmap(icone);
    ui->trv_p_diant->setPixmap(icone);
    ui->info_t_p_dia->setPixmap(icone);
    ui->trv_p_tras->setPixmap(icone);
    ui->info_t_p_tras->setPixmap(icone);
    ui->trv_mala->setPixmap(icone);
    ui->info_t_mala->setPixmap(icone);

    QPixmap icone1(":/Projeto_design/pause.png");
    ui->radio_sit->setPixmap(icone1);

    QPixmap icone2(":/Projeto_design/red_circle_icon.png");
    ui->pil_auto_icon->setPixmap(icone2);
    ui->modo_v_icon->setPixmap(icone2);

    QPixmap fnd1(":/Projeto_design/Fnd1.png");
    ui->fundo1->setPixmap(fnd1);
    QPixmap fnd2(":/Projeto_design/Fundo2.png");
    ui->fundo2->setPixmap(fnd2);
    QPixmap fnd3(":/Projeto_design/Fundo3.png");
    ui->fundo3->setPixmap(fnd3);
    QPixmap fnd4(":/Projeto_design/Fundo4.png");
    ui->fundo4->setPixmap(fnd4);
    QPixmap fnd5(":/Projeto_design/Fundo5.png");
    ui->fundo5->setPixmap(fnd5);
    QPixmap fnd6(":/Projeto_design/Fundo6.png");
    ui->fundo6->setPixmap(fnd6);
    QPixmap fnd7(":/Projeto_design/F7.png");
    ui->F7->setPixmap(fnd7);
    QPixmap fnd8(":/Projeto_design/Fnd8.png");
    ui->Fundo8->setPixmap(fnd8);


}

Tela_principal::~Tela_principal()
{
    delete ui;
}

void Tela_principal::on_Iniciar_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(1);
}

void Tela_principal::on_Info_soft_clicked()
{

    click++;
    Beep(450,500);
    QMessageBox::about(this, "Informações", "Versão 1.0\n Criado por Eduardo Luis, João Moura,\nJosias Abraão e Matheus Bezerra.");

}

void Tela_principal::on_Audio_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(2);

}

void Tela_principal::on_Configuraes_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(6);

}

void Tela_principal::on_Informacoes_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(4);

}

void Tela_principal::on_Waring_clicked()
{

    click++;
    Beep(450,500);
    QMessageBox::warning(this, "Consumo", consumo);

}

void Tela_principal::on_Travas_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(3);

}

void Tela_principal::on_Voltar_audio_clicked()
{
    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(1);

}

void Tela_principal::on_pushButton_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(1);

}

void Tela_principal::on_Voltar_info_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(1);

}

void Tela_principal::on_passar_sit_travas_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(5);

}

void Tela_principal::on_Voltar_sit_travas_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(4);

}

void Tela_principal::on_Voltar_config_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(1);

}

void Tela_principal::on_voltar_conf_vel_clicked()
{

    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(6);
}

void Tela_principal::on_passar_conf_vel_clicked()
{
    click++;
    Beep(450,500);
    ui->stackedWidget->setCurrentIndex(7);

}

void Tela_principal::nivel_bat()
{
    t++;

    int carga=100-t;
    int valor=100-t;

    ui->Carga->setValue(carga);
    ui->nivel_bat->display(valor);

    if(carga==15){
        Beep(400,1000);
        QMessageBox::warning(this, "Bateria do aparelho está baixa", "Aparelho com pouca carga restante, conecte-o ao carregador.");
    }else if(carga==5){
        Beep(400,1000);
        QMessageBox::warning(this, "Pouquíssima carga", "Aparelho descarregando, conecte-o ao carregador com urgência.");
    }else if(carga==0){
        Beep(400,1000);
        QMessageBox::critical(this, "Sem carga", "Aparelho descarregado, sistema encerrando.");
        close();
    }


    if(valor<=15)
        ui->nivel_bat->setStyleSheet("color:#f00");


}
void Tela_principal::nivel_agua(){

    t1++;
    int agua=100-(t1);


    ui->nivel_agua->display(agua);

    if(agua<=75)
        ui->nivel_agua->setStyleSheet("color:#f00");

    if(agua==50){
       QMessageBox::critical(this, "Nível de água", "Nível de água muito baixo, possibilidade de vazamento.");
    }
    if(agua==0){
       QMessageBox::critical(this, "Motor", "Superaquecimento do motor. Sistema encerrando.");
       on_sair_clicked();
    }
}
void Tela_principal::nivel_oleo(){

    t2++;
    int oleo=100-t2;

    ui->nivel_oleo->display(oleo);


    if(oleo<=75)
        ui->nivel_oleo->setStyleSheet("color:#f00");

    if(oleo==50){
       QMessageBox::critical(this, "Nível de óleo", "Nível de óleo muito baixo, possibilidade de vazamento.");
    }
    if(oleo==0){
       QMessageBox::critical(this, "Motor", "Nível de óleo no mínimo. Sistema encerrando.");
       on_sair_clicked();
    }

}
void Tela_principal::beep_seguranca(){

    if(modo_v=="On"){
        Beep(800,600);
    }
}

void Tela_principal::data_hora(){

    QTime hora=QTime::currentTime();
    QString hora_atual = hora.toString("hh:mm:ss");
    ui->hora_princ->setText(hora_atual);
    ui->hora_audio->setText(hora_atual);
    ui->hora_travas->setText(hora_atual);
    ui->hora_info_niv->setText(hora_atual);
    ui->hora_info_trv->setText(hora_atual);
    ui->hora_conf_ar->setText(hora_atual);
    ui->hora_conf_vel->setText(hora_atual);

    QDate data = QDate::currentDate();
    QString data_atual = data.toString("dd/MM/yy");
    ui->data_princ->setText(data_atual);
    ui->data_audio->setText(data_atual);
    ui->data_travas->setText(data_atual);
    ui->data_info_niv->setText(data_atual);
    ui->data_info_trv->setText(data_atual);
    ui->data_conf_ar->setText(data_atual);
    ui->data_conf_vel->setText(data_atual);
}

void Tela_principal::on_sair_clicked()
{
    entrada << "Modo Viagem: "<< modo_v << endl;
    entrada << "Temperatura: "<<temperatura<<" °C" <<endl;
    entrada<<  "Ar:" << ar <<endl;
    entrada<<"Estacao:" <<estacao_atual <<endl;
    entrada<<"Consumo: "<<consumo<<endl;
    close();

}

AUDIO::AUDIO(){

    estacao[0]="     93.1 FM";
    estacao[1]="     97.3 FM";
    estacao[2]="     98.1 FM";
    estacao[3]="     101.1 FM";
    estacao[4]="    103.5 FM";
    n=0;
    volume=0;
}
void passa_est(){

   Radio.n+=1;
   if(Radio.n==5){
     Radio.n=0;
   }
}

void volta_est(){

   Radio.n-=1;
   if(Radio.n==-1){
     Radio.n=4;
   }
}


void Tela_principal::on_passar_est_clicked()
{
    click++;
    estacao_atual="";
    Beep(450,500);
    passa_est();
    estacao_atual=Radio.estacao[Radio.n];
    ui->nome_est->setText(Radio.estacao[Radio.n]);
}


void Tela_principal::on_voltar_est_clicked()
{   click++;
    estacao_atual="";
    Beep(450,500);
    volta_est();
    estacao_atual=Radio.estacao[Radio.n];
    ui->nome_est->setText(Radio.estacao[Radio.n]);
}



void Tela_principal::on_siminui_vol_clicked()
{
    click++;
    Beep(450,500);
    if(Radio.volume==0){

        QMessageBox::warning(this, "Volume", "O volume já está no mínimo possível.");
    }else{

        Radio.volume--;
        ui->tela_volume->display(Radio.volume);
    }
}

void Tela_principal::on_aumenta_vol_clicked()
{
    click++;
    Beep(450,500);
    if(Radio.volume==30){

        QMessageBox::warning(this, "Volume", "O volume já está no máximo possível.");
    }else{

        Radio.volume++;
        ui->tela_volume->display(Radio.volume);
    }
}

void Tela_principal::on_play_clicked()
{
    click++;
    Beep(450,500);
    QPixmap icone(":/Projeto_design/play.png");
    ui->radio_sit->setPixmap(icone);
}

void Tela_principal::on_pause_clicked()
{
    click++;
    Beep(450,500);
    QPixmap icone(":/Projeto_design/pause.png");
    ui->radio_sit->setPixmap(icone);
}
TRAVA::TRAVA(){

    t1=0;
    t2=0;
    t3=0;
    t4=0;
    t5=0;

};
void Tela_principal::on_vidros_clicked()
{
    click++;
    Beep(450,500);
    if(Travas.t1%2==0){
        QPixmap icone(":/Projeto_design/red_circle_icon.png");
        ui->trv_vidro->setPixmap(icone);
        ui->info_t_vidros->setPixmap(icone);
    }else{
        QPixmap icone(":/Projeto_design/green_circle.png");
        ui->trv_vidro->setPixmap(icone);
        ui->info_t_vidros->setPixmap(icone);
    }
    Travas.t1++;
}

void Tela_principal::on_capo_clicked()
{
    click++;
    Beep(450,500);
    if(Travas.t2%2==0){
        QPixmap icone(":/Projeto_design/red_circle_icon.png");
        ui->trv_capo->setPixmap(icone);
        ui->info_t_capo->setPixmap(icone);
    }else{
        QPixmap icone(":/Projeto_design/green_circle.png");
        ui->trv_capo->setPixmap(icone);
        ui->info_t_capo->setPixmap(icone);
    }
    Travas.t2++;
}

void Tela_principal::on_portas_dian_clicked()
{
    click++;
    Beep(450,500);
    if(Travas.t3%2==0){
        QPixmap icone(":/Projeto_design/red_circle_icon.png");
        ui->trv_p_diant->setPixmap(icone);
        ui->info_t_p_dia->setPixmap(icone);
    }else{
        QPixmap icone(":/Projeto_design/green_circle.png");
        ui->trv_p_diant->setPixmap(icone);
        ui->info_t_p_dia->setPixmap(icone);
    }
    Travas.t3++;
}

void Tela_principal::on_portas_tras_clicked()
{
    click++;
    Beep(450,500);
    if(Travas.t4%2==0){
        QPixmap icone(":/Projeto_design/red_circle_icon.png");
        ui->trv_p_tras->setPixmap(icone);
        ui->info_t_p_tras->setPixmap(icone);
    }else{
        QPixmap icone(":/Projeto_design/green_circle.png");
        ui->trv_p_tras->setPixmap(icone);
        ui->info_t_p_tras->setPixmap(icone);
    }
    Travas.t4++;
}

void Tela_principal::on_mala_clicked()
{
    click++;
    Beep(450,500);
    if(Travas.t5%2==0){
        QPixmap icone(":/Projeto_design/red_circle_icon.png");
        ui->trv_mala->setPixmap(icone);
        ui->info_t_mala->setPixmap(icone);
    }else{
        QPixmap icone(":/Projeto_design/green_circle.png");
        ui->trv_mala->setPixmap(icone);
        ui->info_t_mala->setPixmap(icone);
    }
    Travas.t5++;
}

void Tela_principal::on_liga_ar_clicked()
{
    click++;
    Beep(450,500);
    if(ar=="Desligado"){
        ar="";
        QMessageBox::warning(this, "Alerta","Ligar o ar condicionado aumentará o consumo.");
        consumo="Consumo com o ar ligado: 7,5km/L.";
        ar="Ligado";
    }
    else{
        QMessageBox::warning(this, "Alerta","O ar já está ligado.");
        }
}


void Tela_principal::on_desliga_ar_clicked()
{
    click++;
    Beep(450,500);
    if(ar=="Ligado"){

        ar="";
        consumo="";
        temperatura="";

        QMessageBox::warning(this, "Alerta","O ar condicionado foi desligado. Temperatura reajustada para padrão: 27 °C.");

        temperatura="27 °C";
        consumo="Consumo padrão: 9km/L.";
        ar="Desligado";

        ui->exibe_temp_conf->setText(temperatura+" °C");
        ui->exibe_temp_princ->setText(temperatura+" °C");
        ui->exibe_temp_trav->setText(temperatura+" °C");
        ui->exibe_temp_audio->setText(temperatura+" °C");
        ui->exib_temp_info_niv->setText(temperatura+" °C");
        ui->exibe_temp_inf_trv->setText(temperatura+" °C");
        ui->exibe_temp_vel->setText(temperatura+" °C");

    }
    else
        QMessageBox::warning(this, "Alerta","O ar já está desligado.");

}




void Tela_principal::on_altera_temp_clicked()
{
    click++;
    Beep(450,500);
    int temp= ui->edit_temp->text().toInt();
    if(ar=="Ligado"){
        if(temp<=32&&temp>=15){

            temperatura="";
            temperatura=ui->edit_temp->text();

            ui->exibe_temp_conf->setText(temperatura+" °C");
            ui->exibe_temp_princ->setText(temperatura+" °C");
            ui->exibe_temp_trav->setText(temperatura+" °C");
            ui->exibe_temp_audio->setText(temperatura+" °C");
            ui->exib_temp_info_niv->setText(temperatura+" °C");
            ui->exibe_temp_inf_trv->setText(temperatura+" °C");
            ui->exibe_temp_vel->setText(temperatura+" °C");

        }else
            QMessageBox::information(this, "Temperatura", "Não é possível inserir uma temperatura superior a 32 ºC ou inferior a 15 °C.");
    }else{
        QMessageBox::warning(this, "Temperatura", "Não é possível alterar a temperatura com o ar condicionado desligado.");

    }
}
VELOCIDADE::VELOCIDADE(){

    cont_mv=0;
    cont_pa=0;
}
void Tela_principal::on_modo_via_clicked()
{
    click++;
    modo_v="";
    Beep(450,500);
    if(Vel.cont_mv%2==0){

        modo_v="On";
        temperatura="25 °C";

        QPixmap icon(":/Projeto_design/green_circle.png");
        ui->modo_v_icon->setPixmap(icon);

        ui->exibe_temp_conf->setText(temperatura+" °C");
        ui->exibe_temp_princ->setText(temperatura+" °C");
        ui->exibe_temp_trav->setText(temperatura+" °C");
        ui->exibe_temp_audio->setText(temperatura+" °C");
        ui->exib_temp_info_niv->setText(temperatura+" °C");
        ui->exibe_temp_inf_trv->setText(temperatura+" °C");
        ui->exibe_temp_vel->setText(temperatura+" °C");

        on_liga_ar_clicked();
    }
    else{

        modo_v="Off";
        QPixmap icon(":/Projeto_design/red_circle_icon.png");
        ui->modo_v_icon->setPixmap(icon);
        int opc=QMessageBox::question(this, "Ar condicionado", "Deseja desligar o arcondicionado?", "Sim", "Não");
        if(opc==0)
            on_desliga_ar_clicked();

    }

    Vel.cont_mv++;
}

void Tela_principal::on_pil_auto_clicked()
{
    click++;
    Beep(450,500);
    if(Vel.cont_pa%2==0){
        QPixmap icon(":/Projeto_design/green_circle.png");
        ui->pil_auto_icon->setPixmap(icon);
        ui->velocimetro->setText("80 KM/H");
        ui->RPM->setText("2500");
    }
    else{
        QPixmap icon(":/Projeto_design/red_circle_icon.png");
        ui->pil_auto_icon->setPixmap(icon);
        ui->velocimetro->setText("   - X -");
        ui->RPM->setText("- X -");
    }
    Vel.cont_pa++;
}
