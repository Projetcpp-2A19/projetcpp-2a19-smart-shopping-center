#include "calendardialog.h"
#include <QHeaderView> // Add this include for QHeaderView

CalendarDialog::CalendarDialog(QWidget *parent):QDialog(parent)
{   setWindowTitle("Calendrier des événements");
    setMinimumSize(900, 600);

    // Création des widgets
    calendarWidget = new QCalendarWidget(this);
    eventsTableView = new QTableView(this);
    eventsModel = new QStandardItemModel(this);

    // Configuration du modèle pour la TableView
    QStringList headers = {"Identifiant", "Nom", "Type", "Date début", "Date fin", "Lieu", "Capacité", "Prix"};
    eventsModel->setHorizontalHeaderLabels(headers);
    eventsTableView->setModel(eventsModel);
    eventsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    eventsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    eventsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    eventsTableView->verticalHeader()->setVisible(false);
    eventsTableView->setAlternatingRowColors(true);

    // Création des boutons
    addEventButton = new QPushButton("Ajouter", this);
    modifyEventButton = new QPushButton("Modifier", this);
    deleteEventButton = new QPushButton("Supprimer", this);
    closeButton = new QPushButton("Fermer", this);

    // Définir les objectNames pour les styles spécifiques
    closeButton->setObjectName("closeButton");
    addEventButton->setObjectName("addEventButton");
    modifyEventButton->setObjectName("modifyEventButton");
    deleteEventButton->setObjectName("deleteEventButton");

    // Configuration des layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QSplitter *splitter = new QSplitter(Qt::Horizontal);

    QWidget *calendarContainer = new QWidget;
    calendarContainer->setObjectName("calendarContainer");
    QVBoxLayout *calendarLayout = new QVBoxLayout(calendarContainer);
    QLabel *calendarTitle = new QLabel("<h2>Calendrier des événements</h2>");
    calendarTitle->setObjectName("sectionTitle");
    calendarLayout->addWidget(calendarTitle);
    calendarLayout->addWidget(calendarWidget);

    QWidget *eventContainer = new QWidget;
    eventContainer->setObjectName("eventContainer");
    QVBoxLayout *eventLayout = new QVBoxLayout(eventContainer);
    QLabel *eventTitle = new QLabel("<h2>Détails des événements</h2>");
    eventTitle->setObjectName("sectionTitle");
    eventLayout->addWidget(eventTitle);
    eventLayout->addWidget(eventsTableView);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addEventButton);
    buttonLayout->addWidget(modifyEventButton);
    buttonLayout->addWidget(deleteEventButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);

    eventLayout->addLayout(buttonLayout);

    splitter->addWidget(calendarContainer);
    splitter->addWidget(eventContainer);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 2);

    mainLayout->addWidget(splitter);

    // Connexion des signaux et slots
    connect(calendarWidget, &QCalendarWidget::clicked, this, &CalendarDialog::onCalendarClicked);
    connect(addEventButton, &QPushButton::clicked, this, &CalendarDialog::onAddEventClicked);
    connect(modifyEventButton, &QPushButton::clicked, this, &CalendarDialog::onModifyEventClicked);
    connect(deleteEventButton, &QPushButton::clicked, this, &CalendarDialog::onDeleteEventClicked);
    connect(eventsTableView, &QTableView::doubleClicked, this, &CalendarDialog::onEventDoubleClicked);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    // Style moderne amélioré
    QString styleSheet = R"(
        /* Style général de la boîte de dialogue */
        QDialog {
            background-color: #f5f7fa;
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        /* Titres de section */
        QLabel#sectionTitle {
            color: #2c3e50;
            font-size: 16px;
            font-weight: bold;
            padding: 5px;
            border-bottom: 1px solid #e0e0e0;
            margin-bottom: 10px;
        }

        /* Conteneurs */
        QWidget#calendarContainer, QWidget#eventContainer {
            background-color: white;
            border-radius: 8px;
            border: 1px solid #e0e0e0;
            padding: 10px;
        }

        /* Style du calendrier */
        QCalendarWidget {
            background-color: white;
            border-radius: 8px;
            selection-background-color: #3498db;
            selection-color: white;
        }

        QCalendarWidget QToolButton {
            height: 36px;
            color: #2c3e50;
            background-color: white;
            border: none;
            font-weight: bold;
            border-radius: 4px;
        }

        QCalendarWidget QToolButton:hover {
            background-color: #ecf0f1;
        }

        QCalendarWidget QToolButton:pressed {
            background-color: #bdc3c7;
        }

        QCalendarWidget QWidget#qt_calendar_navigationbar {
            background-color: #f8f9fa;
            border-top-left-radius: 8px;
            border-top-right-radius: 8px;
            padding: 4px;
            border-bottom: 1px solid #e0e0e0;
        }

        QCalendarWidget QAbstractItemView {
            selection-background-color: #3498db;
            selection-color: white;
        }

        QCalendarWidget QAbstractItemView:enabled {
            color: #2c3e50;
            background-color: white;
            font-size: 12px;
        }

        QCalendarWidget QMenu {
            background-color: white;
            border: 1px solid #d0d0d0;
            border-radius: 4px;
            padding: 2px;
        }

        QCalendarWidget QSpinBox {
            height: 30px;
            background-color: white;
            border: 1px solid #d0d0d0;
            border-radius: 4px;
            padding: 2px;
            selection-background-color: #3498db;
            selection-color: white;
        }

        /* Style amélioré du tableau */
        QTableView {
            border: 1px solid #e0e0e0;
            border-radius: 6px;
            selection-background-color: #3498db;
            selection-color: white;
            gridline-color: #ecf0f1;
            alternate-background-color: #f9f9f9;
            padding: 5px;
        }

        QTableView::item {
            padding: 6px;
            border-bottom: 1px solid #ecf0f1;
        }

        QTableView::item:selected {
            background-color: #3498db;
            color: white;
        }

        QHeaderView::section {
            background-color: #3498db;
            color: white;
            font-weight: bold;
            padding: 8px;
            border: none;
            border-right: 1px solid #2980b9;
        }

        QHeaderView::section:first {
            border-top-left-radius: 6px;
        }

        QHeaderView::section:last {
            border-top-right-radius: 6px;
            border-right: none;
        }

        /* Style des boutons */
        QPushButton {
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
            min-width: 100px;
            color: white;
        }

        QPushButton:hover {
            opacity: 0.9;
        }

        QPushButton:pressed {
            opacity: 0.7;
        }

        QPushButton#addEventButton {
            background-color: #2ecc71;
        }

        QPushButton#modifyEventButton {
            background-color: #3498db;
        }

        QPushButton#deleteEventButton {
            background-color: #e74c3c;
        }

        QPushButton#closeButton {
            background-color: #95a5a6;
        }

        /* Style du splitter */
        QSplitter::handle {
            background-color: #e0e0e0;
            width: 2px;
        }

        QSplitter::handle:hover {
            background-color: #3498db;
        }

        /* Style des informations sous le calendrier */
        QLabel[noEvents="true"] {
            color: #95a5a6;
            font-style: italic;
            text-align: center;
            padding: 20px;
        }
    )";

    setStyleSheet(styleSheet);

    // Initialisation des événements sur le calendrier
    refreshCalendar();
}

CalendarDialog::~CalendarDialog()
{
}

QList<CalendarEvent> CalendarDialog::getAllEvents()
{
    QList<CalendarEvent> events;

    QSqlQuery query;
    query.prepare("SELECT IDENTIFIANT, NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX, ID_LOCATAIRE FROM eyk.EVENEMENTS ORDER BY DATE_DEBUT");

    if (query.exec())
    {
        while (query.next())
        {
            CalendarEvent event;
            event.identifiant = query.value("IDENTIFIANT").toString();
            event.nom = query.value("NOM").toString();
            event.type = query.value("TYPE").toString();
            event.dateDebut = query.value("DATE_DEBUT").toDateTime();
            event.dateFin = query.value("DATE_FIN").toDateTime();
            event.lieu = query.value("LIEU").toString();
            event.capacite = query.value("CAPACITE").toString();
            event.prix = query.value("PRIX").toString();
            event.idLocataire = query.value("ID_LOCATAIRE").toString();

            events.append(event);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des événements:" << query.lastError().text();
    }

    return events;
}

QList<CalendarEvent> CalendarDialog::getEventsByDate(const QDate &date)
{
    QList<CalendarEvent> events;

    QSqlQuery query;
    query.prepare("SELECT IDENTIFIANT, NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX, ID_LOCATAIRE FROM eyk.EVENEMENTS "
                  "WHERE :date BETWEEN TRUNC(DATE_DEBUT) AND TRUNC(DATE_FIN) ORDER BY DATE_DEBUT");
    query.bindValue(":date", date);

    if (query.exec())
    {
        while (query.next())
        {
            CalendarEvent event;
            event.identifiant = query.value("IDENTIFIANT").toString();
            event.nom = query.value("NOM").toString();
            event.type = query.value("TYPE").toString();
            event.dateDebut = query.value("DATE_DEBUT").toDateTime();
            event.dateFin = query.value("DATE_FIN").toDateTime();
            event.lieu = query.value("LIEU").toString();
            event.capacite = query.value("CAPACITE").toString();
            event.prix = query.value("PRIX").toString();
            event.idLocataire = query.value("ID_LOCATAIRE").toString();

            events.append(event);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des événements par date:" << query.lastError().text();
    }

    return events;
}

void CalendarDialog::highlightEventDates()
{
    // Réinitialiser les formats de date
    calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    QList<CalendarEvent> events = getAllEvents();
    QTextCharFormat eventFormat;
    eventFormat.setForeground(QBrush(QColor(0, 120, 215))); // Bleu Microsoft
    eventFormat.setFontWeight(QFont::Bold);

    QTextCharFormat todayFormat;
    todayFormat.setForeground(QBrush(Qt::white));
    todayFormat.setBackground(QBrush(QColor(0, 120, 215))); // Bleu Microsoft
    todayFormat.setFontWeight(QFont::Bold);

    // Mettre en évidence aujourd'hui
    calendarWidget->setDateTextFormat(QDate::currentDate(), todayFormat);

    // Mettre en évidence les dates avec des événements
    for (const CalendarEvent &event : events)
    {
        QDate currentDate = event.dateDebut.date();
        while (currentDate <= event.dateFin.date())
        {
            // Ne pas écraser le format pour aujourd'hui
            if (currentDate != QDate::currentDate())
            {
                calendarWidget->setDateTextFormat(currentDate, eventFormat);
            }
            currentDate = currentDate.addDays(1);
        }
    }
}

void CalendarDialog::refreshCalendar()
{
    highlightEventDates();
    onCalendarClicked(calendarWidget->selectedDate());
}

void CalendarDialog::onCalendarClicked(const QDate &date)
{
    QList<CalendarEvent> events = getEventsByDate(date);

    eventsModel->setRowCount(0); // Effacer le modèle

    if (events.isEmpty())
    {
        QLabel *noEventsLabel = new QLabel("Aucun événement pour cette date.");
        noEventsLabel->setAlignment(Qt::AlignCenter);
        noEventsLabel->setStyleSheet("color: grey; font-style: italic;");
    }
    else
    {
        for (const CalendarEvent &event : events)
        {
            QList<QStandardItem *> row;

            row << new QStandardItem(event.identifiant);
            row << new QStandardItem(event.nom);
            row << new QStandardItem(event.type);
            row << new QStandardItem(event.dateDebut.toString("dd/MM/yyyy HH:mm"));
            row << new QStandardItem(event.dateFin.toString("dd/MM/yyyy HH:mm"));
            row << new QStandardItem(event.lieu);
            row << new QStandardItem(event.capacite);
            row << new QStandardItem(event.prix);

            eventsModel->appendRow(row);
        }

        // Ajuster les colonnes
        eventsTableView->resizeColumnsToContents();
    }
}

void CalendarDialog::onAddEventClicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter un événement");

    CalendarEvent newEvent;
    newEvent.dateDebut.setDate(calendarWidget->selectedDate());
    newEvent.dateFin.setDate(calendarWidget->selectedDate());

    setupEventDialog(&dialog, &newEvent);

    if (dialog.exec() == QDialog::Accepted)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO eyk.EVENEMENTS (IDENTIFIANT, NOM, TYPE, DATE_DEBUT, DATE_FIN, LIEU, CAPACITE, PRIX, ID_LOCATAIRE) "
                      "VALUES (:id, :nom, :type, :dateDebut, :dateFin, :lieu, :capacite, :prix, :idLocataire)");

        query.bindValue(":id", newEvent.identifiant);
        query.bindValue(":nom", newEvent.nom);
        query.bindValue(":type", newEvent.type);
        query.bindValue(":dateDebut", newEvent.dateDebut);
        query.bindValue(":dateFin", newEvent.dateFin);
        query.bindValue(":lieu", newEvent.lieu);
        query.bindValue(":capacite", newEvent.capacite.toInt());
        query.bindValue(":prix", newEvent.prix.toDouble());
        query.bindValue(":idLocataire", newEvent.idLocataire);

        if (query.exec())
        {
            QMessageBox::information(this, "Succès", "L'événement a été ajouté avec succès.");
            refreshCalendar();
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Impossible d'ajouter l'événement: " + query.lastError().text());
        }
    }
}

void CalendarDialog::onModifyEventClicked()
{
    QModelIndex currentIndex = eventsTableView->currentIndex();
    if (!currentIndex.isValid())
    {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un événement à modifier.");
        return;
    }

    onEventDoubleClicked(currentIndex);
}

void CalendarDialog::onDeleteEventClicked()
{
    QModelIndex currentIndex = eventsTableView->currentIndex();
    if (!currentIndex.isValid())
    {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un événement à supprimer.");
        return;
    }

    QString identifiant = eventsModel->item(currentIndex.row(), 0)->text();
    QString nom = eventsModel->item(currentIndex.row(), 1)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation",
        "Voulez-vous vraiment supprimer l'événement '" + nom + "' ?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM eyk.EVENEMENTS WHERE IDENTIFIANT = :id");
        query.bindValue(":id", identifiant);

        if (query.exec())
        {
            QMessageBox::information(this, "Succès", "L'événement a été supprimé avec succès.");
            refreshCalendar();
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'événement: " + query.lastError().text());
        }
    }
}

void CalendarDialog::onEventDoubleClicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QDialog dialog(this);
    dialog.setWindowTitle("Modifier un événement");

    // Récupérer les données de l'événement
    QString identifiant = eventsModel->item(index.row(), 0)->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM eyk.EVENEMENTS WHERE IDENTIFIANT = :id");
    query.bindValue(":id", identifiant);

    CalendarEvent event;
    if (query.exec() && query.next())
    {
        event.identifiant = query.value("IDENTIFIANT").toString();
        event.nom = query.value("NOM").toString();
        event.type = query.value("TYPE").toString();
        event.dateDebut = query.value("DATE_DEBUT").toDateTime();
        event.dateFin = query.value("DATE_FIN").toDateTime();
        event.lieu = query.value("LIEU").toString();
        event.capacite = query.value("CAPACITE").toString();
        event.prix = query.value("PRIX").toString();
        event.idLocataire = query.value("ID_LOCATAIRE").toString();

        setupEventDialog(&dialog, &event);

        if (dialog.exec() == QDialog::Accepted)
        {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE eyk.EVENEMENTS SET "
                                "NOM = :nom, TYPE = :type, DATE_DEBUT = :dateDebut, DATE_FIN = :dateFin, "
                                "LIEU = :lieu, CAPACITE = :capacite, PRIX = :prix, ID_LOCATAIRE = :idLocataire "
                                "WHERE IDENTIFIANT = :id");

            updateQuery.bindValue(":id", event.identifiant);
            updateQuery.bindValue(":nom", event.nom);
            updateQuery.bindValue(":type", event.type);
            updateQuery.bindValue(":dateDebut", event.dateDebut);
            updateQuery.bindValue(":dateFin", event.dateFin);
            updateQuery.bindValue(":lieu", event.lieu);
            updateQuery.bindValue(":capacite", event.capacite.toInt());
            updateQuery.bindValue(":prix", event.prix.toDouble());
            updateQuery.bindValue(":idLocataire", event.idLocataire);

            if (updateQuery.exec())
            {
                QMessageBox::information(this, "Succès", "L'événement a été modifié avec succès.");
                refreshCalendar();
            }
            else
            {
                QMessageBox::critical(this, "Erreur", "Impossible de modifier l'événement: " + updateQuery.lastError().text());
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails de l'événement.");
    }
}

void CalendarDialog::setupEventDialog(QDialog *dialog, CalendarEvent *event)
{
    // Appliquer un style moderne au dialogue
    dialog->setMinimumSize(500, 450);
    dialog->setStyleSheet(R"(
        QDialog {
            background-color: #f5f7fa;
            font-family: 'Segoe UI', Arial, sans-serif;
        }
        QLabel {
            font-weight: bold;
            color: #2c3e50;
        }
        QLineEdit, QDateTimeEdit, QComboBox {
            border: 1px solid #bdc3c7;
            border-radius: 4px;
            padding: 8px;
            background-color: white;
            selection-background-color: #3498db;
            min-height: 25px;
        }
        QLineEdit:focus, QDateTimeEdit:focus, QComboBox:focus {
            border: 2px solid #3498db;
        }
        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
            min-width: 100px;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1c6ea4;
        }
        QPushButton[text="Cancel"], QPushButton[text="Annuler"] {
            background-color: #95a5a6;
        }
        QPushButton[text="Cancel"]:hover, QPushButton[text="Annuler"]:hover {
            background-color: #7f8c8d;
        }
        QGroupBox {
            border: 1px solid #bdc3c7;
            border-radius: 6px;
            margin-top: 10px;
            font-weight: bold;
            color: #2c3e50;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top center;
            padding: 0 10px;
            background-color: #f5f7fa;
        }
    )");

    // Création d'une mise en page avec des groupes pour mieux organiser
    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);

    // Groupe pour les informations principales
    QGroupBox *mainInfoGroup = new QGroupBox("Informations principales");
    QFormLayout *mainInfoLayout = new QFormLayout(mainInfoGroup);

    QLineEdit *idLineEdit = new QLineEdit(dialog);
    QLineEdit *nomLineEdit = new QLineEdit(dialog);
    QComboBox *typeComboBox = new QComboBox(dialog);

    // Remplir le combobox avec des types d'événements communs
    QStringList eventTypes = {"Conférence", "Concert", "Exposition", "Séminaire", "Formation", "Spectacle", "Festival", "Atelier"};
    typeComboBox->addItems(eventTypes);
    typeComboBox->setEditable(true); // Permettre d'entrer un type personnalisé

    // Groupe pour les dates
    QGroupBox *dateGroup = new QGroupBox("Période de l'événement");
    QFormLayout *dateLayout = new QFormLayout(dateGroup);

    QDateTimeEdit *dateDebutEdit = new QDateTimeEdit(dialog);
    QDateTimeEdit *dateFinEdit = new QDateTimeEdit(dialog);

    // Configuration des widgets de date/heure
    dateDebutEdit->setCalendarPopup(true);
    dateDebutEdit->setDisplayFormat("dd/MM/yyyy HH:mm");
    dateFinEdit->setCalendarPopup(true);
    dateFinEdit->setDisplayFormat("dd/MM/yyyy HH:mm");

    // Groupe pour la localisation
    QGroupBox *locationGroup = new QGroupBox("Localisation et capacité");
    QFormLayout *locationLayout = new QFormLayout(locationGroup);

    QLineEdit *lieuLineEdit = new QLineEdit(dialog);
    QLineEdit *capaciteLineEdit = new QLineEdit(dialog);
    capaciteLineEdit->setValidator(new QIntValidator(0, 999999, dialog)); // Validation numérique

    // Groupe pour les détails financiers
    QGroupBox *financeGroup = new QGroupBox("Détails financiers");
    QFormLayout *financeLayout = new QFormLayout(financeGroup);

    QLineEdit *prixLineEdit = new QLineEdit(dialog);
    prixLineEdit->setValidator(new QDoubleValidator(0, 999999.99, 2, dialog)); // Validation numérique pour prix

    // Organiser le groupe des locataires
    QGroupBox *locataireGroup = new QGroupBox("Organisateur");
    QFormLayout *locataireLayout = new QFormLayout(locataireGroup);

    // Utilisez un QComboBox pour sélectionner les locataires à partir de la base de données
    QComboBox *locataireComboBox = new QComboBox(dialog);
    fillLocatairesComboBox(locataireComboBox);

    // Ajouter des tooltips pour l'aide
    idLineEdit->setToolTip("Identifiant unique de l'événement");
    nomLineEdit->setToolTip("Nom ou titre de l'événement");
    typeComboBox->setToolTip("Type ou catégorie de l'événement");
    dateDebutEdit->setToolTip("Date et heure de début de l'événement");
    dateFinEdit->setToolTip("Date et heure de fin de l'événement");
    lieuLineEdit->setToolTip("Lieu où se déroule l'événement");
    capaciteLineEdit->setToolTip("Nombre maximum de participants");
    prixLineEdit->setToolTip("Prix d'entrée ou de participation (en €)");
    locataireComboBox->setToolTip("Organisateur ou responsable de l'événement");

    // Placer les champs dans les layouts
    mainInfoLayout->addRow("Identifiant:", idLineEdit);
    mainInfoLayout->addRow("Nom:", nomLineEdit);
    mainInfoLayout->addRow("Type:", typeComboBox);

    dateLayout->addRow("Date de début:", dateDebutEdit);
    dateLayout->addRow("Date de fin:", dateFinEdit);

    locationLayout->addRow("Lieu:", lieuLineEdit);
    locationLayout->addRow("Capacité:", capaciteLineEdit);

    financeLayout->addRow("Prix:", prixLineEdit);

    locataireLayout->addRow("Organisateur:", locataireComboBox);

    // Ajouter les groupes au layout principal
    mainLayout->addWidget(mainInfoGroup);
    mainLayout->addWidget(dateGroup);
    mainLayout->addWidget(locationGroup);
    mainLayout->addWidget(financeGroup);
    mainLayout->addWidget(locataireGroup);

    // Boutons de confirmation
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Enregistrer");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");

    connect(buttonBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);

    mainLayout->addWidget(buttonBox);

    // Si nous avons un événement existant, remplir les champs
    if (event)
    {
        idLineEdit->setText(event->identifiant);
        nomLineEdit->setText(event->nom);

        // Rechercher le type dans le combobox ou l'ajouter s'il n'existe pas
        int typeIndex = typeComboBox->findText(event->type);
        if (typeIndex >= 0)
        {
            typeComboBox->setCurrentIndex(typeIndex);
        }
        else
        {
            typeComboBox->addItem(event->type);
            typeComboBox->setCurrentText(event->type);
        }

        dateDebutEdit->setDateTime(event->dateDebut);
        dateFinEdit->setDateTime(event->dateFin);
        lieuLineEdit->setText(event->lieu);
        capaciteLineEdit->setText(event->capacite);
        prixLineEdit->setText(event->prix);

        // Rechercher l'ID du locataire dans le combobox
        int locataireIndex = locataireComboBox->findData(event->idLocataire);
        if (locataireIndex >= 0)
        {
            locataireComboBox->setCurrentIndex(locataireIndex);
        }

        // Si nous modifions un événement existant, l'ID n'est pas modifiable
        idLineEdit->setReadOnly(!event->identifiant.isEmpty());
        if (idLineEdit->isReadOnly())
        {
            idLineEdit->setStyleSheet(idLineEdit->styleSheet() + "QLineEdit { background-color: #f0f0f0; }");
        }
    }

    // Ajouter des validations supplémentaires
    connect(dateDebutEdit, &QDateTimeEdit::dateTimeChanged, [=]()
            {
                if (dateDebutEdit->dateTime() > dateFinEdit->dateTime()) {
                    dateFinEdit->setDateTime(dateDebutEdit->dateTime().addSecs(3600)); // Ajoute 1 heure
                } });

    // Connecter le signal accepted pour valider et sauver les données
    connect(dialog, &QDialog::accepted, [=]()
            {
                event->identifiant = idLineEdit->text();
                event->nom = nomLineEdit->text();
                event->type = typeComboBox->currentText();
                event->dateDebut = dateDebutEdit->dateTime();
                event->dateFin = dateFinEdit->dateTime();
                event->lieu = lieuLineEdit->text();
                event->capacite = capaciteLineEdit->text();
                event->prix = prixLineEdit->text();
                event->idLocataire = locataireComboBox->currentData().toString(); });
}

// Méthode auxiliaire pour remplir le combobox des locataires
void CalendarDialog::fillLocatairesComboBox(QComboBox *comboBox)
{
    comboBox->clear();

    QSqlQuery query;
    query.prepare("SELECT ID_LOCATAIRE, NOM FROM eyk.LOCATAIRES ORDER BY NOM");

    if (query.exec())
    {
        while (query.next())
        {
            QString id = query.value("ID_LOCATAIRE").toString();
            QString nom = query.value("NOM").toString();
            comboBox->addItem(nom, id);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la récupération des locataires:" << query.lastError().text();
    }

    // Ajouter une option "Aucun" si nécessaire
    if (comboBox->count() == 0)
    {
        comboBox->addItem("Aucun locataire disponible", "");
    }
}
