#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "src/const.h"
#include "calculation/calculationmanager.h"
#include "network/networkmanager.h"

#define TERMINATED_EXPECTED_TOTAL 1

/**
 * @brief Ce manager gère fait office de facade pour tous les autres managers.
 *      Son rôle est de garantir la cohérence globale de l'application.
 */
class ApplicationManager : public QObject
{
    Q_OBJECT
public:
    ~ApplicationManager(){}
    static ApplicationManager & GetInstance() { return _instance; }

    void Init();

public slots:
    /**
     * @brief Ce slot reçoit les demandes de consultation de l'état du serveur
     */
    void SLOT_STATE();
    /**
     * @brief Ce slot reçoit les demandes d'exécution de calculs
     * @param calculationOrder
     *      Objet contenant les spécification du calcul à effectuer
     */
    void SLOT_EXEC(QByteArray calculationOrderJSON);
    /**
     * @brief Ce slot reçoit les demandes de status des calculs en cours
     */
    void SLOT_STATUS();
    /**
     * @brief Ce slot reçoit les demandes de résultats pour un calcul en particulier
     * @param id
     *      Identifiant du calcul dont on doit retourner le résultat
     */
    void SLOT_RESULT(QUuid id, QString filename);
    /**
     * @brief Ce slot reçoit les demandes d'annulation pour un calcul en particulier
     * @param id
     *      Identifiant du calcul que l'on doit annuler
     */
    void SLOT_CANCEL(QUuid id);
    /**
     * @brief Ce slot reçoit les demandes d'arrêt du serveur
     */
    void SLOT_SHUTDOWN();
    /**
     * @brief Ce slot reçoit les notifications d'arrêt des composants
     */
    void SLOT_TERMINATED();

signals:
    /**
     * @brief Ce signal est émis en réponse aux demandes reçues par les slots.
     * @param command
     *      Commande à l'origine de l'émission de cette réponse
     * @param ok
     *      Statut de la réponse, 'true' si la demande à pu être traitée correctement
     * @param message
     *      Message détaillant la réponse
     */
    void SIG_RESPONSE(Command command, bool ok, QString message);
    /**
     * @brief Ce signal est émis une fois que tous les composants se sont arrêtés correctement.
     */
    void SIG_TERMINATE();

private:
    ApplicationManager();
    Q_DISABLE_COPY(ApplicationManager)
    static ApplicationManager _instance;

    int _terminated_ctr;
};

#endif // APPLICATIONMANAGER_H
