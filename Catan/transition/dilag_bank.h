
#ifndef DILAG_BANK_H
#define DILAG_BANK_H

#include <QDialog>

namespace Ui {
class Dilag_bank;
}

class Dilag_bank : public QDialog
{
    Q_OBJECT

public:
    explicit Dilag_bank(QWidget *parent = nullptr);
    ~Dilag_bank();

private:
    Ui::Dilag_bank *ui;
};

#endif // DILAG_BANK_H
