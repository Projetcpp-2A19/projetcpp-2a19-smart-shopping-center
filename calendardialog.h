#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>
#include <QCalendarWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSplitter>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QTextCharFormat>
#include <QMessageBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QDialogButtonBox>
#include <QComboBox>  // Added for QComboBox
#include <QGroupBox>  // Added for QGroupBox
#include <QValidator> // Added for QIntValidator and QDoubleValidator

struct CalendarEvent
{
    QString identifiant;
    QString nom;
    QString type;
    QDateTime dateDebut;
    QDateTime dateFin;
    QString lieu;
    QString capacite;
    QString prix;
    QString idLocataire;
};

class CalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarDialog(QWidget *parent = nullptr);
    ~CalendarDialog();

private slots:
    void onCalendarClicked(const QDate &date);
    void onAddEventClicked();
    void onModifyEventClicked();
    void onDeleteEventClicked();
    void onEventDoubleClicked(const QModelIndex &index);
    void refreshCalendar();

private:
    QCalendarWidget *calendarWidget;
    QTableView *eventsTableView;
    QStandardItemModel *eventsModel;
    QPushButton *addEventButton;
    QPushButton *modifyEventButton;
    QPushButton *deleteEventButton;
    QPushButton *closeButton;

    QList<CalendarEvent> getAllEvents();
    QList<CalendarEvent> getEventsByDate(const QDate &date);
    void highlightEventDates();
    void showEventDetails(const QModelIndex &index);
    void setupEventDialog(QDialog *dialog, CalendarEvent *event = nullptr);
    void fillLocatairesComboBox(QComboBox *comboBox); // Nouvelle méthode auxiliaire
};

#endif // CALENDARDIALOG_H
