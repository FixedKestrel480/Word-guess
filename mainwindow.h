#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QStringList>
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
    QStringList m_wordList; //list of word guess
    Ui::MainWindow *ui;
    QString m_word;        // In capital letter the objective word
    QVector<QLabel*> m_slots;               // visual kaestchen
    QWidget* m_wordContainer =nullptr; //container kaestchen

    void setupWordUI();                     // create the lines
    void applyGuess(QChar letter);          // allocate the letter if it is ther
    bool allRevealed() const;               // is the word finish?
    void newGame(); //start new game
};
#endif // MAINWINDOW_H
