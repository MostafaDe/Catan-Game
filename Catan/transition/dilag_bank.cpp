#include "dilag_bank.h"
#include "ui_dilag_bank.h"

Dilag_bank::Dilag_bank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dilag_bank)
{
    ui->setupUi(this);
}

Dilag_bank::~Dilag_bank()
{
    delete ui;
}
