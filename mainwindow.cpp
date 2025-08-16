#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QColor>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: lightblue;");

    //list of buttons
    QPushButton* buttons[] = {
        ui->pushButton_A, ui->pushButton_B, ui->pushButton_C, ui->pushButton_D,
        ui->pushButton_E, ui->pushButton_F, ui->pushButton_g, ui->pushButton_H,
        ui->pushButton_I, ui->pushButton_J, ui->pushButton_K, ui->pushButton_L,
        ui->pushButton_M, ui->pushButton_N, ui->pushButton_enne, ui->pushButton_O,
        ui->pushButton_P, ui->pushButton_Q, ui->pushButton_R, ui->pushButton_S,
        ui->pushButton_T, ui->pushButton_U, ui->pushButton_V, ui->pushButton_W,
        ui->pushButton_X, ui->pushButton_Y, ui->pushButton_Z
    };

    //unique style for each one
    QString button_style = "background-color: #2F4F4F; color: white;";
    //to change all the buttons
    for (QPushButton* btn : buttons) {
        if (btn) btn->setStyleSheet(button_style);
    }

    setupWordUI();
    // find which button was pressed
        const auto allButtons = ui->centralwidget->findChildren<QPushButton*>();
    const QString keyStyle = "background-color: #2F4F4F; color: white;";

    for (QPushButton* btn : allButtons) { //look in all buttons
        if (!btn) continue;
        if (!btn->objectName().startsWith("pushButton_")) continue; //just the buttons with letters

        btn->setStyleSheet(keyStyle);
        connect(btn, &QPushButton::clicked, this, [this, btn]() { //everytime this button is clicked, write letter
            const QString txt = btn->text().trimmed().toUpper(); //convert to capital letters
            if (txt.isEmpty()) return; //if empty
            btn->setEnabled(false);//disable button
            applyGuess(txt.at(0));
        });
    }
    }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupWordUI()
{
    // container
    auto *container = new QWidget(ui->centralwidget);
    auto *h = new QHBoxLayout(container);
    h->setSpacing(12); //separte boxes by 12
    h->setContentsMargins(0, 0, 0, 0);

    //position of container
    container->setGeometry(QRect(120, 200, 560, 60));

    m_slots.clear();
    m_slots.reserve(m_word.size()); //reserve the lenght of the word

    for (QChar c : m_word) {
        auto *lab = new QLabel(container); //creates box
        lab->setMinimumSize(32, 40); //min size
        lab->setAlignment(Qt::AlignCenter); //aligment

        if (c.isSpace()) { //if word has spaces
            lab->setText(" "); //does not draw lines
            lab->setStyleSheet("border: none;");
        } else { //if letter
            // draw dot line
            lab->setText(""); // begins empty
            lab->setStyleSheet(
                "QLabel {"
                "  border: none;"
                "  border-bottom: 3px dashed #1f3b3b;"
                "  font: bold 20px 'Segoe UI';"
                "  color: #103030;"
                "}"
                );
        }
        h->addWidget(lab); //add box to row
        m_slots.push_back(lab);//store it
    }
}

void MainWindow::applyGuess(QChar letter)
{
    letter = letter.toUpper(); //convert lett to capital letters
    bool hit = false;

    for (int i = 0; i < m_word.size(); ++i) {
        if (!m_word[i].isLetter()) continue; //if is notthe same continue
        if (m_word[i].toUpper() == letter) { //until it matches
            m_slots[i]->setText(QString(letter)); // reveal theletter
            hit = true;
        }
    }



    if (hit && allRevealed()) {
        QMessageBox::information(this, "You win",
                                 "You have guessed the word: " + m_word);

    }
}

//Proves if all the letter boxes have text
bool MainWindow::allRevealed() const
{
    for (int i = 0; i < m_word.size(); ++i) {
        if (m_word[i].isLetter() && m_slots[i]->text().isEmpty())
            return false;
    }
    return true;
}
