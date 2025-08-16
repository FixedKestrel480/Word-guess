#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString m_word = "PROGRAMACION";        // In capital letter the objective word
    QVector<QLabel*> m_slots;               // visual kaestchen

    void setupWordUI();                     // create the lines
    void applyGuess(QChar letter);          // allocate the letter if it is ther
    bool allRevealed() const;               // is the word finish?
};
#endif // MAINWINDOW_H
